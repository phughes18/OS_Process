// execute.cpp
// Program to execute the instructions in an input file


#include <string>
#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"
#include "process_table.h"
#include "process.h"
#include "cpu_scheduler_base.h"
#include "cpu_scheduler_fcfs.h"
#include "cpu_scheduler_priority_rr.h"

using namespace std;


int main(int argc, char ** argv)
{
      // Validate the command line
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << "sample_input.json" << endl;
        return(3);
    }

           
    // Open the input file. 
    ifstream in(argv[1]);
    if (! in.good()) {
        cerr << "Failed to open file " << argv[1] << endl;
        return(4);
    }

    nlohmann::json input_json;

    // Read the file into the json object.
    // If the input file is not in json format, this will
    // throw an exception
       try {
        in >> input_json;
    } catch (nlohmann::json::exception& e) {
        cerr << "Error: " << e.what() << endl;
        cerr  << "exception id: " << e.id << endl;
        return(5);
    }


    // Table size defaults to 100 if not specified on the command line
    int tableSize = 100;
    

    // Retrieve the table_size from the "options" 
    // segment of the input file
    if (input_json.contains("options")) {
        if (input_json["options"].contains("table_size")) {
            tableSize = input_json["options"]["table_size"];
        }
    }

    // Initialize a ProcessTable with the table size obtained from
    // the options (or the default if no option was specified)
    ProcessTable table(tableSize);


    // These variables are based on the contents of the "schedule"
    // segment in the input.
    std::string algorithm = "";
    
    
    // TODO: 
    // Determine the scheduling algorithm from the schedule
    // segment. If the scheduling algorithm in not found
    // in the input, or if the value is not 
    // one of "fcfs" or "priority_round_robin" 
    // exit with an error
   
    if (input_json.contains("schedule"))
    {
        if (input_json["schedule"].contains("scheduling_algorithm"))
        {
            algorithm = input_json["schedule"]["scheduling_algorithm"];
        }
    }
    

    // Initialize a scheduling object depending on the algorithm
    CpuSchedulerBase * scheduler;
    if (algorithm == "fcfs") {
        scheduler = (CpuSchedulerBase *) new CpuSchedulerFcfs();
    } else if (algorithm == "priority_round_robin") {
        scheduler = (CpuSchedulerBase *) new CpuSchedulerPriorityRr;
    } else {
        cerr << "Error: Unknown algorithm '" << algorithm <<
                "'. Legal values are 'fcfs' and 'priority_round_robin'" << endl;
        return(7);
    }

    
    // TODO: 
    // If "scheduling_quantum" is in the "schedule" segment, 
    // retrieve its value. Validate that the value is greater than 0.
    // If an incorrect value is provided, exit with an error
    //
    // Scheduling quantum defaults to 1 if it is not specified in the
    // input.
    int scheduling_quantum = 1;

    if (input_json["schedule"].contains("scheduling_quantum"))
    {
        if (input_json["schedule"]["scheduling_quantum"] > 0)
            scheduling_quantum = input_json["schedule"]["scheduling_quantum"];
    }
    
    cout << "8" << endl;

    // TODO: 
    // Iterate the "processes" list in the input json.
    // Add each process in the list to *both* the process
    // table and the scheduler.

    for (auto action = input_json["processes"].begin(); action != input_json["processes"].end(); action++)
    {
        Process p;
       
        if (action->contains("process_name"))
            p.setProcessName(action->at("process_name"));

        if (action->contains("cpu_needed"))
            p.setCPUneeded(action->at("cpu_needed"));

        if (action->contains("priority"))
            p.setPriority(action->at("priority"));

        if (action->contains("processId"))
            p.setProcessId(action->at("processId"));

        table.add(p);
        scheduler->addProcess(p);
   
         
    }

    // Print the process table one time after all processes are loaded
    std::cout << table;
    std::cout << endl;
    
    
    // TODO:
    // Execute the scheduling algorithm in a loop.
    // The basic sequence is:
    // 1. Get the process ID of the next process that should be run
    while (scheduler->nextProcess() != -1)
    {      
        int pid = scheduler->nextProcess();
        
        // 2. Find that process in the ProcessTable
        Process* main;
        main = table.find(pid);

        // 3. Call that process's run() method, making sure to 
        //    tell it how many cycles to execute.
        
        int cpuUsed = main->run(3);
        int needed = main->cpu_needed();

        // 4. Print the entire process table
        cout << table;
        // 5. If the process that you just ran has used up all of the
        //    CPU that it needed, remove it from the process table
        //    and the scheduler
        if (cpuUsed == needed)
        {
            table.remove(pid);
            scheduler->removeProcess(*main);
            
        }
    }
    //
    // The loop should end when there are no longer any processes to schedule
    
    return 0;
}
