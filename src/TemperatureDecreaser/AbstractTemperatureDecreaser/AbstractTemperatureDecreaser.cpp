/**
 * @author sanyavertolet
 */

#include "AbstractTemperatureDecreaser.h"

AbstractTemperatureDecreaser::AbstractTemperatureDecreaser(): temperature(1.0), iteration(0) { }
AbstractTemperatureDecreaser::AbstractTemperatureDecreaser(temperature_type new_temperature, iteration_type new_iteration):
temperature(new_temperature), iteration(new_iteration) { }

AbstractTemperatureDecreaser::temperature_type AbstractTemperatureDecreaser::get_temperature() const {
    return temperature;
}

AbstractTemperatureDecreaser::temperature_type AbstractTemperatureDecreaser::operator()() {
    return decrease();
}
