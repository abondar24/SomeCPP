//
// Created by abondar on 11.05.16.
//

#include "Scheduler.h"


Scheduler::Scheduler(const vector<Process>& processes) {
    for (auto& process : processes){
        rr.add(process);
    }
}
void Scheduler::scheduleTimeSlice(){
    try{
        rr.getNext().doWorkDuringTimeSlice();
    }catch (const out_of_range&){
        cerr << "No more proecesses to schedule"<<endl;
    }
}

void Scheduler::removeProcess(const Process& process){
    rr.remove(process);
}