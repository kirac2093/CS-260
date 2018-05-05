/*****************************************************
Name: SchedulerSim.h
Code: Kira Corbett
Date: 4/26/18
Desc: Class definitions for Schedule Simulation
******************************************************/

#include <fstream>
#include <string>
#include <queue>

using namespace std;

const static int PRIORITY_QUEUE_SIZE = 5;
const static int TIME_SLICE = 20;
const static int DATA_SIZE = 20;

class SchedulerSim
{
public:
	SchedulerSim();
	/*==================================================
	Desc: constructor
	===================================================*/

	~SchedulerSim();
	/*==================================================
	Desc: deconstructor
	===================================================*/

	void startSim();
	/*==================================================
	Desc: runs all processes within the array of queues
	Retn: none
	===================================================*/

private:
	struct process
	{
		int processID;
		int initialPriority;
		int currentPriority;
		int requiredTime;
		int initialTime;
		int startTime;
		int endTime;
		int elapsedTime;
		bool processRun;
	};

	queue<process> PriorityQueue[PRIORITY_QUEUE_SIZE]; // priority queue

	ifstream infile;

	int ourTime;

	bool readProcesses();
	/*==================================================
	Desc: read the processes from the input file
	Retn: true if successful, false otherwise
	===================================================*/

	void processQueues(string data, process& processes);
	/*==================================================
	Desc: insert process into appropriate queue
	Retn: none
	===================================================*/

	bool checkTime(process& processes);
	/*==================================================
	Desc: checks the task's runtime
	Retn: true if successful, false otherwise
	===================================================*/

	void ifRan(process& processes);
	/*==================================================
	Desc: checks if process has ran or needs to run
	Retn: none
	===================================================*/

	void updateProcess(process& processes);
	/*==================================================
	Desc: updates the queue priority of process
	Retn: none
	===================================================*/

	void printSim(process& processes);
	/*==================================================
	Desc: output statistics
	Retn: none
	===================================================*/
};