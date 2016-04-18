//
// Created by abondar on 12.04.16.
//

#include <iostream>
#include <array>
#include <memory>

#include <vector>
#include "base.h"
#include "BaseClass.h"

using namespace std;

int main() {
    std::cout << "Let's start the show" << std::endl;

    int a = 256;
    short b = 255;
    long c = 100500;
    float pi = 3.14;
    double p = 2;

    a++;
    a *= 2;

    b = short(a);
    cout << b << endl;

    c = b * 1000;
    cout << c << endl;

    pi = c + 0.76;
    cout << pi << endl;

    p = (double) pi / 100;
    cout << p << endl;

    //at last for-each
    array<int, 4> arr = {1, 2, 3, 4};

    std::cout << "Arr size " << arr.size() << endl;
    for (auto i:arr) {
        i += 2;
        cout << i << endl;
    }


    int *pa = new int;
    *pa = 8;
    cout << "Heap addr " << pa << endl;
    cout << "Stack addr " << &pa << endl;
    cout << "Pointer val " << *pa << endl;

    try {
        cout << division(3.0, 0.0) << endl;
    } catch (const std::exception(exception1)) {
        std::cout << "Exception Alert!" << endl;
    }


    BaseClass bc("Stack init");
    bc.mult2(4);
    bc.showVal();

    BaseClass *bc1 = new BaseClass("Heap init");
    bc1->mult2(7);
    bc1->showVal();
    delete bc1;

    vector<string> vector1 = {"Medeved","Balalika"};
    vector1.push_back("Vodka");
    for (auto& str:vector1){
        cout <<str<<endl;
    }

    return 0;

};

double division(double inum, double denom) {
    if (denom == 0) {
        throw std::exception();
    }

    return inum / denom;
}