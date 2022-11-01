/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULINGMUTATOR_H
#define BURN_DOWN_FOR_WHAT_SCHEDULINGMUTATOR_H

#include "../AbstractMutator/AbstractMutator.h"
#include "../../Solution/SchedulingSASolution/SchedulingSASolution.h"

class SchedulingMutator: AbstractMutator<SchedulingSASolution> {
public:
    SchedulingMutator() = default;
    SchedulingSASolution mutate(SchedulingSASolution solution) override;
};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULINGMUTATOR_H
