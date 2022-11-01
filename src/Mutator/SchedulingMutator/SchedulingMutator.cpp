/**
 * @author sanyavertolet
 */

#include "SchedulingMutator.h"

#include "../../Randomizer/Randomizer.h"

SchedulingSASolution SchedulingMutator::mutate(SchedulingSASolution solution) {
    int n_proc = static_cast<int>(solution.data.size());
    int from;
    do {
        from = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, n_proc)));
    } while(solution.data[from].empty());

    int to;
    do {
        to = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, n_proc)));
    } while(from == to);

    int i = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, static_cast<double>(solution.data[from].size()))));
    int j = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, static_cast<double>(solution.data[to].size()))));

    std::swap(solution.data[from][i], solution.data[to][j]);

    return solution;
}
