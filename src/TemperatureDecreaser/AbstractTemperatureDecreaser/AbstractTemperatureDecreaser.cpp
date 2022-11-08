/**
 * @author sanyavertolet
 */

#include "AbstractTemperatureDecreaser.h"

AbstractTemperatureDecreaser::AbstractTemperatureDecreaser(): temperature(10.0) { }
AbstractTemperatureDecreaser::AbstractTemperatureDecreaser(temperature_type new_temperature, iteration_type new_iteration):
temperature(new_temperature) { }

AbstractTemperatureDecreaser::temperature_type AbstractTemperatureDecreaser::get_temperature() const {
    return temperature;
}

AbstractTemperatureDecreaser::temperature_type AbstractTemperatureDecreaser::operator()(iteration_type iteration) {
    return decrease(iteration);
}
