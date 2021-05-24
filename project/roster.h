//By Rafael Santos for WGU C867

#pragma once
#include "student.h"
#include <string>

class Roster {
private:
	Student *classRosterArray[5];


public:
	 void add(std::string studentID, 
		std::string firstName, 
		std::string lastName, 
		std::string emailAddress, 
		int age, 
		int daysInCourse1, 
		int daysInCourse2, 
		int daysInCourse3, 
		DegreeProgram degreeprogram);

	void initializeStudents();

	void remove(std::string studentID);

	void printAll();

	void printAverageDaysInCourse(std::string studentID);

	//Checks if student ID is valid
	bool rosterCheck(std::string studentId);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Destructor
	~Roster();



};




