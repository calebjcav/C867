#include <string>
#include "Roster.h"
#include "Degree.h"
#include <iostream>
using namespace std;


int main() {


	string studentData[] =

	{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Caleb,Caviness,caleb.j.cav@gmail.com,20,21,42,30,SOFTWARE"
	};
	const int numStudents = 5;
	Roster classRoster = Roster();

	cout << "C867 - Scripting and Programming Applications" << endl << "Language: C++" << endl << "Student ID: 000926487" << endl << "Name: Caleb Caviness" << endl << endl;;
	/*--------------------------------------------------------------------------------*/
	classRoster.LoadData(studentData, numStudents);

	classRoster.printAll();

	classRoster.printInvalidEmails();

	//loop through classRosterArray and for each element:

	for (int i = 0; i < numStudents; ++i) {
		if (classRoster.classRosterArray[i] != nullptr) {
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
		}
	}

	classRoster.printByDegreeProgram(DegreeProgramEnum::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	classRoster.~Roster();


	return 0;
}
/*--------------------------------------------------------------------------------*/