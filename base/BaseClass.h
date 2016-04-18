//
// Created by abondar on 13.04.16.
//

#ifndef SOMECPP_BASECLASS_H
#define SOMECPP_BASECLASS_H

#include <string>
using namespace std;

class BaseClass {

public:
    BaseClass(string type);
    ~BaseClass();
    int mult2(int val);
    void showVal();

private:
    int ss;

};


#endif //SOMECPP_BASECLASS_H
