#include<iostream>

#include "student.h"
#include "roster.h"

#include <regex>



using namespace std;




//Parse Function
void roster::parse(string row) {

	regex regex("\\,");
	vector<string> splitter(
		sregex_token_iterator(row.begin(), row.end(), regex, -1), sregex_token_iterator()

	);
	DegreeProgram degProgram = DegreeProgram::SOFTWARE;
	if (splitter.at(8).back() == 'K') degProgram = DegreeProgram::NETWORK;
	if (splitter.at(8).back() == 'Y') degProgram = DegreeProgram::SECURITY;
	addStudent(splitter.at(0), splitter.at(1), splitter.at(2), splitter.at(3), stoi(splitter.at(4)), stoi(splitter.at(5)), 
		stoi(splitter.at(6)), stoi(splitter.at(7)), degProgram);

}

//Add Student Function
void roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse0, int daysInCourse1, int daysInCourse2, DegreeProgram degreeProgram) {

	int daysInCourseArray[] = { daysInCourse0, daysInCourse1, daysInCourse2 };

	classRosterArray[++lastPosition] = new student(studentID, firstName, lastName, emailAddress, age,
		daysInCourseArray, degreeProgram);

}

//Print All Function
void roster::printAll() {
	cout << "Print all student rosters." << endl;
	for (int i = 0; i <= roster::lastPosition; i++) {
		classRosterArray[i]->print();

	}
	cout << endl;
}

//Print Average Days In Course Function
void roster::printAverageDaysInCourse(string studentID) {
	cout << "Student ID: " << studentID << "\t";
	for (int i = 0; i <= roster::lastPosition; i++) {
		if (classRosterArray[i]->studentIDGet() == studentID) {
			cout << (classRosterArray[i]->daysInCourseGet()[0] + classRosterArray[i]->daysInCourseGet()[1] +
				classRosterArray[i]->daysInCourseGet()[2]) / 3.0 << " Days" << endl;
		}
	}
	cout << endl;
}


//Print By Degree Program Function (Software Only, not Loop through All)
void roster::printByDegreeProgram(DegreeProgram degProgram) {
	for (int i = 0; i <= roster::lastPosition; i++) {
		if (classRosterArray[i]->degreeProgramGet() == degProgram) {

			if(degProgram == DegreeProgram::SOFTWARE)
				classRosterArray[i]->print();
		}
			

	}
	cout << endl;
}

//Print Invalid Email Function
void roster::printInvalidEmails() {

	for (int i = 0; i <= roster::lastPosition; i++) {

		string emailAddress = roster::classRosterArray[i]->emailAddressGet();
		if (emailAddress.find('.') == string::npos || emailAddress.find('@') == string::npos || emailAddress.find(' ') != string::npos)
			cout << emailAddress << " is Invalid!" << endl;

	}
}

//Remove Student Function
void roster::removeStudent(string studentID) {

	bool success = false;
	for (int i = 0; i <= roster::lastPosition; i++) {

		if (classRosterArray[i]->studentIDGet() == studentID) {

			success = true;
			student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numberInRoster - 1];
			classRosterArray[numberInRoster - 1] = temp;
			roster::lastPosition--;
		}		
	}
	if (success) {
		cout << "Student " << studentID << " Removed From Roster.";
		cout << endl;
		this->printAll();
	}
	else cout << "Student " << studentID << " Not Found.";
	cout << endl;

}

//Roster Destructor
roster::~roster() {
	cout << "Roster Desctuctor started....." << endl;

	for (int i = 0; i < numberInRoster; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Roster Destructor Finished. Student Info Destroyed." << endl;

}

