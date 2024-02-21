#pragma once
#include <malloc.h>
#include <stdio.h>
#include <Windows.h>

const int CODE_PHYSICS = 1;
const int CODE_HIGHER_MATH = 2;
const int CODE_COMPUTER_SCIENCE = 3;

struct RecordBook
{
	int physicsMark;
	int higherMathMark;
	int computerScienceMark;
	double middleMark;
};

struct Student
{
	char surname[256];
	char inicials[256];
	int yearOfBirth;
	int yearOfAdmission;
	RecordBook studentsRecordBook;
};

extern void russianAlphabet();

extern void calculateMiddleMark(int index);

extern void allocationMemory();
extern void releaseMemory();

extern void readFromFile();
extern void writeToFile();

extern void addStudent();
extern void printStudents();
extern void printStudentsWhoHasMarksThree();
extern void updateStudent();
extern void deleteStudent();
extern void sortStudent();

extern char* inputSurname();
extern char* inputInitials();
extern int inputYearOfBirth();
extern int inputYearOfAdmission(int yearOfBirth);

extern int inputMark(int codeOfDiscipline);

extern int inputIntOptions();

extern void deleteBeginsAndEndsSpaces(char* str);


