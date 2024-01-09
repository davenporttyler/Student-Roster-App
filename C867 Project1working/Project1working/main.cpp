#include "student.h"
#include "roster.h"
#include "degree.h"

#include <iostream>
#include <sstream>
#include <regex>



using namespace std;




int main() {

    const int numStudents = 5;

    const string studentData[numStudents] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Tyler,Davenport,tdave68@wgu.edu,28,17,20,52,SOFTWARE"
    };

    //Title
    cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "WGU Student ID: 009202780" << endl;
    cout << "WGU Student Name: Tyler Davenport" << endl << endl << endl;


    roster roster;


    //Show Roster
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all student data : " << endl;
    roster.printAll();

    //Displaying students with invalid email addresses
    cout << "Displaying students with invalid email addresses:" << endl;
    roster.printInvalidEmails();
    cout << endl;

    //Displaying average number of days to complete the courses
    for (int i = 0; i < numStudents; i++) {
        cout << "Average number of days to complete 3 courses: " << '\t';
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->studentIDGet());

    }

   
    //Displaying by degree program
    for (int i = 0; i < 3; i++) {
        cout << "Displaying by degree program: " << endl;
        roster.printByDegreeProgram((DegreeProgram)i);

    }

    //Remove student ID A3 
    cout << "Removing student with ID: A3" << endl;
    cout << endl;
    roster.removeStudent("A3");
    
    //Checking that A3 was removed
    roster.removeStudent("A3");
    cout << endl;

    system("pause");
    cout << "Program Finished Executing" << endl;




    return 0;





}