/**
 * @author sanyavertolet
 */

#include "SchedulingSASolution.h"

#include <utility>

SchedulingSASolution::SchedulingSASolution(int n_proc): AbstractSASolution(), data() {
    for (int i = 0; i < n_proc; ++i) {
        data.push_back({});
    }
}

SchedulingSASolution::SchedulingSASolution(ir_type new_data): AbstractSASolution(), data(std::move(new_data)) { }

SchedulingSASolution::operator std::string() {
    std::string result;
    for(int i = 0; i < data.size(); ++i) {
        result += std::to_string(i) + ": ";
        for(auto task : data[i]) {
            result += "<" + std::to_string(task) + ">";
        }
        result += "\n";
    }
    return result;
}

