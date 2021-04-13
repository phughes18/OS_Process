// process.cpp
//
// Include your implementation of the Process class here.

#include <string>
#include <iostream>
#include <sstream>

#include "process.h"
#include "nlohmann/json.hpp"

using namespace std;

// TODO: 
// Add the additional arguments so the new attributes can be initialized here.
// Initialize the attribute for cpu_used to 0
Process::Process(const string& processName, int priority, int processId, int cpu_needed) :
    m_processName(processName), 
    m_priority(priority),
    m_processId(processId),
    m_cpu_needed(cpu_needed),
    m_cpu_used(0)
{
    // Nothing to do here
}

const string& Process::processName() const
{
    return m_processName;
}

void Process::setProcessName(const string& processName)
{
    m_processName = processName;
}

const int Process::processId() const
{
    return m_processId;
}

void Process::setProcessId(int processId)
{
    m_processId = processId;
}


// TODO:
// Provide the implementations for the new setter/getter
// methods declared in the header file.

void Process::setPriority(int priority)
{
    m_priority = priority;
}

const int Process::priority() const
{
    return m_priority;
}

void Process::setCPUneeded(int cpu_needed)
{
    m_cpu_needed = cpu_needed;
}

const int Process::cpu_needed() const
{
    return m_cpu_needed;
}

int Process::cpu_used()
{
    return m_cpu_used;
}


int Process::run(int numCycles)
{
    // TODO:
    // Impmlement the run() method.
    //
    // Determine how many cycles the process should actually execute
    // (that number should either be the value of numCycles provided,
    // or a smaller number if the process doesn't need that many cycles)
    //
    // Update cpu_used to reflect the actual number of cycles executed, 
    // and return the number executed.

    if (numCycles >= m_cpu_needed)
    {
        m_cpu_used = m_cpu_needed;
    }
    else
    {
        m_cpu_used = numCycles;
    }

    return m_cpu_used;
}



// Friend function to print the object
std::ostream& operator<<(std::ostream& os, const Process& p)
{
    nlohmann::json j;
    to_json(j, p);
    os << j;
    return os;
}

// Functions to convert a process to and from json
void to_json(nlohmann::json& j, const Process& p)
{
    j["process_name"] = p.processName();
    j["process_id"] = p.processId();

    // TODO:
    // Add the new Process attributes to the output json

}

void from_json(const nlohmann::json& j, Process& p)
{
    if (j.contains("process_name")) {
        p.setProcessName(j["process_name"]);
    } else {
        ostringstream o;
        o << "Missing process_name in json input: " << j;
        throw(std::invalid_argument(o.str()));
    }

    if (j.contains("process_id")) {
        p.setProcessId(j["process_id"]);
    }

    // TODO: 
    // Retrieve the priority and cpu_needed attributes
    // from the input json and set them in the output
    // Process object

    if (j.contains("priority")) {
        p.setPriority(j["priority"]);
    }

    if (j.contains("cpu_needed")) {
        p.setCPUneeded(j["cpu_needed"]);
    }


}
