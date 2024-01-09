#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include "degree.h"

using namespace std;





class student {

private:
		string studentID = "";
		string firstName = "";
		string lastName = "";
		string emailAddress = "";
		int age = 0;
		int daysInCourseArray[3] = {0,0,0};
		DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;

public:
	const static int daysArraySize = 3;
	student();

	student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourseArray[daysArraySize], DegreeProgram degreeProgram);
	

	string studentIDGet();
	string firstNameGet();
	string lastNameGet();
	string emailAddressGet();
	int ageGet();
	int* daysInCourseGet();
	DegreeProgram degreeProgramGet();

	void studentIDSet(string studentID);
	void firstNameSet(string firstName);
	void lastNameSet(string lastName);
	void emaillAddressSet(string emailAddress);
	void ageSet(int);
	void daysInCourseSet(int daysInCourseArray[daysArraySize]);
	void degreeProgramSet(DegreeProgram degProgram);



	void print();

	~student();

};

