/**
 * Boltzmann temperature decreaser class declaration.
 *
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_BOLTZMANNTEMPERATUREDECREASER_H
#define BURN_DOWN_FOR_WHAT_BOLTZMANNTEMPERATUREDECREASER_H

#include <cmath>

#include "../AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h"

class BoltzmannTemperatureDecreaser: public AbstractTemperatureDecreaser {
    BoltzmannTemperatureDecreaser();
    explicit BoltzmannTemperatureDecreaser(temperature_type new_temperature, iteration_type iteration);
    temperature_type decrease() override;
};


#endif //BURN_DOWN_FOR_WHAT_BOLTZMANNTEMPERATUREDECREASER_H