//
// Created by abondar on 09.05.16.
//

#include <iostream>
#include <vector>
#include <limits>
#include "Process.h"
#include "Scheduler.h"

using namespace std;

auto main() -> int{
    vector <int> vector1(10,0);
    vector<int> vector2(10,0);

    if (vector1==vector2){
        cout << "equal!"<<endl;
    } else {
        cout << "not equal!"<<endl;
    }
    vector1[3]=7;
    if (vector1<vector2){
        cout << "vector 1 is less than vector 2"<<endl;
    } else {
        cout << "vector 1 is greater than vector 2"<<endl;
    }

    for (vector<int>::iterator iter = vector2.begin();iter!= vector2.end();++iter){

        cout <<  *iter << " ";
    }

    vector<string>vector3;
    for (auto& str: vector3){
        str.append("A");
    }

    vector<Process> processes ={Process("1"),Process("2"),Process("3")};
    Scheduler scheduler(processes);
    for (int i=0;i<4;i++){
       scheduler.scheduleTimeSlice();
    }
    scheduler.removeProcess(processes[1]);
    cout << "Removed second process"<<endl;
    for (int i=0;i<4;i++){
        scheduler.scheduleTimeSlice();
    }


    return 0;
}