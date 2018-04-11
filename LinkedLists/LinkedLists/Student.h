/************************************************
Name: Student.h
Code: Kira Corbett
Date: 4/10/18
Desc: Student class
************************************************/

#pragma once
#include <iostream>
#include <string>

class Student {
public:
	//constructor
	Student(const std::string name = "anonymous", char letterGrade = 'W')
	{
		this->name = name;
		this->letterGrade = letterGrade;
	}

	//operator overloads
	friend bool operator== (const Student& stu1, const Student& stu2)
	{
		if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
			return true;
		else
			return false;
	}

	friend bool operator!=  (const Student& stu1, const Student& stu2)
	{
		if (stu1.name != stu2.name && stu1.letterGrade != stu2.letterGrade)
			return true;
		else
			return false;
	}

	friend std::ostream& operator<< (std::ostream& stream, const Student& student)
	{
		stream << student.name;
		stream << " (" << student.letterGrade << ") ";
		return stream;
	}

private:
	std::string name;
	char letterGrade;
};
