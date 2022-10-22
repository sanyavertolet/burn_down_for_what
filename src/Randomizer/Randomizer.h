/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_RANDOMIZER_H
#define BURN_DOWN_FOR_WHAT_RANDOMIZER_H

#include <random>
#include <chrono>

class Randomizer {
public:
    Randomizer(Randomizer const&) = delete;
    Randomizer& operator=(Randomizer const&) = delete;

    double randomize() {
        return dis(generator);
    }

    static Randomizer& get_randomizer();
private:
    Randomizer* randomizer;
    std::random_device device;
    std::mt19937::result_type seed;
    std::mt19937 generator;
    std::uniform_real_distribution<> dis;
    Randomizer();
};


#endif //BURN_DOWN_FOR_WHAT_RANDOMIZER_H
