/******************************************************
Code: Sorting
Name: Kira Corbett
Date: 6/1/2018
Desc: Class implementations for 3 different sorts for
	  various data sets.
******************************************************/

#include "Sort.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ostream>

Sort::Sort()
{
	// setup the sort data sets 100
	sortInOrder(dataSet100->inOrder, ARRAY100_SIZE);
	sortReverseOrder(dataSet100->reverseOrder, ARRAY100_SIZE);
	sortRandomOrder(dataSet100->randomOrder, ARRAY100_SIZE);

	// setup the sort data sets 1000
	sortInOrder(dataSet1000->inOrder, ARRAY1000_SIZE);
	sortReverseOrder(dataSet1000->reverseOrder, ARRAY1000_SIZE);
	sortRandomOrder(dataSet1000->randomOrder, ARRAY1000_SIZE);

	// setup the sort data sets 10000
	sortInOrder(dataSet10000->inOrder, ARRAY10000_SIZE);
	sortReverseOrder(dataSet10000->reverseOrder, ARRAY10000_SIZE);
	sortRandomOrder(dataSet10000->randomOrder, ARRAY10000_SIZE);

	// setup the sort data sets 100000
	sortInOrder(dataSet100000->inOrder, ARRAY100000_SIZE);
	sortReverseOrder(dataSet100000->reverseOrder, ARRAY100000_SIZE);
	sortRandomOrder(dataSet100000->randomOrder, ARRAY100000_SIZE);
}

Sort::~Sort()
{

}

void Sort::consoleOutput()
{
	std::cout << "Selection Sort, 100, 1000, 10000" << std::endl;

	timedSelectionSort(dataSet100->inOrder, dataSet100->reverseOrder, dataSet100->randomOrder, ARRAY100_SIZE);
	timedSelectionSort(dataSet1000->inOrder, dataSet1000->reverseOrder, dataSet1000->randomOrder, ARRAY1000_SIZE);
	timedSelectionSort(dataSet10000->inOrder, dataSet10000->reverseOrder, dataSet10000->randomOrder, ARRAY10000_SIZE);
	timedSelectionSort(dataSet100000->inOrder, dataSet100000->reverseOrder, dataSet100000->randomOrder, ARRAY100000_SIZE);

	std::cout << dataSet100->orderSelectionSortTime << ", " << dataSet1000->orderSelectionSortTime << ", "
		<< dataSet10000->orderSelectionSortTime << ", " << dataSet100000->orderSelectionSortTime << std::endl << std::endl;

	timedInsertionSort(dataSet100->inOrder, dataSet100->reverseOrder, dataSet100->randomOrder, ARRAY100_SIZE);
	timedInsertionSort(dataSet1000->inOrder, dataSet1000->reverseOrder, dataSet1000->randomOrder, ARRAY1000_SIZE);
	timedInsertionSort(dataSet10000->inOrder, dataSet10000->reverseOrder, dataSet10000->randomOrder, ARRAY10000_SIZE);
	timedInsertionSort(dataSet100000->inOrder, dataSet100000->reverseOrder, dataSet100000->randomOrder, ARRAY100000_SIZE);

	std::cout << dataSet100->orderInsertionSortTime << ", " << dataSet1000->orderInsertionSortTime << ", "
		<< dataSet10000->orderInsertionSortTime << ", " << dataSet100000->orderInsertionSortTime << std::endl << std::endl;

	timedQuickSort(dataSet100->inOrder, dataSet100->reverseOrder, dataSet100->randomOrder, ARRAY100_SIZE);
	timedQuickSort(dataSet1000->inOrder, dataSet1000->reverseOrder, dataSet1000->randomOrder, ARRAY1000_SIZE);
	timedQuickSort(dataSet10000->inOrder, dataSet10000->reverseOrder, dataSet10000->randomOrder, ARRAY10000_SIZE);
	timedQuickSort(dataSet100000->inOrder, dataSet100000->reverseOrder, dataSet100000->randomOrder, ARRAY100000_SIZE);

	std::cout << dataSet100->orderQuickSortTime << ", " << dataSet1000->orderQuickSortTime << ", "
		<< dataSet10000->orderQuickSortTime << ", " << dataSet100000->orderQuickSortTime << std::endl << std::endl;

	std::cout << "Outputting results..." << std::endl;
	outputResults();

	std::cout << "Sorting completed." << std::endl;

}

/*================================  Timed Sorting Routines  =============================
Functions: timedSelectionSort, timedInsertionSort, timedQuickSort
Description: times the various sorting routines
==========================================================================================*/
void Sort::timedSelectionSort(int inOrder[], int reverseOrder[], int randomOrder[], int size)
{
	float timeInOrder;
	float timeReverse;
	float timeRandom;

	clock_t time;

	// in order
	std::cout << "In order..." << std::endl;
	time = clock();
	selectionSort(inOrder, size);
	/*time = clock() - (time);
	time = (float)time / CLOCKS_PER_SEC;*/
	timeInOrder = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// reverse order
	std::cout << "Reverse order..." << std::endl;
	time = clock();
	selectionSort(reverseOrder, size);
	timeReverse = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// random order
	std::cout << "Random order..." << std::endl << std::endl;
	time = clock();
	selectionSort(randomOrder, size);
	timeRandom = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	switch (size)
	{
	case 100:
		dataSet100->orderSelectionSortTime = timeInOrder;
		dataSet100->reverseSelectionSortTime = timeReverse;
		dataSet100->randomSelectionSortTime = timeRandom;

		sortInOrder(dataSet100->inOrder, size);
		sortReverseOrder(dataSet100->reverseOrder, size);
		sortRandomOrder(dataSet100->randomOrder, size);
		break;
	case 1000:
		dataSet1000->orderSelectionSortTime = timeInOrder;
		dataSet1000->reverseSelectionSortTime = timeReverse;
		dataSet1000->randomSelectionSortTime = timeRandom;

		sortInOrder(dataSet1000->inOrder, size);
		sortReverseOrder(dataSet1000->reverseOrder, size);
		sortRandomOrder(dataSet1000->randomOrder, size);
		break;
	case 10000:
		dataSet10000->orderSelectionSortTime = timeInOrder;
		dataSet10000->reverseSelectionSortTime = timeReverse;
		dataSet10000->randomSelectionSortTime = timeRandom;

		sortInOrder(dataSet10000->inOrder, size);
		sortReverseOrder(dataSet10000->reverseOrder, size);
		sortRandomOrder(dataSet10000->randomOrder, size);
		break;
	case 100000:
		dataSet100000->orderSelectionSortTime = timeInOrder;
		dataSet100000->reverseSelectionSortTime = timeReverse;
		dataSet100000->randomSelectionSortTime = timeRandom;

		sortInOrder(dataSet100000->inOrder, size);
		sortReverseOrder(dataSet100000->reverseOrder, size);
		sortRandomOrder(dataSet100000->randomOrder, size);
		break;
	}
}

void Sort::timedInsertionSort(int order[], int reverse[], int random[], int size)
{
	float timeInOrder;
	float timeReverse;
	float timeRandom;

	clock_t time;

	// in order
	std::cout << "In order..." << std::endl;
	time = clock();
	insertionSort(order, size);
	timeInOrder = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// reverse order
	std::cout << "Reverse order..." << std::endl;
	time = clock();
	insertionSort(reverse, size);
	timeReverse = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// random order
	std::cout << "Random order..." << std::endl << std::endl;
	time = clock();
	insertionSort(random, size);
	timeRandom = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	switch (size)
	{
	case 100:
		dataSet100->orderInsertionSortTime = timeInOrder;
		dataSet100->reverseInsertionSortTime = timeReverse;
		dataSet100->randomInsertionSortTime = timeRandom;

		sortInOrder(dataSet100->inOrder, size);
		sortReverseOrder(dataSet100->reverseOrder, size);
		sortRandomOrder(dataSet100->randomOrder, size);
		break;
	case 1000:
		dataSet1000->orderInsertionSortTime = timeInOrder;
		dataSet1000->reverseInsertionSortTime = timeReverse;
		dataSet1000->randomInsertionSortTime = timeRandom;

		sortInOrder(dataSet1000->inOrder, size);
		sortReverseOrder(dataSet1000->reverseOrder, size);
		sortRandomOrder(dataSet1000->randomOrder, size);
		break;
	case 10000:
		dataSet10000->orderInsertionSortTime = timeInOrder;
		dataSet10000->reverseInsertionSortTime = timeReverse;
		dataSet10000->randomInsertionSortTime = timeRandom;

		sortInOrder(dataSet10000->inOrder, size);
		sortReverseOrder(dataSet10000->reverseOrder, size);
		sortRandomOrder(dataSet10000->randomOrder, size);
		break;
	case 100000:
		dataSet100000->orderInsertionSortTime = timeInOrder;
		dataSet100000->reverseInsertionSortTime = timeReverse;
		dataSet100000->randomInsertionSortTime = timeRandom;

		sortInOrder(dataSet100000->inOrder, size);
		sortReverseOrder(dataSet100000->reverseOrder, size);
		sortRandomOrder(dataSet100000->randomOrder, size);
		break;
	}
}

void Sort::timedQuickSort(int order[], int reverse[], int random[], int size)
{
	float timeInOrder;
	float timeReverse;
	float timeRandom;

	clock_t time;

	// in order
	std::cout << "In order..." << std::endl;
	time = clock();
	quickSortR(order, 0, size - 1);
	timeInOrder = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// reverse order
	std::cout << "Reverse order..." << std::endl;
	//time = 0;
	time = clock();
	quickSortR(reverse, 0, size - 1);
	timeReverse = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	// random order
	std::cout << "Random order..." << std::endl << std::endl;
	time = clock();
	quickSortR(random, 0, size - 1);
	timeRandom = static_cast<float>(clock() - time) / CLOCKS_PER_SEC;

	switch (size)
	{
	case 100:
		dataSet100->orderQuickSortTime = timeInOrder;
		dataSet100->reverseQuickSortTime = timeReverse;
		dataSet100->randomQuickSortTime = timeRandom;

		sortInOrder(dataSet100->inOrder, size);
		sortReverseOrder(dataSet100->reverseOrder, size);
		sortRandomOrder(dataSet100->randomOrder, size);
		break;
	case 1000:
		dataSet1000->orderQuickSortTime = timeInOrder;
		dataSet1000->reverseQuickSortTime = timeReverse;
		dataSet1000->randomQuickSortTime = timeRandom;

		sortInOrder(dataSet1000->inOrder, size);
		sortReverseOrder(dataSet1000->reverseOrder, size);
		sortRandomOrder(dataSet1000->randomOrder, size);
		break;
	case 10000:
		dataSet10000->orderQuickSortTime = timeInOrder;
		dataSet10000->reverseQuickSortTime = timeReverse;
		dataSet10000->randomQuickSortTime = timeRandom;

		sortInOrder(dataSet10000->inOrder, size);
		sortReverseOrder(dataSet10000->reverseOrder, size);
		sortRandomOrder(dataSet10000->randomOrder, size);
		break;
	case 100000:
		dataSet100000->orderQuickSortTime = timeInOrder;
		dataSet100000->reverseQuickSortTime = timeReverse;
		dataSet100000->randomQuickSortTime = timeRandom;

		sortInOrder(dataSet100000->inOrder, size);
		sortReverseOrder(dataSet100000->reverseOrder, size);
		sortRandomOrder(dataSet100000->randomOrder, size);
		break;
	}
}

// =============================================== Sorting Algorithms ===============================================

/**************************************************
Func: selectionSortHelper
Desc: selection sort algorithm (finds min. element)
Args: arr[] (int), size (int)
Retn: none
Note: pseudocode adaptions from GeeksforGeeks
**************************************************/
void Sort::selectionSort(int arr[], int size)
{
	int minIndex;

	// update boundary point of unsorted subarray
	for (int i = 0; i < size; i++)
	{
		minIndex = i;

		// identify min. element of unsorted array
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		swap(arr, i, minIndex);
	}
}

/**************************************************************
Func: swap
Desc: moves the smallest element to beginning of unsorted list
Args: arr[] (int), first (int), second (int)
Retn: none
Note: adaptions from C++ programming D.S. Malik
**************************************************************/
void Sort::swap(int arr[], int first, int second)
{
	int temp;

	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

/********************************************************
Func: insertionSort
Desc: insertion sort algorithm (sorts like playing cards)
Args: arr[] (int), size (int)
Retn: none
Note: pseudocode adaptions from D.S. Malik
*******************************************************/
void Sort::insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			// copy list into temp & initialize i
			int temp = arr[i];
			int keyLocation = i;

			do
			{
				// do copy list and decrement location while the key is > 0 
				// & element is one less spot than temp
				arr[keyLocation] = arr[keyLocation - 1];
				keyLocation--;
			} while (keyLocation > 0 && arr[keyLocation - 1] > temp);

			arr[keyLocation] = temp;
		}
	}
}

/********************************************************
Func: quickSort
Desc: quick sort algorithm (divide & conquer)
Args: arr[] (int), first (int), last (int)
Retn: none
Note: pseudocode adaptions - D.S. Malik + GeeksforGeeks
*******************************************************/
void Sort::quickSortR(int arr[], int first, int last)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(arr, first, last);
		quickSortR(arr, first, pivot - 1);
		quickSortR(arr, pivot + 1, last);
	}
}

/********************************************************
Func: partition
Desc: key process to quickSort
Args: arr[] (int), first (int), last (int)
Retn: none
Note: pseudocode adaptions GeeksforGeeks
********************************************************/
int Sort::partition(int arr[], int first, int last)
{
	int pivot;
	int smallIndex;

	swap(arr, first, (first + last) / 2);

	pivot = arr[first];
	smallIndex = first;

	for (int i = first + 1; i <= last; i++)
	{
		if (arr[i] < pivot)
		{
			smallIndex++;
			swap(arr, smallIndex, i);
		}
	}
	swap(arr, first, smallIndex);
	return smallIndex;
}

// ================================================ Dataset Sorting Orders ======================================
void Sort::sortInOrder(int order[], int size)
{
	for (int i = 0; i < size; i++)
	{
		order[i] = i;
	}
}

void Sort::sortReverseOrder(int reverse[], int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		reverse[i - 1] = size - i;
	}
}

void Sort::sortRandomOrder(int random[], int size)
{
	srand(42);

	for (int i = 0; i < size; i++)
	{
		random[i] = rand() % size;
	}
}

/********************************************************
Func: outputResults
Desc: outputs timed results to .csv file
Args: none
Retn: none
*******************************************************/
void Sort::outputResults()
{
	std::ofstream outfile;
	outfile.open("sortingResults.csv");

	if (!outfile)
	{
		std::cout << "Error! Cannot write to file!" << std::endl;
	}

	outfile << "Selection Sort, 100, 1000, 10000, 100000" << std::endl;
	outfile << ", " << dataSet100->orderSelectionSortTime << ", " << dataSet1000->orderSelectionSortTime << ", "
			<< dataSet10000->orderSelectionSortTime << ", " << dataSet100000->orderSelectionSortTime << std::endl << std::endl;

	outfile << "Insertion Sort, 100, 1000, 10000, 100000" << std::endl;
	outfile << ", " << dataSet100->orderInsertionSortTime << ", " << dataSet1000->orderInsertionSortTime << ", "
		<< dataSet10000->orderInsertionSortTime << ", " << dataSet100000->orderInsertionSortTime << std::endl << std::endl;

	outfile << "Quick Sort, 100, 1000, 10000, 100000" << std::endl;
	outfile << ", " << dataSet100->orderQuickSortTime << ", " << dataSet1000->orderQuickSortTime << ", "
		<< dataSet10000->orderQuickSortTime << ", " << dataSet100000->orderQuickSortTime << std::endl << std::endl;

	outfile.close();

	std::cout << "Output completed." << std::endl;
}