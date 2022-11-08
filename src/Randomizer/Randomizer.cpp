/**
 * @author sanyavertolet
 */

#include "Randomizer.h"

Randomizer::Randomizer(): device(),
seed(device() ^ ((std::mt19937::result_type) std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
        ).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count())), generator(seed) { }

double Randomizer::randomize(double from, double to) {
    return randomize(std::uniform_real_distribution<>(from, to));
}

int Randomizer::randomize(int from, int to) {
    return std::floor(std::abs(randomize(1.0 * from, 1.0 * to)));
}

double Randomizer::randomize(std::uniform_real_distribution<> dis) {
    return dis(generator);
}

Randomizer& Randomizer::get_randomizer() {
    static Randomizer randomizer;
    return randomizer;
}
