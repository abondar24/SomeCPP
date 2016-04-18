//
// Created by abondar on 13.04.16.
//

#include "BaseClass.h"
#include <iostream>

using namespace std;


BaseClass::BaseClass(string type){

    std::cout<< type <<std::endl;
    ss=0;
};

BaseClass::~BaseClass(){};

int BaseClass:: mult2(int val){
    ss = val*2;
};

void BaseClass::showVal(){
    std::cout<< ss<<std::endl;
};

