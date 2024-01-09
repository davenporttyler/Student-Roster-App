#include <iostream>
#include "student.h"

using namespace std;

//Empty Student Constructor
student::student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourseArray[daysArraySize];
	this->degreeProgram = DegreeProgram::SOFTWARE;

}

//Main Student Constructor
student::student(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourseArray[daysArraySize], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourseArray[i] = daysInCourseArray[i];
	this->degreeProgram = degreeProgram;
}

//Student Destructor
student::~student() {

}


//Getter Fuctions
string student::studentIDGet() {
	return this->studentID;
}
string student::firstNameGet() {
	return this->firstName;
}
string student::lastNameGet() {
	return this->lastName;
}
string student::emailAddressGet() {
	return this->emailAddress;
}
int student::ageGet() {
	return this->age;
}
int* student::daysInCourseGet() {
	return this->daysInCourseArray;
}
DegreeProgram student::degreeProgramGet() {
	return this->degreeProgram;
}


//Setter Functions
void student::studentIDSet(string studentID) {
	this->studentID = studentID;
}
void student::firstNameSet(string firstName) {
	this->firstName = firstName;
}
void student::lastNameSet(string lastName) {
	this->lastName = lastName;
}
void student::emaillAddressSet(string emailAddress) {
	this->emailAddress = emailAddress;
}
void student::ageSet(int age) {
	this->age = age;
}
void student::daysInCourseSet(int daysInCourseArray[daysArraySize]) {
	this->daysInCourseArray[0] = daysInCourseArray[0];
	this->daysInCourseArray[1] = daysInCourseArray[1];
	this->daysInCourseArray[2] = daysInCourseArray[2];
}
void student::degreeProgramSet(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


//Student Print Function
void student::print() {
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->daysInCourseArray[0] << '\t';
	cout << this->daysInCourseArray[1] << '\t';
	cout << this->daysInCourseArray[2] << '\t';
	cout << degreeProgramString[(int)this->degreeProgram] << '\t';
	cout << endl;



}