/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H
#define BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H

#include <utility>

#include "../AbstractSASolver/AbstractSASolver.h"
#include "../../Solution/ScheduleSASolution/ScheduleSASolution.h"
#include "../../Mutator/ScheduleMutator/ScheduleMutator.h"

template<class TemperatureDecreaser>
class ScheduleSASolver: public AbstractSASolver<TemperatureDecreaser, class ScheduleSASolution, class ScheduleMutator> {
public:
    using quality_type = typename AbstractSASolver<TemperatureDecreaser, ScheduleSASolution, ScheduleMutator>::quality_type;

    explicit ScheduleSASolver(int proc, int tasks, std::vector<int> durs): job_durations(std::move(durs)), n_proc(proc), n_jobs(tasks),
    AbstractSASolver<TemperatureDecreaser, class ScheduleSASolution, class ScheduleMutator>(proc, tasks){ }

    void set_starting_solution() override {
        this->current_solution = ScheduleSASolution(n_proc, n_jobs);
        this->best_solution = this->current_solution;
    }

    bool stop_criterion() override {
        return this->iteration >= 100;
    }

    quality_type quality_function(const ScheduleSASolution& solution) override {
        quality_type t_max = 0;
        quality_type t_min = LONG_LONG_MAX;
        for(const auto& processor_queue: solution.data) {
            quality_type start_time = 0;
            for(auto job: processor_queue) {
                start_time += this->job_durations[job];
            }
            if (t_max < start_time) {
                t_max = start_time;
            }
            if (t_min > start_time) {
                t_min = start_time;
            }
        }
        return t_max - t_min;
    }
private:
    std::vector<int> job_durations;
    int n_proc;
    int n_jobs;
};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H
