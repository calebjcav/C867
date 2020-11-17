#pragma once
#include <string>
#include <iostream>
#include "Degree.h"

using namespace std;

class Student
{
public:
    const static int daysToCompArrayLength = 3;

    Student();
    ~Student();

    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComp[], DegreeProgramEnum degreePrgrm);


    /*Getters declarations*/
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComp();
    DegreeProgramEnum getDegreePrgrm();

    /*Setters declarations*/
    void setStudentId(string value);
    void setFirstName(string value);
    void setLastName(string value);
    void setEmailAddress(string value);
    void setAge(int value);
    void setDaysToComp(int* value);
    void setDegreePrgrm(DegreeProgramEnum value);

    bool validEmail();
    void printInvalidEmail();

    int AverageDaysInCourse();

    void printAverageDays();

    void print();

private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age = 0;
    int daysToComp[daysToCompArrayLength];
    DegreeProgramEnum degreePrgrm;

};

