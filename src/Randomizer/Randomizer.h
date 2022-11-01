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
    double randomize(double from = 0.0, double to = 1.0);
    double randomize(std::uniform_real_distribution<> dis);
    static Randomizer& get_randomizer();
private:
    Randomizer();
    std::random_device device;
    std::mt19937::result_type seed;
    std::mt19937 generator;
};


#endif //BURN_DOWN_FOR_WHAT_RANDOMIZER_H
