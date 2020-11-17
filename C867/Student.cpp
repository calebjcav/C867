
#include "Degree.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->degreePrgrm = DegreeProgramEnum::UNDECIDED;

	for (int i = 0; i < this->daysToCompArrayLength; i++)
	{
		this->daysToComp[i] = 0;
	}
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysToComp, DegreeProgramEnum degreePrgrm) {
	for (int x = 0; x < daysToCompArrayLength; x++) {
		this->daysToComp[x] = daysToComp[x];
	};
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->degreePrgrm = degreePrgrm;
}

Student::~Student()
{
}
/*--------------------------------------------------------------------------------*/
/*Getters*/

string Student::getStudentId()
{
	return this->studentId;
}

string Student::getFirstName()
{
	return this->firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

string Student::getEmailAddress()
{
	return this->emailAddress;
}

int Student::getAge()
{
	return this->age;
}

int* Student::getDaysToComp()
{
	return this->daysToComp;
}

DegreeProgramEnum Student::getDegreePrgrm()
{
	return this->degreePrgrm;
}
/*--------------------------------------------------------------------------------*/
/*Setters*/

void Student::setStudentId(string value)
{
	this->studentId = value;
	return;
}

void Student::setFirstName(string value)
{
	this->firstName = value;
	return;
}

void Student::setLastName(string value)
{
	this->lastName = value;
	return;
}

void Student::setEmailAddress(string value)
{
	this->emailAddress = value;
	return;
}

void Student::setAge(int value)
{
	this->age = value;
	return;
}

/*fixme*/
void Student::setDaysToComp(int* value)
{
	for (int i = 0; i < daysToCompArrayLength; i++) {
		this->daysToComp[i] = value[i];
	}
}

void Student::setDegreePrgrm(DegreeProgramEnum value)
{
	this->degreePrgrm = value;
}
/*--------------------------------------------------------------------------------*/
/*email validation*/

bool Student::validEmail() {
	int x = this->emailAddress.find("@");
	int y = this->emailAddress.rfind(".");
	int z = this->emailAddress.find(" ");
	return (z == -1 && y - x > 0 && y > y - x);

}

void Student::printInvalidEmail() {
	char buffer[200];
	string result;
	int x = sprintf_s(buffer, "%s|%s|%s|%s - Email Is Invalid\n", this->studentId.c_str(), this->firstName.c_str(), this->lastName.c_str(), this->emailAddress.c_str());
	result = buffer;
	cout << (this->validEmail() ? "" : result);
}

/*--------------------------------------------------------------------------------*/
int Student::AverageDaysInCourse() {
	int z = 0;
	for (int i = 0; i < this->daysToCompArrayLength; i++) {
		z += this->daysToComp[i];
	}
	return z / this->daysToCompArrayLength;
}

void Student::printAverageDays() {
	printf("Average Days In Course : %s\n", to_string(this->AverageDaysInCourse()).c_str());
}


void Student::print() {
	printf("%s\tFirst Name : %s\tLast Name : %s\tEmail : %s\tAge : %s\tdaysInCourse : {%s, %s, %s}\tDegree Program : %s\n", studentId.c_str(), firstName.c_str(), lastName.c_str(), emailAddress.c_str(), to_string(age).c_str(), to_string(daysToComp[0]).c_str(), to_string(daysToComp[1]).c_str(), to_string(daysToComp[2]).c_str(), DegPrgrmString[(int)degreePrgrm].c_str());

}
