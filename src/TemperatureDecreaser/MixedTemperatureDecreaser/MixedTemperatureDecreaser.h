/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_MIXEDTEMPERATUREDECREASER_H
#define BURN_DOWN_FOR_WHAT_MIXEDTEMPERATUREDECREASER_H

#include <cmath>

#include "../AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h"

class MixedTemperatureDecreaser: public AbstractTemperatureDecreaser {
public:
    MixedTemperatureDecreaser();
    explicit MixedTemperatureDecreaser(temperature_type new_temperature, iteration_type new_iteration = 0);

    temperature_type decrease() override;
};


#endif //BURN_DOWN_FOR_WHAT_MIXEDTEMPERATUREDECREASER_H
