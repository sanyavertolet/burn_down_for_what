/**
 * @author sanyavertolet
 */

#include "CauchyTemperatureDecreaser.h"

CauchyTemperatureDecreaser::CauchyTemperatureDecreaser(): AbstractTemperatureDecreaser() { }

CauchyTemperatureDecreaser::CauchyTemperatureDecreaser(CauchyTemperatureDecreaser::temperature_type new_temperature,
                                                       CauchyTemperatureDecreaser::iteration_type new_iteration)
        : AbstractTemperatureDecreaser(new_temperature, new_iteration) { }

CauchyTemperatureDecreaser::temperature_type CauchyTemperatureDecreaser::decrease(iteration_type iteration) {
    return (temperature = temperature / (iteration++ + 1));
}
