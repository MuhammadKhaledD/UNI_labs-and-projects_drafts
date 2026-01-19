#pragma once

#include <iostream>
using namespace std;

class Student
{
	float grade;
public:
	Student(float g=0);

	void AddToGrades_No(float g);      // increment the grades and does NOT return (void)
	Student AddToGrades_Val(float g);  // increment the grades and return the calling objec "by value"
	Student& AddToGrades_Ref(float g); // increment the grades and return the calling objec "by reference"

	Student& ReturnLocal_By_Ref(); // return a local copy of the calling object by ref
	                               // this function will cause a problem in the main
	
	void Print();
};

