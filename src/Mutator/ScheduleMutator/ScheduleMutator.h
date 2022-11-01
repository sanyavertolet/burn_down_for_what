/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_SCHEDULEMUTATOR_H
#define BURN_DOWN_FOR_WHAT_SCHEDULEMUTATOR_H

#include "../AbstractMutator/AbstractMutator.h"
#include "../../Solution/ScheduleSASolution/ScheduleSASolution.h"

class ScheduleMutator: AbstractMutator<ScheduleSASolution> {
public:
    ScheduleMutator() = default;
    ScheduleSASolution mutate(ScheduleSASolution solution) override;
};


#endif //BURN_DOWN_FOR_WHAT_SCHEDULEMUTATOR_H
