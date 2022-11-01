/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_CAUCHYTEMPERATUREDECREASER_H
#define BURN_DOWN_FOR_WHAT_CAUCHYTEMPERATUREDECREASER_H

#include "../AbstractTemperatureDecreaser/AbstractTemperatureDecreaser.h"

class CauchyTemperatureDecreaser : public AbstractTemperatureDecreaser {
public:
    CauchyTemperatureDecreaser();
    explicit CauchyTemperatureDecreaser(temperature_type new_temperature, iteration_type new_iteration = 0);

    temperature_type decrease() override;
};


#endif //BURN_DOWN_FOR_WHAT_CAUCHYTEMPERATUREDECREASER_H
