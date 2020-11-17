#pragma once
#include <iostream>
#include "Student.h" 
#include <string>
#include "Degree.h"

using namespace std;


class Roster
{
private:
    int length = 0;

public:

    Student* classRosterArray[5]; /*Array of pointers to hold the data provided in the “studentData Table.”*/

    Student* find(string studentId);
    void LoadData(string studentRecords[], size_t len);

    Student* ParseStudentData(string studentInformation);

    void add(Student* student);

    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgramEnum degreePrgrm);
    void remove(string studentId);

    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgramEnum degreePrgrm);

    Roster(/* args */);
    ~Roster();
};
