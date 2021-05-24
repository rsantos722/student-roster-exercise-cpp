//By Rafael Santos for WGU C867


#pragma once
#include "degree.h"
#include <string>


//Class definition
class Student {

private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeprogram;

public:
	//constructor
	Student(
		std::string studentId,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse[3],
		DegreeProgram degreeprogram
	);
	
	//Destructor
	~Student();

	//Getters
	std::string getStudentId();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int getDaysInCourse1();
	int getDaysInCourse2();
	int getDaysInCourse3();
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentId(std::string studentId);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysInCourse1(int daysInC1);
	void setDaysInCourse2(int daysInC2);
	void setDaysInCourse3(int daysInC3);
	void setDegreeProgram(DegreeProgram degreeprogram);


	//Functions
	void print();

};



