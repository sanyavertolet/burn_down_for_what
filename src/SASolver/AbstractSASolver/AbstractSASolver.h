/**
 * @author sanyavertolet
*/

#ifndef BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H
#define BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H

#include <memory>
#include <utility>
#include <vector>
#include <type_traits>
#include <unordered_set>

#include "../../Randomizer/Randomizer.h"
#include "../../TemperatureDecreaser/AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h"
#include "../../Solution/AbstractSASolution/AbstractSASolution.h"
#include "../../Mutator/AbstractMutator/AbstractMutator.h"

template<class TemperatureDecreaser, class Solution, class Mutator>
class AbstractSASolver {
    static_assert(std::is_base_of<AbstractTemperatureDecreaser, TemperatureDecreaser>::value,
            "AbstractTemperatureDecreaser should be inherited by TemperatureDecreaser.");
    static_assert(std::is_base_of<AbstractSASolution, Solution>::value,
                  "AbstractSASolution should be inherited by Solution.");
    static_assert(std::is_base_of<AbstractMutator<Solution>, Mutator>::value,
                  "AbstractSASolution should be inherited by Solution.");

public:
    using integer_type = int;
    using probability_type = double;

    using quality_type = int;

    explicit AbstractSASolver(): decreaser(TemperatureDecreaser()), mutator(Mutator()), iteration(),
    best_solution(), current_solution(best_solution) { }

    Solution solve() {
        set_starting_solution();
        set_starting_temperature();
        for (iteration = 0; stop_criterion(); ++iteration) {
            decreaser->decrease();
            for (integer_type index = 0; index < 10; ++index) {
                Solution new_solution = get_new_solution();
                quality_type quality_difference = quality_function(new_solution) - quality_function(current_solution);

                if (quality_difference < 0) {
                    current_solution = new_solution;
                    if (quality_function(current_solution) < quality_function(best_solution)) {
                        best_solution = current_solution;
                        iteration = 0;
                    }
                } else {
                    if (should_visit(quality_difference)) {
                        current_solution = new_solution;
                    }
                }
            }
        }
        return best_solution;
    }

    virtual ~AbstractSASolver() = default;
protected:
    bool should_visit(quality_type quality_difference) {
        return get_random_number() <= probability(quality_difference);
    }

    probability_type probability(quality_type quality_difference) {
        if (quality_difference <= 0) {
            return 1;
        } else {
            return static_cast<double>(exp(-quality_difference / decreaser->get_temperature()));
        }
    }

    virtual void set_starting_solution() = 0;

    virtual void set_starting_temperature() {
        decreaser = TemperatureDecreaser();
    }

    virtual bool stop_criterion() = 0;
    virtual quality_type quality_function(const Solution& solution) = 0;

    integer_type iteration;

    Solution best_solution;
    Solution current_solution;

    Mutator mutator;
    TemperatureDecreaser decreaser;
private:
    static probability_type get_random_number() {
        return Randomizer::get_randomizer().randomize();
    }

    Solution get_new_solution() {
        return mutator.mutate(current_solution);
    }
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H
