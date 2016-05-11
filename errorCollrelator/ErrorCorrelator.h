//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_ERRORCOLLERATOR_H
#define SOMECPP_ERRORCOLLERATOR_H


#include <queue>
#include "Error.h"

class ErrorCorrelator {
public:
    ErrorCorrelator() { }

    void addError(const Error &error);

    Error getError() throw(std::out_of_range);

protected:
    std::priority_queue<Error> errors;
};


#endif //SOMECPP_ERRORCOLLERATOR_H
