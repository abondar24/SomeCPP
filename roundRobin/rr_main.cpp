//
// Created by abondar on 12.05.16.
//

#include <vector>
#include "Process.h"
#include "Scheduler.h"

int main(){

    vector<Process> processes = {Process("1"), Process("2"), Process("3")};
    Scheduler scheduler(processes);
    for (int i = 0; i < 4; i++) {
        scheduler.scheduleTimeSlice();
    }
    scheduler.removeProcess(processes[1]);
    cout << "Removed second process" << endl;
    for (int i = 0; i < 4; i++) {
        scheduler.scheduleTimeSlice();
    }

    return 0;
}