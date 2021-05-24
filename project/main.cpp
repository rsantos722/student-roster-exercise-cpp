//By Rafael Santos for C867

#include <iostream>
#include "roster.h"

int main() {

	//Print name
	std::cout << "Student Roster Program" << std::endl;
	std::cout << "By Rafael Santos" << std::endl << std::endl;

	Roster *classRoster = new Roster;

	classRoster->initializeStudents();
	classRoster->printAll();
	classRoster->printInvalidEmails();

	//loop through classRosterArray and for each element:
	for (int i = 0; i < 5; i++) {
		std::string studentId = "A";
		studentId += (i + '0');
		classRoster->printAverageDaysInCourse(studentId);
	}


	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.

	classRoster->~Roster(); //Destructor
	std::cin.get();		//Avoid closing terminal immediately
	return 0;
}