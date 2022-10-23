/**
 * @author sanyavertolet
 */

#include "SchedulingSASolution.h"

SchedulingSASolution::SchedulingSASolution(): AbstractSASolution(), solution() {}

std::string SchedulingSASolution::get_solution() {
    std::string result;
    for(int i = 0; i < solution.size(); ++i) {
        result += std::to_string(i) + ": ";
        for(auto task : solution[i]) {
            result += "<" + std::to_string(task) + ">";
        }
        result += "\n";
    }
    return result;
}

