/**************************************************************
Code: Source.cpp
Name: Kira Corbett
Date: 5/18/18
Desc: create a hash function to generate a hash from a string,
	  test, and evaluate results.
**************************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <ostream>
#include <string>
#include <math.h>

using namespace std;

// constants
const int MAX_WORDS = 45401;


// function prototypes
string toLower(string upperCase);
int hashFunc(string myString, int myArray[]);
float numOfCollisions(int hashMap[]);
void mapResults(int hashMap[]);

int main()
{
	int hashMap[MAX_WORDS] = {};
	int i = 0;
	char wordFromLine = {};

	string word = "";
	ifstream infile;
	infile.open("words.txt");

	// read each line of input file
	if (!infile)
	{
		cout << "Error! The file cannot load." << endl;
	}

	while (infile >> word)
	{
		word = toLower(word); // convert it all to lowercase
		//i = myhash(word) % MAX_WORDS;
		i = hashFunc(word, hashMap) % MAX_WORDS; // create a hash from each word
		hashMap[i]++; // increment bucket
	}

	infile.close();

	mapResults(hashMap);
	cout << "CS 260: A6 hashing, Kira Corbett, " << numOfCollisions(hashMap) << "%" << endl;

	cin.get();
	cin.ignore();

	return 0;
}

/*===========================================================================
Name: toLower
Desc: converts input word to all lower case
Args: enteredString (string)
Retn: enteredString in lowercase (string)
===========================================================================*/
string toLower(string enteredString)
{
	for (int i = 0; i < enteredString.length(); i++)
	{
		enteredString[i] = tolower(enteredString[i]);
	}

	return enteredString;
}

/*===========================================================================
Name: hashFun
Desc: creates a hash from each word in words.txt
Args: word (string), myArray[]
Retn: hash (int)
===========================================================================*/
int hashFunc(string word, int myArray[]) 
{
	int hash = 1;
	char ch;
	double rHash = 1;
	double bigPrime = 131071;

	for (int i = 0; i < word.length(); i++)
	{
		ch = word[i];
		if (myArray[i] != NULL)
		{
			rHash *= ch * (i + 1001);
		}
		else
		{
			rHash *= ch * (i + 1000);
		}
	}

	// randomize integer placement with large numbers
	rHash = fmod(rHash, bigPrime);
	hash = rHash;

	return hash;
}

/*===========================================================================
Name: numOfCollisions
Desc: calculate percentage in hashes that resulted in collisions
Args: hashMap[]
Retn: collisions (float)
===========================================================================*/
float numOfCollisions(int hashMap[])
{
	float collisions = 0;

	for (int i = 0; i < MAX_WORDS; i++)
	{
		// if values at specific index are greater than 1
		if (hashMap[i] > 1)
		{
			// collisions occurred; subtract 1 because 1 value is there by a perfect hash
			collisions += hashMap[i] - 1;
		}
	}

	return (collisions / MAX_WORDS) * 100;
}

/*===========================================================================
Name: mapResults
Desc: write contents of array to a spreadsheet
Args: hash[]
Retn: none
===========================================================================*/
void mapResults(int hash[])
{
	ofstream outfile;
	outfile.open("hashresults.csv");

	if (!outfile)
	{
		cout << "Error! Cannot write to file!" << endl;
	}

	for (int i = 0; i < MAX_WORDS; i++)
	{
		//if (hash[i] != 0)
		{
			outfile << hash[i] << '\n';
			//outfile << hash[i] << ',';
		}
	}

	outfile << hash[MAX_WORDS];

	outfile.close();
}
