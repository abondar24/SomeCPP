//
// Created by abondar on 12.05.16.
//

#include "ErrorCorrelator.h"


void ErrorCorrelator::addError(const Error &error) {
    errors.push(error);
}

Error ErrorCorrelator::getError() throw(std::out_of_range) {
    if (errors.empty()) {
        throw out_of_range("No elemensts");
    }

    Error top = errors.top();
    errors.pop();
    return top;
}

bool operator<(const Error &lhs, const Error &rhs){
    return (lhs.mPriority < rhs.mPriority);
}

ostream &operator<<(ostream &os, const Error &err){
    os << err.mError << " (priority" << err.mPriority << ") ";
    return os;
}
