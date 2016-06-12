//
// Created by abondar on 12.06.16.
//

#include <iostream>
#include <thread>
#include "Counter.h"

using namespace std;

int main(){
    cout.sync_with_stdio(true); //sure count is thread safe
    thread t1{Counter(1,20)};

    Counter c(2,30);
    thread t2{c};

    //using temp
    thread t3(Counter(3,10));

    t1.join();
    t2.join();
    t3.join();
    return 0;
}