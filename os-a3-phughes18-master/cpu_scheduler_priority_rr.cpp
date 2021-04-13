#include "cpu_scheduler_priority_rr.h"
#include "process.h"
#include <vector>



bool CpuSchedulerPriorityRr::addProcess(Process process)
{
    // TODO:
    // Add a process to be scheduled.

    (vect.push_back(make_pair(process.priority(), process.processId())));
    
    sort(vect.begin(), vect.end());
    return true;

    // The processes should be stored in such a way that
    // all processes of the same priority are grouped together, 
    // and a new process is added to the end of the list for a 
    // particular priority.

    // Return true if the process was successfully added,
    // and false otherwise.

}

// Remove a process from the scheduling queue
bool CpuSchedulerPriorityRr::removeProcess(Process process)
{
    // TODO:
    // Remove a process from the scheduler. 
    // If the process was successfully removed,
    // return true; otherwise, if the process
    // wasn't found in the schedule, return false.

    for (int i = 0; i < vect.size(); i++)
    {
        if (process.processId() == vect[i].first)
        {
            vect.erase(vect.begin()+i);
            return true;
        }
    }
    return false;

}

// Find the next process to run
int CpuSchedulerPriorityRr::nextProcess()
{
   // TODO:
   // Return the process ID of the next process
   // that should be executed.
   //
   // The next process to be executed should always 
   // be a process that has the highest priority of the
   // ones remaining in the scheduler.
   //
   // If there is more than one process at the highest priority,
   // these processes should be scheduled in a round-robin fashion,
   // so each of the processes at the highest priority gets
   // to run in turn until they are all complete.
   //
   // If there are no processes remaining to 
   // schedule, return -1

  if (vect.empty())
    return -1;

  int i = 0;
  while (vect[i].first == vect[i+1].first)
  {
    i++;
  }

  for (int j=0; j < i; j++)
  {
    swap(vect[j], vect[j+1]);
  }

  return vect[0].second;


}
