/**
 * @author sanyavertolet
 */

#include "AbstractSASolver.h"

AbstractSASolver::AbstractSASolver(integer_type proc_num, std::unique_ptr<AbstractTemperatureDecreaser>& dec):
decreaser(std::move(dec)), iteration(), number_or_processors(proc_num), best_solution(), current_solution() { }

AbstractSASolver::solution_type AbstractSASolver::solve() {
    set_starting_solution();
    set_starting_temperature();
    while (!solutions.empty()) {
        for (iteration = 0; stop_criterion(); ++iteration) {
            if (quality_function(current_solution) < quality_function(best_solution)) {
                best_solution = current_solution;
            }
            solution_type new_solution = get_new_solution();
            quality_type quality_difference = quality_function(new_solution) - quality_function(current_solution);
            if (should_visit(quality_difference)) {
                current_solution = new_solution;
            }
        }
        decreaser->decrease();
    }
    return best_solution;
}

bool AbstractSASolver::should_visit(quality_type quality_difference) {
    return get_random_number() <= probability(quality_difference);
}

AbstractSASolver::probability_type AbstractSASolver::get_random_number() {
    return Randomizer::get_randomizer().randomize();
}

AbstractSASolver::probability_type AbstractSASolver::probability(AbstractSASolver::quality_type quality_difference) {
    if (quality_difference <= 0) {
        return 1;
    } else {
        return static_cast<double>(exp(-quality_difference / decreaser->get_temperature()));
    }
}
