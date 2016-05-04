//
// Created by abondar on 04.05.16.
//
#include <iostream>

using namespace std;
class Something {

public:
    Something(){ cout<< "2"; }
    virtual ~Something(){ cout<< "2";}
};

class Parent{

public:
    Parent(){ cout<< "1"; }
    virtual ~Parent(){ cout<< "1";}


};

class Child : public Parent{
public:
public:
    Child(){ cout<< "3"; }
    virtual ~Child(){ cout<< "3";}
protected:
    Something member;
};


int main(){
    Child ch;
    return 0;
}
