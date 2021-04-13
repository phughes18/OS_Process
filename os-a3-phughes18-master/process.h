#ifndef CISC5595_PROCESS_H
#define CISC5595_PROCESS_H

// process.h
//
// Class definition for a simulated process in our operating system
//

#include <iostream>
#include <string>

#include "nlohmann/json.hpp"

using namespace std;

class Process {
    public:

        // TODO:
        // Update the declaration of the constructor so the new attributes
        // can be provided by the caller
        Process(const string& processName = "", int priority = 100, int processId=0, int cpu_needed=0);

        // Setters and getters
        const string& processName() const;
        void setProcessName(const string& processName);

        const int processId() const;
        void setProcessId(int processId);

        // TODO: 
        // Add declarations for setters and getters
        // for the priority and cpu_needed
        // attributes

        const int priority() const;
        void setPriority(int priority);

        const int cpu_needed() const;
        void setCPUneeded(int cpu_needed);

        // TODO:
        // Add a declaration for a getter for the cpu_used attribute

        int cpu_used();

        // run
        // Execute the given number of CPU cycles, if we need that many.
        // Return the number of cycles actually executed.
        int run(int numCycles);

        // This function will enable printing the Process using 
        // a construct like
        //    cout << process
        // The output should include all of the data members of the class
        // printed on a single line.
        friend std::ostream& operator<<(std::ostream& os, const Process& p);


    private:
        // Include private member data here`

        int m_processId;
        std::string m_processName;

        // TODO:
        // Add new attributes here
        int m_priority;
        int m_cpu_needed;
        int m_cpu_used;
        

};

// These methods will be used to populate a process object from
// json input files, or to output the json representation of a process
// object.
//
// See https://github.com/nlohmann/json/blob/develop/README.md#arbitrary-types-conversions
// for details on how to implement these functions

void to_json(nlohmann::json& j, const Process& p);
void from_json(const nlohmann::json& j, Process& p);

#endif // CISC5595_PROCESS_H
