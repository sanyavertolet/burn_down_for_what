/**
 * @author sanyavertolet
*/

#ifndef BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H
#define BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H

#include <memory>
#include <vector>
#include <unordered_set>

#include "../../Randomizer/Randomizer.h"
#include "../../TemperatureDecreaser/AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h"

class AbstractSASolver {
public:
    using integer_type = int;
    using probability_type = double;
    using solution_type = int;

    using quality_type = long double;

    AbstractSASolver(integer_type proc_num, std::unique_ptr<AbstractTemperatureDecreaser>& dec);

    solution_type solve();

    bool should_visit(quality_type quality_difference);

    probability_type probability(AbstractSASolver::quality_type quality_difference);

    virtual void set_starting_solution() = 0;

    virtual void set_starting_temperature() = 0;

    virtual solution_type get_new_solution() = 0;

    virtual bool stop_criterion() = 0;

    virtual void set_best_solution(solution_type new_best_solution) = 0;

protected:
    integer_type iteration;
    integer_type number_or_processors;
    std::vector<integer_type> job_duration;
    virtual quality_type quality_function(solution_type solution) = 0;

    std::unordered_set<solution_type> solutions;

    solution_type best_solution;
    solution_type current_solution;

    std::unique_ptr<AbstractTemperatureDecreaser> decreaser;

private:
    static probability_type get_random_number();
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTSASOLVER_H
