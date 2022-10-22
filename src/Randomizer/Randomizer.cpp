/**
 * @author sanyavertolet
 */

#include "Randomizer.h"

Randomizer::Randomizer(): device(), randomizer(),
seed(device() ^ ((std::mt19937::result_type) std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
        ).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count())), generator(seed), dis(0.0, 1.0) { }

Randomizer& Randomizer::get_randomizer() {
    static Randomizer randomizer;
    return randomizer;
}
