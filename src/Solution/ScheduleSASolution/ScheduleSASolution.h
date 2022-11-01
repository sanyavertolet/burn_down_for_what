/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULESASOLUTION_H
#define BURN_DOWN_FOR_WHAT_SCHEDULESASOLUTION_H

#include <vector>
#include <unordered_set>
#include <string>

#include "../AbstractSASolution/AbstractSASolution.h"

class ScheduleSASolution: public AbstractSASolution {
public:
    using ir_type = std::vector<std::vector<int>>;

    explicit ScheduleSASolution(int n_proc, int n_jobs);

    ir_type data;
    operator std::string() override; // NOLINT(google-explicit-constructor)
private:

};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULESASOLUTION_H
