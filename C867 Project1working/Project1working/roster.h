#pragma once
#include "student.h"

#include <iostream>
#include <vector>

using namespace std;




class roster{

private:
	int lastPosition = -1;
	
	const static int numberInRoster = 5;

public:
	vector<string> parsedStudentData;

	student* classRosterArray[numberInRoster] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	void parse(string row);

	void addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, 
		int daysInCourse0, int daysInCourse1, int daysInCourse2, DegreeProgram degProgram);

	void printAll();

	void printByDegreeProgram(DegreeProgram degProgram);

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void removeStudent(string studentID);



	//Deconstructor
	~roster();


};

