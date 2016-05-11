//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_PROCESS_H
#define SOMECPP_PROCESS_H


#include <string>
#include <iostream>

using namespace std;
class Process {
public:
    Process(const string& name): name(name){};
    void doWorkDuringTimeSlice(){
        cout << "Process " << name << " performing work during time slice"<<endl;
    }

    bool operator==(const Process& rhs){
        return name == rhs.name;
    }

protected:
    string name;
};


#endif //SOMECPP_PROCESS_H
