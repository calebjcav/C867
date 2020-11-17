#include <iostream>
#include <string>
#include <array>
#include "Degree.h"
#include "Roster.h"
#include <sstream>
#include "Student.h"

using namespace std;


Roster::Roster()
{
	for (int i = 0; i < 5; i++)
	{
		this->classRosterArray[i] = nullptr;
	}

}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete[] classRosterArray[i];
	}

	delete[] classRosterArray;
}
/*--------------------------------------------------------------------------------*/

Student* Roster::find(string studentId) {
	Student* retVal = nullptr;

	for (int i = 0; i < length; i++)
	{
		if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentId() == studentId) {
			retVal = this->classRosterArray[i];
		}
	}
	return retVal;

}

void Roster::LoadData(string studentInformation[], size_t len) {

	size_t i = 0;
	for (i = 0; i < len; i++)
	{
		this->add(
			this->ParseStudentData(studentInformation[i])
		);
	}
};

/*--------------------------------------------------------------------------------*/

void Roster::add(Student* student)
{

	this->classRosterArray[this->length++] = student;


};

Student* Roster::ParseStudentData(string studentInformation) {
	string studentData[9];

	int daysArray[3];

	int i = 0;
	string dataItem;
	istringstream data(studentInformation);

	while (getline(data, dataItem, ',')) {
		studentData[i++] = dataItem;
	}

	for (int j = 0; j < 3; j++) {
		daysArray[j] = stoi(studentData[j + 5]);
	}

	DegreeProgramEnum enumVal = DegreeProgramEnum::UNDECIDED;


	if (studentData[8] == "SECURITY") {
		enumVal = DegreeProgramEnum::SECURITY;
	}
	else if (studentData[8] == "SOFTWARE") {
		enumVal = DegreeProgramEnum::SOFTWARE;
	}
	else if (studentData[8] == "NETWORK") {
		enumVal = DegreeProgramEnum::NETWORK;
	}

	return new Student(
		studentData[0],
		studentData[1],
		studentData[2],
		studentData[3],
		stoi(studentData[4]),
		daysArray,
		enumVal
	);
};

/*--------------------------------------------------------------------------------*/

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgramEnum degreePrgrm) {
	/*that sets the instance variables from part D1 and updates the roster.*/
	int DaysArray[3] = { daysCourse1,daysCourse2,daysCourse3 };
	Student student = Student(studentId, firstName, lastName, emailAddress, age, DaysArray, degreePrgrm);
}

void Roster::remove(string studentId) {
	/*that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.*/
	for (int i = 0; i < this->length; i++)
	{
		if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentId() == studentId) {
			this->classRosterArray[i] = nullptr;
		}
	}
}
/*--------------------------------------------------------------------------------*/

void Roster::printAll() {
	/*that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.*/
	printf("Function Roster::printAll()\n");
	for (int i = 0; i < this->length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->print();
		}
	}
	printf("\n");
}

void Roster::printAverageDaysInCourse(string studentId) {

	/*that correctly prints a student’s average number of days in the three courses. The student is identified by the studentId parameter.*/
	printf("Function Roster::printAverageDaysInCourse(%s)\n", studentId.c_str());
	this->find(studentId)->printAverageDays();
	printf("\n");
}


void Roster::printInvalidEmails() {

	/*that verifies student email addresses and displays all invalid email addresses to the user.*/
	printf("Function Roster::printInvalidEmails()\n");
	for (int i = 0; i < this->length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->printInvalidEmail();
		}
	}
	printf("\n");
}

//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').


void Roster::printByDegreeProgram(DegreeProgramEnum degreePrgrm) {
	/*that prints out student information for a degree program specified by an enumerated type.*/
	printf("Function printByDegreeProgram(%s)\n", DegPrgrmString[(int)degreePrgrm].c_str());
	for (int i = 0; i < length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			if (this->classRosterArray[i]->getDegreePrgrm() == degreePrgrm) {
				this->classRosterArray[i]->print();
			}
		}
	}
	printf("\n");
}