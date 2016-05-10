//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_SCHEDULER_H
#define SOMECPP_SCHEDULER_H


#include <vector>
#include "Process.h"
#include "RoundRobin.h"

class Scheduler {
public:
    Scheduler(const vector<Process>& processes);
    void scheduleTimeSlice();
    void removeProcess(const Process& process);

protected:
    RoundRobin<Process>rr;

};


#endif //SOMECPP_SCHEDULER_H
