/**
 * Boltzmann temperature decreaser class implementation.
 *
 * @author sanyavertolet
 */

#include "BoltzmannTemperatureDecreaser.h"

BoltzmannTemperatureDecreaser::BoltzmannTemperatureDecreaser(): AbstractTemperatureDecreaser() { }

BoltzmannTemperatureDecreaser::BoltzmannTemperatureDecreaser(
        BoltzmannTemperatureDecreaser::temperature_type new_temperature,
        BoltzmannTemperatureDecreaser::iteration_type iteration) : AbstractTemperatureDecreaser(new_temperature,
                                                                                               iteration) { }

BoltzmannTemperatureDecreaser::temperature_type BoltzmannTemperatureDecreaser::decrease(iteration_type iteration) {
    return (temperature = temperature / log(iteration++ + 1));
}
