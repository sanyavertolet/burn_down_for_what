/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_TIMER_H
#define BURN_DOWN_FOR_WHAT_TIMER_H

#include <chrono>

template <class DT = std::chrono::milliseconds, class ClockT = std::chrono::steady_clock>
class Timer {
public:
    void tick() {
        end = timep_t{};
        start = ClockT::now();
    }

    void tock() {
        end = ClockT::now();
    }

    template <class T = DT>
    auto duration() const {
        assert(end != timep_t{} && "toc before reporting");
        return std::chrono::duration_cast<T>(end - start);
    }
private:
    using timep_t = typename ClockT::time_point;
    timep_t start = ClockT::now();
    timep_t end = {};
};

#endif //BURN_DOWN_FOR_WHAT_TIMER_H
