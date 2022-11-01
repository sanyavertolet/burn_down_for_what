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

    temperature_type operator()(iteration_type iteration);

    virtual temperature_type decrease(iteration_type iteration) = 0;

    [[nodiscard]] temperature_type get_temperature() const;

    virtual ~AbstractTemperatureDecreaser() = default;
protected:
    temperature_type temperature;
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTTEMPERATUREDECREASER_H
