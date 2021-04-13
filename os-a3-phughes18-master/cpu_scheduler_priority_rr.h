#ifndef CISC5595_CPU_SCHEDULER_PRIORITY_H
#define CISC5595_CPU_SCHEDULER_PRIORITY_H

// cpu_scheduler_fcfs.h
//
// First-come first-served CPU scheduler.
#include <vector>
#include "cpu_scheduler_base.h"
#include "process.h"


using namespace std;

class CpuSchedulerPriorityRr : public CpuSchedulerBase {

    public:

        // Add a new process to the set of processes to be
        // scheduled.
        virtual bool addProcess(Process process);

        // Remove a process from the set of processes to be 
        // scheduled (generally because it's done)
        virtual bool removeProcess(Process process);

        // Get the process id of the next process to be scheduled
        // If no processes remain to schedule, return -1
        virtual int nextProcess();

    private:
        // TODO:

        vector<pair<int,int>>vect;

        // Add a data structure here that will hold the processes
        // that need to be scheduled. Note that since you need to schedule 
        // in order of priority, you will need to store both the priority
        // and the process ID of each process.


};

#endif