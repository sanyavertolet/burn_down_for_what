/**
 * @author sanyavertolet
 */

#include "MixedTemperatureDecreaser.h"

MixedTemperatureDecreaser::MixedTemperatureDecreaser(): AbstractTemperatureDecreaser() { }

MixedTemperatureDecreaser::MixedTemperatureDecreaser(MixedTemperatureDecreaser::temperature_type new_temperature,
                                                     MixedTemperatureDecreaser::iteration_type new_iteration)
        : AbstractTemperatureDecreaser(new_temperature, new_iteration) { }

MixedTemperatureDecreaser::temperature_type MixedTemperatureDecreaser::decrease(iteration_type iteration) {
    temperature = log (iteration + 1) / (iteration + 1) * temperature;
    ++iteration;
    return temperature;
}
