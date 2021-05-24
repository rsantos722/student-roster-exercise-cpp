//By Rafael Santos for C867
#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"




void Roster::initializeStudents() {
	std::string tempStringArray[9]; //Iterates through the 9 data points in the string

	//String to parse into class roster
	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Rafael,Santos,rsant46@wgu.edu,22,20,30,15,SOFTWARE" };

	//Iterates through each string in the array above
	for (int studentIndex = 0; studentIndex <= 4; studentIndex++) {
		int stringLocation = 0; //Keeps track of location within the string
		for (int currentData = 0; currentData <= 8; currentData++) {
			std::string s; //Temporary string
			char currentChar;
			int stringLength = studentData[studentIndex].length();
			do { //Adds current character (from location in string) to the temporary string until a ',' is found
				currentChar = studentData[studentIndex].at(stringLocation);
				s += currentChar;
				stringLocation++;
			} while ((currentChar != ',') && (stringLocation < stringLength));
			//Remove ','

			s.erase(s.size() - 1);


			//Adds the temporary string data to my string array
			tempStringArray[currentData] = s;

		}

		//Checks for current degree. Workaround is to check 3rd letter of degree, which is different for each, and set enum based on it
		DegreeProgram currentDegree; //Initialize for complier sake
		//char degreeIdentifier = tempStringArray[8].at(2);

		if (tempStringArray[8] == "SECURIT") {
			currentDegree = SECURITY;
		}
		else if (tempStringArray[8] == "NETWOR") {
			currentDegree = NETWORK;
		}
		else if (tempStringArray[8] == "SOFTWAR") {
			currentDegree = SOFTWARE;
		}

		
		//Add data to roster
		Roster::add(
			tempStringArray[0], //Student ID
			tempStringArray[1],	//First Name
			tempStringArray[2],	//Last Name
			tempStringArray[3], //Email
			std::stoi(tempStringArray[4]), //Age (int)
			std::stoi(tempStringArray[5]), //Days in Course 1 (int)
			std::stoi(tempStringArray[6]), //Days in Course 2 (int)
			std::stoi(tempStringArray[7]), //Days in Course 3 (int)
			currentDegree);
	}

}

void Roster::remove(std::string studentID)  {

	int rosterId = (studentID.at(1) - '0') - 1;
	if (classRosterArray[rosterId]!=nullptr) {
		classRosterArray[rosterId] = nullptr;
		std::cout << "Student with ID " << studentID << " deleted successfully." << std::endl;
	}
	else {
		std::cout << "Error Deleting Student: Student does not exist." << std::endl;
	}


}


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	
	int daysInCourse[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	int rosterId = (studentID.at(1) - '0')-1; //Converts ID into Integer, used for array index
	this->classRosterArray[rosterId] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);

	 
}

void Roster::printAll() {

	//Go through each ID. If it is null, skip student
	for (int i = 0; i <= 4; i++) {
		if (classRosterArray[i]!= nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {

	int rosterId = (studentID.at(1) - '0');
	int daysInC1 = classRosterArray[rosterId]->getDaysInCourse1();
	int daysInC2 = classRosterArray[rosterId]->getDaysInCourse2();
	int daysInC3 = classRosterArray[rosterId]->getDaysInCourse3();

	int average = (daysInC1 + daysInC2 + daysInC3) / 3;
	//Calculate average for this student


	std::cout << "Average Days In Course for Student ID A" << (rosterId+1) << " is " << average << std::endl;
 
}

bool Roster::rosterCheck(std::string studentId) {

	int rosterId = (studentId.at(1) - '0') ; //Converts ID into Integer, used for array index

	//Check if the entry is blank (or if it is out of range
	if ((classRosterArray[rosterId] == NULL) || (rosterId > 4)) {
		std::cout << "Error: Student with ID " << studentId << " was not found." << std::endl;
		return false; //Return false if  the ID is invalid
	}
	else { return true; }
}

void Roster::printInvalidEmails() {

	for (int i = 0; i < 5; i++) { //Go through each student
		std::string emailToCheck = classRosterArray[i]->getEmailAddress(); //Obtain email
		if ((emailToCheck.find('@') != std::string::npos) && ((emailToCheck.find('.') != std::string::npos)) && ((emailToCheck.find(' ') == std::string::npos))) {
			break; //Checks if @, ., and no space is present
		} else {
			std::cout << "Invalid Email at Student ID " << classRosterArray[i]->getStudentId() << ": " << emailToCheck << std::endl;
		}
	}
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i < 5; i++) { //Go through each student
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}


//Destructor
Roster::~Roster() {

	delete classRosterArray;

}



