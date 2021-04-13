CPPFLAGS = -g -I.

libsrc = process.cpp process_table.cpp cpu_scheduler_fcfs.cpp cpu_scheduler_priority_rr.cpp
libobj = $(libsrc:.cpp=.o)

all:  execute $(libobj)

execute: execute.o $(libobj)
	$(CXX) -o $@ execute.o $(libobj)

.PHONY: clean
clean:
	rm -f execute execute.o $(libobj)