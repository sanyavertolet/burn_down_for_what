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
    AbstractSASolver<TemperatureDecreaser, class ScheduleSASolution, class ScheduleMutator>(){ }

    void set_starting_solution() override {
        this->current_solution;
        this->best_solution = this->current_solution;
    }

    bool stop_criterion() override {
        return this->iteration >= 100;
    }

    quality_type quality_function(const ScheduleSASolution& solution) override {
        quality_type sum = 0;
        for(const auto& processor_queue: solution.data) {
            quality_type start_time = 0;
            for(auto job: processor_queue) {
                start_time += start_time + this->job_durations[job];
                sum += start_time;
            }
        }
        return sum;
    }
private:
    std::vector<int> job_durations;
    int n_proc;
    int n_jobs;
};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H
