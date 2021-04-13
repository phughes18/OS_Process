# CISC 5595 Assignment 3: Process Scheduling

In this assignment, we will enhance our Process class so that we can simulate a "running" process. We will then implement two different CPU scheduling algorithms using this capability, and update our test program to execute the algorithms.

Throughout the templates, the places where you will need to add your own code are marked with "TODO". 

# Process class

We will start with the Process and ProcessTable classes from Assignment 2.

## Changes to the Process class

We will need to make a number of changes to the Process class for this project, as follows:

### Add new attributes

Add the following new attributes to your Process class:

* `priority` - an integer value representing the scheduling priority of the process, where 0 repesents the highest priority. 
* `cpu_needed` - the number of cpu cycles the process needs to run over its entire lifetime
* `cpu_used` - the number of cpu cycles that have actually executed for the process. This will be an internal attribute of the object.

### Add a `run()` method

The `run()` method will execute that process for a specific number of CPU cycles.

### Update Process Input and Output

Handle additional attributes when retrieving Process objects and also when printing them out.


Update your `Process` class as indicated by the TODO: entries in the `process.h/process.cpp` or `process.py` files.

# CPU Scheduler Classes

You will implement two different scheduling algorithms for this assignment, based on the instructions below.

Each of your algorithms will implement the following three functions:
* `addProcess` will take a process object and store the process ID and other information in a data structure local to the scheduling object.
* `removeProcess` will remove a process from the scheduler
* `nextProcess` will determine the next process that should run and return its process ID

You will implement a *First-Come, First-Served* and a *Priority Round Robin* scheduler.

The scheduling classes are implemented slightly differently between C++ and Python, as noted below.

## C++

### Base Class

For C++, the starter files include the file `cpu_scheduler_base.h`, which defines an [Abstract Base Class](https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm) for our schedulers. This base class requires that any class derived from it must implement the following methods:
* `virtual bool addProcess(Process& process)`
* `virtual bool removeProcess(Process& process)`
* `virtual Process& nextProcess()`

### First Come, First-Served Scheduler

There are starter files in your directory called `cpu_scheduler_fcfs.h` and `cpu_scheduler_fcfs.cpp`. These files will contain the declaration and implementation of your first-come, first-served scheduling class.

Based on the instructions in these files, implement this scheduler class.

### Priority round-robin scheduler

There are starter files in your directory called `cpu_scheduler_priority_rr.h` and `cpu_scheduler_priority_rr.cpp`. These files will contain the declaration and implementation of your Priority Round Robin scheduling class.

Based on the instructions in these files, implement this scheduler class.

## Python

### First Come, First-Served Scheduler

There is starter file in your directory called `cpu_scheduler_fcfs.py` which contains the skeleton of your First-Come, First-Served scheduler class. Based on the instructions in this file, implement this scheduler class.

### Priority round-robin scheduler

There is a starter file in your directory called `cpu_scheduler_priority_rr.py` which contains the skeleton of your Priority Round-Robin scheduler class. Based on the instructions in this file, implement the class.

# Input File

The input file format for this assignment is slightly different than it was for assignment 2. As with assignment 2, there is a JSON schema file (`assignment3-input-schema.json`) that can help you with editing. 

Here are the contents of the input file for assignment 3:
## Options
The `options` object for this assignment is the same as for the previous one; it contains a `table_size` element that determines the size of the process table. The only consideration here is that you should make sure the `table_size` is large enough to hold all of the processes in the next section.
## Processes
Instead of an `actions` section, this version contains a `processes` section, which enumerates all of the processes that will be run using your scheduler. For this assignment, each `process` within the `processes` section contains `priority` and `cpu_needed` values, in addition to the `process_name`.
## Schedule
Finally, the input file contains a `schedule` section, which gives the details of what scheduling parameters should be used for a particular run.

The `schedule` object contains the following entries:
* `scheduling_algorithm` - determins which algorithm should be used. Valid ales are `fcfs` or  `priority_round_robin`
* `scheduling_quantum` - the number of CPU cycles that a process can run at each scheduling iteration. This defaults to 1.

# execute

The `execute` main program (either `execute.cpp` or `execute.py`) is the main program that you will use to exercise your scheduling algorithms.

Your program will:
* Read the table_size from the input and initialze the ProcessTable object
* Read the scheduling options from the input and initialize the scheduling object
* Read the list of proceses from the input and add them to the process table and the scheduler
* Simulate the execution of the processes until all processes are complete.

Follow the comments in `execute.cpp` or `execute.py` to implement and test this program. 

# Submission

When you have completed your assignment, commit your work to git, push to github, update the `submit.txt` file, and upload it to Blackboard.

