/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_ABSTRACTTEMPERATUREDECREASER_H
#define BURN_DOWN_FOR_WHAT_ABSTRACTTEMPERATUREDECREASER_H


class AbstractTemperatureDecreaser {
public:
    using temperature_type = long double;
    using iteration_type = int;

    AbstractTemperatureDecreaser();
    explicit AbstractTemperatureDecreaser(temperature_type new_temperature, iteration_type new_iteration = 0);

    temperature_type operator()();

    virtual temperature_type decrease() = 0;

    [[nodiscard]] temperature_type get_temperature() const;

protected:
    temperature_type temperature;
    iteration_type iteration;
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTTEMPERATUREDECREASER_H
