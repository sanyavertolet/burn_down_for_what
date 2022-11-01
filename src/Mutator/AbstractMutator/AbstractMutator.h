/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_ABSTRACTMUTATOR_H
#define BURN_DOWN_FOR_WHAT_ABSTRACTMUTATOR_H

#include <type_traits>

#include "../../Solution/AbstractSASolution/AbstractSASolution.h"

template<class Solution>
class AbstractMutator {
    static_assert(std::is_base_of<AbstractSASolution, Solution>::value, "Solution should inherit AbstractSASolution");
public:
    virtual Solution mutate(Solution solution) = 0;
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTMUTATOR_H
