#include "cpu_scheduler_fcfs.h"
#include "process.h"
#include <deque>

using namespace std;

bool CpuSchedulerFcfs::addProcess(Process process)
{
   // TODO:
   // Add a process to be scheduled.


    schedule.push_back(process.processId());

    if (schedule[0] == process.processId())
      return true;

    return false;


   // Return true if the process was successfully added,
   // and false otherwise
}

// Remove a process from the scheduling queue
bool CpuSchedulerFcfs::removeProcess(Process process)
{
    // TODO: 
    // Remove a process from the scheduler. 
    // If the process was successfully removed,
    // return true; otherwise, if the process
    // wasn't found in the schedule, return false.

   
    for (int i = schedule.size()-1; i >= 0 ; i--)
    {
        if (schedule[i] == process.processId())
        {
          schedule.erase(schedule.begin()+i);
          return true;
        }

    }
    return false;

}

// Find the next process to run
int CpuSchedulerFcfs::nextProcess()
{
   // TODO: 
   // Return the process ID of the next process
   // that should be executed.
    if (schedule.empty())
      return -1;

    return schedule.front();


   // If there are no processes remaining to 
   // schedule, return -1
}
