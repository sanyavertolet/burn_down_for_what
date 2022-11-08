/**
 * @author sanyavertolet
 */

#ifndef BURN_DOWN_FOR_WHAT_ABSTRACTSASOLUTION_H
#define BURN_DOWN_FOR_WHAT_ABSTRACTSASOLUTION_H

#include <string>

class AbstractSASolution {
public:
    virtual operator std::string() = 0; // NOLINT(google-explicit-constructor)
    virtual ~AbstractSASolution() = default;
};


#endif //BURN_DOWN_FOR_WHAT_ABSTRACTSASOLUTION_H
