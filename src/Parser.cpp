/**
 * @author sanyavertolet
 */

#include <string>
#include <fstream>
#include <vector>

void read_from_csv(const std::string& filename, int& n_proc, int& n_jobs, std::vector<int>& job_durations) {
    std::ifstream input(filename);
    char ch;
    input >> n_proc;
    input >> ch;
    input >> n_jobs;
    input >> ch;

    for (int i = 0; i < n_jobs; ++i) {
        int duration = 0;
        input >> duration;
        job_durations.push_back(duration);
        if (i + 1 < n_jobs) {
            input >> ch;
        }
    }
    input.close();
}

std::vector<int> get_possible_n_proc() {
    std::vector<int> possible_n_proc;
    constexpr int n_proc_min = 2;
    constexpr int n_proc_step = 2;
    constexpr int n_proc_max = 20;

    for (int n_proc = n_proc_min; n_proc <= n_proc_max; n_proc += n_proc_step) {
        possible_n_proc.push_back(n_proc);
    }
    return possible_n_proc;
}

std::vector<int> get_possible_n_jobs() {
    std::vector<int> possible_n_jobs;

    constexpr int n_jobs_min = 100;
    constexpr int n_jobs_step = 100;
    constexpr int n_jobs_max = 2000;
    for (int n_jobs = n_jobs_min; n_jobs <= n_jobs_max; n_jobs += n_jobs_step) {
        possible_n_jobs.push_back(n_jobs);
    }
    return possible_n_jobs;
}
