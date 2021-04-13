#ifndef CISC5595_CPU_SCHEDULER_FCFS_H
#define CISC5595_CPU_SCHEDULER_FCFS_H

// cpu_scheduler_fcfs.h
//
// First-come first-served CPU scheduler.

#include "cpu_scheduler_base.h"
#include "process.h"

#include <deque>

using namespace std;

class CpuSchedulerFcfs : public CpuSchedulerBase {

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
        // Add a data structure here which will hold processes
        // waiting to be scheduled. 
        //
        deque<int> schedule;

        // Because this is a first-come, first-served, scheduler,
        // new processes that are added should be added at the end
        // of the list, and when it is time to schedule the next process,
        // the first one on the list should always be scheduled 
};

#endif