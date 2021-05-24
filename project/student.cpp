//By Rafael Santos for WGU C867


#include "degree.h"
#include <string>
#include "student.h"
#include <iostream>


//Getters
std::string Student::getStudentId() { return this->studentId; }
std::string Student::getFirstName() { return this->firstName; }
std::string Student::getLastName() { return this->lastName; }
std::string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int Student::getDaysInCourse1() { return this->daysInCourse[0]; }
int Student::getDaysInCourse2() { return this->daysInCourse[1]; }
int Student::getDaysInCourse3() { return this->daysInCourse[2]; }
DegreeProgram Student::getDegreeProgram() { return this->degreeprogram; }

//Setters
void Student::setStudentId(std::string newStudentId) { studentId = newStudentId; }
void Student::setFirstName(std::string newFirstName) { firstName = newFirstName; }
void Student::setLastName(std::string newLastName) { lastName = newLastName; }
void Student::setEmailAddress(std::string newEmailAddress) { emailAddress = newEmailAddress; }
void Student::setAge(int newAge) { age = newAge; }
void Student::setDaysInCourse1(int newDaysInC1) { daysInCourse[0] = newDaysInC1; }
void Student::setDaysInCourse2(int newDaysInC2) { daysInCourse[1] = newDaysInC2; }
void Student::setDaysInCourse3(int newDaysInC3) { daysInCourse[2] = newDaysInC3; }
void Student::setDegreeProgram(DegreeProgram newDegreeProgram) { degreeprogram = newDegreeProgram; }

//Prints out specific student data
void Student::print() {

	std::string degreeString;
	switch (degreeprogram) {
	case SECURITY:
		degreeString = "Degree Program: Security.";
		break;
	case NETWORK:
		degreeString = "Degree Program: Network.";
		break;
	case SOFTWARE:
		degreeString = "Degree Program: Software.";
		break;
	}

	//Output, formatted as in instructions
	std::cout
		<< this->studentId <<
		"\t First Name: " << this->firstName <<
		"\t Last Name:" << this->lastName <<
		"\t Age: " << std::to_string(this->age) <<
		"\t daysInCourse: {" << std::to_string(this->daysInCourse[0]) << ", " << std::to_string(this->daysInCourse[1]) << ", " << std::to_string(this->daysInCourse[2]) << "} \t"
		<< degreeString << std::endl;

}

Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeprogram) {
	
	this->setStudentId(studentId);
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setEmailAddress(emailAddress);
	this->setAge(age);
	this->setDaysInCourse1(daysInCourse[0]);
	this->setDaysInCourse2(daysInCourse[1]);
	this->setDaysInCourse3(daysInCourse[2]);
	this->setDegreeProgram(degreeprogram);

}


Student::~Student() {}



