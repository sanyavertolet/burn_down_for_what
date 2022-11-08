/**
 * @author sanyavertolet
 */

#include <string>
#include <iostream>

#include "ScheduleMutator.h"

#include "../../Randomizer/Randomizer.h"

ScheduleSASolution ScheduleMutator::mutate(ScheduleSASolution solution) {
    int n_proc = static_cast<int>(solution.data.size());
    int from;
    do {
        from = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, n_proc)));
    } while(solution.data[from].empty());

    int to;
    do {
        to = std::floor(std::abs(Randomizer::get_randomizer().randomize(0, n_proc)));
    } while(from == to);

    int i = Randomizer::get_randomizer().randomize(0, static_cast<int>(solution.data[from].size()));
    int j = Randomizer::get_randomizer().randomize(0, static_cast<int>(solution.data[to].size()));

    if (solution.data[to].empty()) {
        solution.data[to].push_back(solution.data[from][i]);
    } else {
        solution.data[to].insert(solution.data[to].begin() + j, solution.data[from][i]);
    }
    solution.data[from].erase(solution.data[from].begin() + i);
    return solution;
}
