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
    using ir_type = std::vector<std::vector<int>>;

    explicit SchedulingSASolution(int n_proc);
    explicit SchedulingSASolution(ir_type new_solution);

    ir_type data;
    operator std::string() override; // NOLINT(google-explicit-constructor)
private:

};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULINGSASOLUTION_H
