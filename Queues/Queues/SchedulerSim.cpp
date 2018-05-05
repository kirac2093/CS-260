/*****************************************************
Name: SchedulerSim.cpp
Code: Kira Corbett
Date: 4/26/18
Desc: Class implementations for Schedule Simulation.
******************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

#include "SchedulerSim.h"

SchedulerSim::SchedulerSim()
{

}

SchedulerSim::~SchedulerSim()
{
	
}

/*================================================================
Name: startSim
Desc: runs all of the processes within the array of queues
Args: none
Retn: none (called from main)
================================================================*/
void SchedulerSim::startSim()
{
	process processes;
	int passedTime = 0;

	// set up simulator table
	cout << setw(5) << "PID" << setw(10) << "Initial" << setw(10) << "Time" << setw(10) << "Time"
		<< setw(10) << "Time" << setw(10) << "Elapsed" << setw(10) << "Final" << endl;

	cout << setw(15) << "Priority" << setw(10) << "Needed" << setw(10) << "Started"
		<< setw(10) << "Ended" << setw(10) << "Time" << setw(10) << "Priority" << endl << endl;

	// read file and process queues
	readProcesses();

	// serve a process
	for (int i = 0; i < PRIORITY_QUEUE_SIZE; i++)
	{
		// while there are still items in the queue, pop and process them
		while (!PriorityQueue[i].empty())
		{
			if (!PriorityQueue[i].empty())
			{
				processes = PriorityQueue[i].front();
				PriorityQueue[i].pop();
			}

			// if the process is done
			if (checkTime(processes) == true)
			{
				// print out statistics
				printSim(processes);
			}
			else // process is not done
			{
				// update priority of queue item & push onto queue
				updateProcess(processes);
			}
		}

	}
}

/*================================================================
Name: readProcesses
Desc: read the processes from the input file
Args: none
Retn: true if successful, false otherwise
================================================================*/
bool SchedulerSim::readProcesses()
{
	process process;
	char outputData[TIME_SLICE];

	infile.open("sim.data");

	if (!infile)
	{
		// if the file can't be opened, print an error and terminate
		cout << "ERROR! The input files does not exist." << endl;
		return false;
	}

	while (!infile.eof())
	{
		// extract data
		infile.getline(outputData, DATA_SIZE);

		// process each line in input file and place into appropriate queue
		processQueues(outputData, process);
	}
	return true;
}

/*================================================================
Name: processQueues
Desc: insert process into appropriate queue
Args: data (string), process (ref param process)
Retn: none
================================================================*/
void SchedulerSim::processQueues(string data, process& process)
{
	string extractedData = "";

	static unsigned int processID = 1;
	unsigned int i = 0;
	int priority = 0;
	int time = 0;

	// initialize processes
	process.processID = processID;
	process.elapsedTime = 0;
	process.startTime = 0;
	process.endTime = 0;
	process.processRun = false;

	// identify queue priority
	while (i < data.length() && (data[i] >= 48 && data[i] <= 57))
	{
		extractedData += data[i];
		i++;
	}

	// extract the queue priority
	stringstream streamData(extractedData);
	streamData >> priority;
	process.initialPriority = priority;
	process.currentPriority = process.initialPriority;

	// traverse through space between data
	while (i < data.length() && data[i] == ' ')
	{
		i++;
	}

	extractedData = "";
	priority = 0;

	// identify data
	while (i < data.length() && (data[i] >= 48 && data[i] <= 57))
	{
		extractedData += data[i];
		i++;
	}

	// extract the time needed
	stringstream stream(extractedData);
	stream >> time;
	process.initialTime = time;	// initial time is the time needed
	process.requiredTime = process.initialTime;	// required time is the time the data needs to run
	
	processID++;

	// push the process onto the queue
	PriorityQueue[process.currentPriority].push(process);
}

/*================================================================
Name: checkTime
Desc: checks the task's runtime
Args: processes (process&)
Retn: true if successful, false otherwise
================================================================*/
bool SchedulerSim::checkTime(process& processes)
{
	ifRan(processes);

	// if it is less than the TIME_SLICE
	if (processes.requiredTime < TIME_SLICE)
	{
		// let the process run and update its time information
		processes.elapsedTime = processes.endTime - processes.startTime;
		return true;
	}
	else
	{
		// only run a TIME_SLICE and update
		processes.requiredTime = processes.requiredTime - TIME_SLICE;
		return false;
	}
}

/*================================================================
Name: ifRan
Desc: checks if process has ran or needs to run
Args: processes (process&)
Retn: none
================================================================*/
void SchedulerSim::ifRan(process& processes)
{
	int passedTime = 0;

	// check if the process has been ran
	if (processes.processRun == false)
	{
		processes.processRun = true;
		processes.startTime = ourTime;
	}

	// run the process 
	while (processes.requiredTime > passedTime && passedTime < TIME_SLICE)
	{
		passedTime++;
		ourTime++;
	}

	processes.endTime = ourTime;
}

/*================================================================
Name: updateProcess
Desc: updates the queue priority of process
Args: processes (process&)
Retn: none
================================================================*/
void SchedulerSim::updateProcess(process& processes)
{
	// 0 = highest priority queue
	// 4 = lowest priority queue

	// if the current priority is less than 4
	if (processes.currentPriority < 4)
	{
		processes.currentPriority++;
	}

	// push the data into the next lowest queue (even if it was popped from queue 4)
	PriorityQueue[processes.currentPriority].push(processes);
}

/*================================================================
Name: printSim
Desc: output statistics
Args: processes (process&)
Retn: none
================================================================*/
void SchedulerSim::printSim(process& processes)
{
	const char spacer = ' ';
	const int dataWidth = 5;
	const int width = 15;

	cout << setw(3) << processes.processID << setw(10) << processes.initialPriority << setw(10) << processes.initialTime << setw(10) 
		 << processes.startTime << setw(10) << processes.endTime << setw(10) << processes.elapsedTime << setw(10) << processes.currentPriority 
		 << endl << endl;
}