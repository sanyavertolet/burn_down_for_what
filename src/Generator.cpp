/**
 * @author sanyavertolet
 */

#include <string>
#include <fstream>
#include <vector>

#include "Randomizer/Randomizer.h"

void generate_csv(const std::string& filename, int n_proc, int n_jobs, int from, int to, const std::string& prefix = "csv/") {
    std::ofstream out(prefix + filename);
    out << n_proc << "," << n_jobs << ",";
    for (int i = 0; i < n_jobs; ++i) {
        out << Randomizer::get_randomizer().randomize(from, to);
        if (i + 1 < n_jobs) {
            out << ",";
        }
    }
    out.close();
}

int main() {
    constexpr int from = 1;
    constexpr int to = 100;

    constexpr int n_proc_min = 2;
    constexpr int n_proc_step = 2;
    constexpr int n_proc_max = 20;

    constexpr int n_jobs_min = 100;
    constexpr int n_jobs_step = 100;
    constexpr int n_jobs_max = 2000;

    std::string dirname = "csv";

    if (!std::filesystem::exists(dirname)) {
        std::filesystem::create_directory(dirname);
    }

    for (int n_proc = n_proc_min; n_proc <= n_proc_max; n_proc += n_proc_step) {
        for (int n_jobs = n_jobs_min; n_jobs <= n_jobs_max; n_jobs += n_jobs_step) {
            std::string filename = std::to_string(n_proc) + "_" + std::to_string(n_jobs) + ".csv";
            generate_csv(filename, n_proc, n_jobs, from, to, dirname + "/");
        }
    }
}
