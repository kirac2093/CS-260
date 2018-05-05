/*****************************************************
Name: SchedulerSimTest.cpp
Code: Kira Corbett
Date: 4/26/18
Desc: Practice working with queues, creating a 
	  simulation, and learn about process scheduling.
******************************************************/

#include <iostream>
#include "SchedulerSim.h"

using namespace std;

int main()
{
	SchedulerSim sim;

	cout << "Author: Kira Corbett" << endl << endl;

	sim.startSim();

	cin.get();
	cin.ignore();

	return 0;
}
