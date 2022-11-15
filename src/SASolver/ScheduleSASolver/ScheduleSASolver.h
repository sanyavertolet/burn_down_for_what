/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H
#define BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H

#include <utility>
#include <thread>
#include <mutex>
#include <cassert>

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


std::mutex mutex;
template<class TemperatureDecreaser>
void solve_wrapper(ScheduleSASolver<TemperatureDecreaser> solver, ScheduleSASolution &best_solution, long long &best_quality) {
    auto [solution, quality] = solver.solve();
    mutex.lock();
    if (best_quality > quality) {
        best_solution = solution;
        best_quality = quality;
    }
    mutex.unlock();
}

template<class TemperatureDecreaser>
std::pair<ScheduleSASolution, long long> multiprocess_runner(int n_proc, int n_jobs, std::vector<int> durations, int n_threads) {
    assert(n_threads <= std::thread::hardware_concurrency() && "Too many threads requested.");
    using Solver = ScheduleSASolver<TemperatureDecreaser>;
    std::vector<Solver> solvers;
    std::vector<std::thread> thread_pull;

    ScheduleSASolution best_solution(n_proc, n_jobs);
    long long best_quality = LONG_LONG_MAX;

    for(int i = 0; i < n_threads; ++i) {
        solvers.push_back(Solver(n_proc, n_jobs, durations));
        thread_pull.push_back(
                std::thread(solve_wrapper<TemperatureDecreaser>, solvers.back(), std::ref(best_solution), std::ref(best_quality))
                );
    }

    for(auto &thread : thread_pull) {
        thread.join();
    }

    return { best_solution, best_quality };
}

#endif //BURN_DOWN_FOR_WHAT_SCHEDULESASOLVER_H
