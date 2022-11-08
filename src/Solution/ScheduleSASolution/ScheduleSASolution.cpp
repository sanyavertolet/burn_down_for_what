/**
 * @author sanyavertolet
 */

#include "ScheduleSASolution.h"

#include <utility>

ScheduleSASolution::ScheduleSASolution(int n_proc, int n_jobs): AbstractSASolution(), data() {
    int job_counter = 0;
    int jobs_per_processor = n_jobs/n_proc;
    for (int i = 0; i < n_proc; ++i) {
        data.push_back({});
        for (int j = 0; j < jobs_per_processor; ++j) {
            data[i].push_back(job_counter++);
        }
    }
    for (int i = 0; i <= n_jobs - job_counter; ++i) {
        data[0].push_back(job_counter++);
    }
}

ScheduleSASolution::operator std::string() {
    std::string result;
    for(int i = 0; i < data.size(); ++i) {
        result += std::to_string(i) + ": ";
        for(auto task : data[i]) {
            result += "<" + std::to_string(task) + ">";
        }
        result += "\n";
    }
    return result;
}

