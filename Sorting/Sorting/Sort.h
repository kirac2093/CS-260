/******************************************************
Code: Sorting
Name: Kira Corbett
Date: 6/1/2018
Desc: Class definitions for 3 different sorts for
	  various data types.
******************************************************/

#pragma once

const int ARRAY100_SIZE = 100;
const int ARRAY1000_SIZE = 1000;
const int ARRAY10000_SIZE = 10000;
const int ARRAY100000_SIZE = 100000;

class Sort
{
public:
	Sort();

	~Sort();

	void consoleOutput();

private:
	struct Dataset100
	{
		int inOrder[ARRAY100_SIZE];
		int reverseOrder[ARRAY100_SIZE];
		int randomOrder[ARRAY100_SIZE];

		// times to sort each routine inOrder
		float orderSelectionSortTime = 0;
		float orderInsertionSortTime = 0;
		float orderQuickSortTime = 0;
		
		// times to sort each routine reverseOrder
		float reverseSelectionSortTime = 0;
		float reverseInsertionSortTime = 0;
		float reverseQuickSortTime = 0;

		// times to sort each routine in randomOrder
		float randomSelectionSortTime = 0;
		float randomInsertionSortTime = 0;
		float randomQuickSortTime = 0;
	};

	struct Dataset1000
	{
		int inOrder[ARRAY1000_SIZE];
		int reverseOrder[ARRAY1000_SIZE];
		int randomOrder[ARRAY1000_SIZE];

		// times to sort each routine inOrder
		float orderSelectionSortTime = 0;
		float orderInsertionSortTime = 0;
		float orderQuickSortTime = 0;

		// times to sort each routine reverseOrder
		float reverseSelectionSortTime = 0;
		float reverseInsertionSortTime = 0;
		float reverseQuickSortTime = 0;

		// times to sort each routine in randomOrder
		float randomSelectionSortTime = 0;
		float randomInsertionSortTime = 0;
		float randomQuickSortTime = 0;
	};

	struct Dataset10000
	{
		int inOrder[ARRAY10000_SIZE];
		int reverseOrder[ARRAY10000_SIZE];
		int randomOrder[ARRAY10000_SIZE];

		// times to sort each routine inOrder
		float orderSelectionSortTime = 0;
		float orderInsertionSortTime = 0;
		float orderQuickSortTime = 0;

		// times to sort each routine reverseOrder
		float reverseSelectionSortTime = 0;
		float reverseInsertionSortTime = 0;
		float reverseQuickSortTime = 0;

		// times to sort each routine in randomOrder
		float randomSelectionSortTime = 0;
		float randomInsertionSortTime = 0;
		float randomQuickSortTime = 0;
	};

	struct Dataset100000
	{
		int inOrder[ARRAY100000_SIZE];
		int reverseOrder[ARRAY100000_SIZE];
		int randomOrder[ARRAY100000_SIZE];

		// times to sort each routine inOrder
		float orderSelectionSortTime = 0;
		float orderInsertionSortTime = 0;
		float orderQuickSortTime = 0;

		// times to sort each routine reverseOrder
		float reverseSelectionSortTime = 0;
		float reverseInsertionSortTime = 0;
		float reverseQuickSortTime = 0;

		// times to sort each routine in randomOrder
		float randomSelectionSortTime = 0;
		float randomInsertionSortTime = 0;
		float randomQuickSortTime = 0;
	};

	Dataset100* dataSet100 = new Dataset100;
	Dataset1000* dataSet1000 = new Dataset1000;
	Dataset10000* dataSet10000 = new Dataset10000;
	Dataset100000* dataSet100000 = new Dataset100000;

	void timedSelectionSort(int inOrder[], int reverseOrder[], int randomOrder[], int size);
	void timedInsertionSort(int order[], int reverse[], int random[], int size);
	void timedQuickSort(int order[], int reverse[], int random[], int size);

	void selectionSort(int list[], int length);
	void swap(int list[], int first, int second);
	
	void insertionSort(int inOrder[], int size);

	void quickSortR(int list[], int first, int last);
	int partition(int list[], int first, int last);

	void sortInOrder(int order[], int size);
	void sortReverseOrder(int reverse[], int size);
	void sortRandomOrder(int random[], int size);

	void outputResults();
};