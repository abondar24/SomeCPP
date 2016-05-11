//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_ERROR_H
#define SOMECPP_ERROR_H

#include <iostream>

using namespace std;
class Error{
public:
    Error(int priority,const std::string& errMsg):mPriority(priority),mError(errMsg){};
    int getPriority() const { return mPriority;}
    std::string getErrorString() const { return mError;}
    friend bool operator<(const Error& lhs, const Error& rhs);
    friend  std::ostream&operator<<(std::ostream& os, const Error& err);
protected:
    int mPriority;
    std::string mError;
};
#endif //SOMECPP_ERROR_H
