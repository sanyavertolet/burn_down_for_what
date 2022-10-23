/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULINGSASOLUTION_H
#define BURN_DOWN_FOR_WHAT_SCHEDULINGSASOLUTION_H

#include <vector>
#include <unordered_set>
#include <string>

#include "../AbstractSASolution/AbstractSASolution.h"

class SchedulingSASolution: public AbstractSASolution {
public:
    SchedulingSASolution();
    std::string get_solution();
private:
    using ir_type = std::vector<std::unordered_set<int>>;
    ir_type solution;
};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULINGSASOLUTION_H
