#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <type_traits>

#include "src/SASolver/ScheduleSASolver/ScheduleSASolver.h"
#include "src/TemperatureDecreaser/BoltzmannTemperatureDecreaser/BoltzmannTemperatureDecreaser.h"
#include "src/TemperatureDecreaser/CauchyTemperatureDecreaser/CauchyTemperatureDecreaser.h"
#include "src/TemperatureDecreaser/MixedTemperatureDecreaser/MixedTemperatureDecreaser.h"
#include "src/Timer.h"

#define ITERATIONS_FOR_TEST 5

void read_from_csv(const std::string& filename, int& n_proc, int& n_jobs, std::vector<int>& job_durations);
std::vector<int> get_possible_n_proc();
std::vector<int> get_possible_n_jobs();


template<typename TemperatureDecreaser>
void read_run_and_save_results(const std::string& filename, std::ofstream& out) {
    static_assert(std::is_base_of<AbstractTemperatureDecreaser, TemperatureDecreaser>::value);
    std::vector<int> job_durations;
    int n_proc;
    int n_jobs;
    read_from_csv(filename, n_proc, n_jobs, job_durations);
    int sum_quality = 0;
    long long duration = 0;
    for (int i = 0; i < ITERATIONS_FOR_TEST; ++i) {
        Timer timer;
        ScheduleSASolver<TemperatureDecreaser> solver(n_proc, n_jobs, job_durations);
        timer.tick();
        auto [best_solution, quality] = solver.solve();
        timer.tock();
        sum_quality += quality;
        duration += timer.template duration().count();
    }
    out << n_proc << "," << n_jobs << "," << static_cast<long double>(duration) / (long double)(5.0) << "," << sum_quality / 5.0 << std::endl;
}

int main() {
    auto possible_n_proc = get_possible_n_proc();
    auto possible_n_jobs = get_possible_n_jobs();

    std::string dirname = "csv";

    std::string boltzmann_report_file_name = "boltzmann.csv";
    std::string cauchy_report_file_name = "cauchy.csv";
    std::string mixed_report_file_name = "mixed.csv";

    std::ofstream boltzmann(boltzmann_report_file_name);
    std::ofstream cauchy(cauchy_report_file_name);
    std::ofstream mixed(mixed_report_file_name);

    for (const auto& filename : std::filesystem::directory_iterator(dirname)) {
        read_run_and_save_results<BoltzmannTemperatureDecreaser>(filename.path().string(), boltzmann);
    }

    boltzmann.close();

    for (const auto& filename : std::filesystem::directory_iterator(dirname)) {
        read_run_and_save_results<CauchyTemperatureDecreaser>(filename.path().string(), cauchy);
    }

    cauchy.close();

    for (const auto& filename : std::filesystem::directory_iterator(dirname)) {
        read_run_and_save_results<MixedTemperatureDecreaser>(filename.path().string(), mixed);
    }

    mixed.close();

    return 0;
}
