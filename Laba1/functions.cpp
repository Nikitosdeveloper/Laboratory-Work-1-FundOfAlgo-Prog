#include "Header.h"

static Student* students;
int countStudents = 0;

extern void russianAlphabet() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

extern void calculateMiddleMark(int studentIndex)
{
	students[studentIndex].studentsRecordBook.middleMark = (double)(
		students[studentIndex].studentsRecordBook.computerScienceMark +
		students[studentIndex].studentsRecordBook.higherMathMark +
		students[studentIndex].studentsRecordBook.physicsMark
	) / 3;
}

extern void allocationMemory()
{
	students = (Student*)realloc(students, countStudents * sizeof(Student));
}

extern void releaseMemory()
{
	free(students);
}

extern void readFromFile() {
	FILE* file;
	fopen_s(&file, "Students.txt", "r");
	if (file != NULL) {

		fscanf_s(file, "���������� ���������: %d\n", &countStudents);

		allocationMemory();

		for (register int i = 0; i < countStudents; i++) {
			fscanf_s(file, "������� � ��������: %s %s\n", students[i].surname,sizeof(students[i].surname), students[i].inicials, sizeof(students[i].surname));
			fscanf_s(file, "��� ��������: %d\n", &students[i].yearOfBirth);
			fscanf_s(file, "��� ����������� � �����: %d\n", &students[i].yearOfAdmission);
			fscanf_s(file, "������ �� ������: %d\n", &students[i].studentsRecordBook.physicsMark);
			fscanf_s(file, "������ �� ������ ����������: %d\n", &students[i].studentsRecordBook.higherMathMark);
			fscanf_s(file, "������ �� �����������: %d\n", &students[i].studentsRecordBook.computerScienceMark);
			calculateMiddleMark(i);
		}

		fclose(file);
		printf("���������� � ��������� ������� ��������� �� �����\n");
	}
	else {
		printf("��������� ����������� ������ =(\n");
	}
}

extern void writeToFile() {
	FILE* file;
	fopen_s(&file, "Students.txt", "w");
	if (file != NULL) {
		fprintf(file,"���������� ���������: %d\n", countStudents);
		for (register int i = 0; i < countStudents; i++) {
			fprintf(file, "\n������� � ��������: %s %s\n", students[i].surname, students[i].inicials);
			fprintf(file, "��� ��������: %d\n", students[i].yearOfBirth);
			fprintf(file, "��� ����������� � �����: %d\n", students[i].yearOfAdmission);
			fprintf(file, "������ �� ������: %d\n", students[i].studentsRecordBook.physicsMark);
			fprintf(file, "������ �� ������ ����������: %d\n", students[i].studentsRecordBook.higherMathMark);
			fprintf(file, "������ �� �����������: %d\n", students[i].studentsRecordBook.computerScienceMark);
		}

		fclose(file);
		printf("���������� � ��������� ������� �������� � ����\n");
	}
	else {
		printf("��������� ����������� ������ =(\n");
	}
}

extern void addStudent() {
	countStudents++;
	allocationMemory();
	int index = countStudents - 1;
	printf("������� ���������� � ����� ��������:\n");
	char* str = inputSurname();
	strcpy_s(students[index].surname, str);
	str = inputInitials();
	strcpy_s(students[index].inicials, str);
	students[index].yearOfBirth = inputYearOfBirth();
	students[index].yearOfAdmission = inputYearOfAdmission(students[index].yearOfBirth);
	students[index].studentsRecordBook.physicsMark = inputMark(CODE_PHYSICS);
	students[index].studentsRecordBook.higherMathMark = inputMark(CODE_HIGHER_MATH);
	students[index].studentsRecordBook.computerScienceMark = inputMark(CODE_COMPUTER_SCIENCE);;
	calculateMiddleMark(countStudents-1);
}

extern void printStudents() {
	printf("������ ���������\n");
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {

		int maxLenSurname = 7;
		for (register int i = 0; i < countStudents; i++) {
			maxLenSurname = strlen(students[i].surname) > maxLenSurname ? 
				strlen(students[i].surname) : maxLenSurname;
		}

		for (register int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}
		printf("\n|  �|�������");
		for (register int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|��� ��������|��� �����������|������� ������|������� ������ ����������|������� �����������|\n");
		for (register int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}printf("\n");
		for (register int i = 0; i < countStudents; i++) {
			printf("|%3d|", i + 1);
			printf("%s",students[i].surname);
			for (register int j = 0; j < maxLenSurname - strlen(students[i].surname); j++) {
				printf(" ");
			}
			printf(" %s", students[i].inicials);
			printf("|%d        |", students[i].yearOfBirth);
			printf("%d           ", students[i].yearOfAdmission);
			printf("|%2d            |", students[i].studentsRecordBook.physicsMark);
			printf("%2d                       ", students[i].studentsRecordBook.higherMathMark);
			printf("|%2d                 |\n", students[i].studentsRecordBook.computerScienceMark);
			for (register int i = 0; i < maxLenSurname + 101; i++) {
				printf("-");
			}printf("\n");
		}
	}
}

extern void printStudentsWhoHasMarksThree() {
	printf("������ ��������� � ������� ���� ������� 3:\n");
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		bool isHaventStudentsWhoWhasThree = true;
		int maxLenSurname = 7;
		for (register int i = 0; i < countStudents; i++) {
			maxLenSurname = strlen(students[i].surname) > maxLenSurname && 
				(students[i].studentsRecordBook.computerScienceMark == 3 ||
				students[i].studentsRecordBook.physicsMark == 3 ||
				students[i].studentsRecordBook.higherMathMark == 3) ?
				strlen(students[i].surname) : maxLenSurname;
		}

		for (register int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}
		printf("\n|  �|�������");
		for (register int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|��� ��������|��� �����������|������� ������|������� ������ ����������|������� �����������|\n");
		for (register int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}printf("\n");
		for (register int i = 0; i < countStudents; i++) {
			if (students[i].studentsRecordBook.computerScienceMark == 3 ||
				students[i].studentsRecordBook.physicsMark == 3 ||
				students[i].studentsRecordBook.higherMathMark == 3) {
				printf("|%3d|", i + 1);
				printf("%s", students[i].surname);
				for (register int j = 0; j < maxLenSurname - strlen(students[i].surname); j++) {
					printf(" ");
				}
				printf(" %s", students[i].inicials);
				printf("|%d        |", students[i].yearOfBirth);
				printf("%d           ", students[i].yearOfAdmission);
				printf("|%2d            |", students[i].studentsRecordBook.physicsMark);
				printf("%2d                       ", students[i].studentsRecordBook.higherMathMark);
				printf("|%2d                 |\n", students[i].studentsRecordBook.computerScienceMark);
				for (register int i = 0; i < maxLenSurname + 101; i++) {
					printf("-");
				}printf("\n");
				isHaventStudentsWhoWhasThree = false;
			}
		}
		if (isHaventStudentsWhoWhasThree) {
			printf("������ ��������� ����\n");
		}
	}
}

void updateStudent()
{
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int index;
		do {
			printf("�������� ����� ��������, ���������� � ������� �� ������ ��������: ");

			index = inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("�� ����� ������������ ����� ��������, ���������� ��� ���\n");
			}
		} while (index == 0);
		index--;
		int options;
		do {
			printf("�������� ��������, ������� �� ������ ��������\n");
			printf("1 - �������\n");
			printf("2 - ��������\n");
			printf("3 - ��� ��������\n");
			printf("4 - ��� ����������� � �����\n");
			printf("5 - ������ � �������\n");
			printf("�������� ��� ���������: ");
			options = inputIntOptions();
			switch (options)
			{
			case 1:
			{
				char* surname = inputSurname();
				strcpy_s(students[index].surname, surname);
			}
			break;
			case 2:
			{
				char* inicials = inputSurname();
				strcpy_s(students[index].inicials, inicials);
			}
			break;
			case 3:
				students[index].yearOfBirth = inputYearOfBirth();
				break;
			case 4:
				students[index].yearOfAdmission = inputYearOfAdmission(students[index].yearOfBirth);
				break;
			case 5:
				int disciplineIndex;
				do {
					printf("�������� ���������� �� ������� �� ������ �������� ������\n");
					printf("1 - ������\n");
					printf("2 - ������ ����������\n");
					printf("3 - �����������\n");
					printf("����� ����������: ");
					disciplineIndex = inputIntOptions();
					switch (disciplineIndex)
					{
					case CODE_PHYSICS:
						students[index].studentsRecordBook.higherMathMark = inputMark(CODE_PHYSICS);
						break;
					case CODE_HIGHER_MATH:
						students[index].studentsRecordBook.physicsMark = inputMark(CODE_HIGHER_MATH);
						break;
					case CODE_COMPUTER_SCIENCE:
						students[index].studentsRecordBook.computerScienceMark = inputMark(CODE_COMPUTER_SCIENCE);
						break;
					default:
						disciplineIndex = 0;
						printf("�� ����� ������������ ����� ����������, ���������� ��� ���\n");
						break;
					}
				} while (!disciplineIndex);
				calculateMiddleMark(index);
				break;
			default:
				printf("�� ������� �������� ��������, ���������� ��� ���\n");
				break;
			}
		} while (!options);
		printf("������ �������� ������� ���������\n");
	}
}

extern void deleteStudent() {
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int index;
		do {
			printf("�������� ����� ��������, ���������� � ������� �� �������: ");

			index = inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("�� ����� ������������ ����� ��������, ���������� ��� ���\n");
			}

		} while (index == 0);
		index--;
		for (register int i = index; i < countStudents-1; i++) {
			students[i] = students[i+1];
		}
		countStudents--;
		allocationMemory();
		printf("������� ������� �����\n");
	}
}

extern void sortStudent() {
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		bool isIncorrect = false;
		int options;
		do {
			printf("�������� �������� �� ��������, �� ������ ������������� ���������\n");
			printf("1 - �� �������(� ���������� �������)\n");
			printf("2 - �� �������� �����\n");
			printf("��� ��������: ");
			options = inputIntOptions();
			isIncorrect = false;
			if (options != 1 && options != 2) {
				isIncorrect = true;
				printf("�� ������� �������� ��������, ���������� ��� ���\n");
			}

		} while (isIncorrect);


		bool isSwap = true;
		for (register int k = 0; k < countStudents && isSwap; k++) {
			isSwap = false;
			for (register int i = 0; i < countStudents - 1 - k; i++) {
				if (options == 1 && strcmp(students[i].surname, students[i + 1].surname) > 0 ||
					options == 2 && students[i].studentsRecordBook.middleMark < students[i + 1].studentsRecordBook.middleMark) {
					Student temp = students[i];
					students[i] = students[i + 1];
					students[i + 1] = temp;
					isSwap = true;
				}
			}
		}

		printf("�������� ������� �������������\n");
	}
}

extern char* inputSurname() {
	static char surname[256];
	bool isIncorrect;
	do
	{
		printf("������� ��������: ");
		gets_s(surname, 256);
		deleteBeginsAndEndsSpaces(surname);
		isIncorrect = false;
		if (strlen(surname) == 0) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; surname[i] != '\0'; i++) {
				if ((('�' > surname[i] || surname[i] > '�'))
					&& surname[i] != '-' && !isalpha(surname[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		
		if (isIncorrect) {
			printf("������������ �������, ���������� ��� ���\n");
		}

	} while (isIncorrect);
	return surname;
}

extern char* inputInitials() {
	static char inicials[256];
	bool isIncorrect;
	do
	{
		printf("������� ��������: ");
		gets_s(inicials, 256);
		deleteBeginsAndEndsSpaces(inicials);
		isIncorrect = false;
		if (strlen(inicials) != 4 && strlen(inicials) != 5) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; inicials[i] != '\0'; i++) {
				if (('�' > inicials[i] || inicials[i] > '�')
					&& inicials[i] != '.' && !isalpha(inicials[i])) {
					if (inicials[i] != ' ') {
						isIncorrect = true;
						break;
					}
					else if(i != 2){
						isIncorrect = true;
						break;
					}
				}
				else if(inicials[i] == '.' && 
					((i != 1 && i != 3) && strlen(inicials) == 4 ||
					(i != 1 && i != 4) && strlen(inicials) == 5))  {
					isIncorrect = true;
					break;
				}
				else if(('�' <= inicials[i] && inicials[i] <= '�') && 
					((i != 0 && i != 2) && strlen(inicials) == 4 ||
					  (i!= 0 && i != 3) && strlen(inicials) == 5)){
					isIncorrect = true;
					break;
				}
			}
		}
		if (isIncorrect) {
			printf("������������ ��������, ���������� ��� ���\n");
		}

	} while (isIncorrect);

	if (strlen(inicials) == 5) {
		inicials[2] = inicials[3];
		inicials[3] = inicials[4];
		inicials[4] = '\0';
	}

	return inicials;
}

extern int inputYearOfBirth() {
	char yearOfBirth[256];
	bool isIncorrect;
	do
	{
		printf("������� ��� ��������: ");
		gets_s(yearOfBirth, 256);
		deleteBeginsAndEndsSpaces(yearOfBirth);
		isIncorrect = false;
		if (strlen(yearOfBirth) != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfBirth[i] != '\0'; i++) {
				if (('�' < yearOfBirth[i] && yearOfBirth[i] < '�') || !isdigit(yearOfBirth[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = atoi(yearOfBirth);
			if (1907 <= year && year <= 2006) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ ��� ��������, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}

extern int inputYearOfAdmission(int yearOfBirth) {
	char yearOfAdmission[256];
	bool isIncorrect;
	do
	{
		printf("������� ��� ����������� � �����: ");
		gets_s(yearOfAdmission, 256);
		deleteBeginsAndEndsSpaces(yearOfAdmission);
		isIncorrect = false;
		if (strlen(yearOfAdmission) != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfAdmission[i] != '\0'; i++) {
				if (('�' < yearOfAdmission[i] && yearOfAdmission[i] < '�') || !isdigit(yearOfAdmission[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = atoi(yearOfAdmission);
			if (1964 <= year && year <= 2024 && (year - yearOfBirth >= 17)) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ ��� ����������� � �����, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}

extern int inputMark(int codeOfDiscipline) {
	char mark[256];
	bool isIncorrect;
	do
	{
		switch (codeOfDiscipline)
		{
		case CODE_PHYSICS:
			printf("������� ������ �� ������: ");
			break;
		case CODE_HIGHER_MATH:
			printf("������� ������ �� ������ ����������: ");
			break;
		case CODE_COMPUTER_SCIENCE:
			printf("������� ������ �� �����������: ");
			break;
		}
		gets_s(mark, 256);
		deleteBeginsAndEndsSpaces(mark);
		isIncorrect = false;
		if (strlen(mark) != 1 && strlen(mark) != 2) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; mark[i] != '\0'; i++) {
				if (('�' < mark[i] && mark[i] < '�') || !isdigit(mark[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = atoi(mark);
			if (0 <= year && year <= 10) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ ������, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}

extern int inputIntOptions()
{
	char options[256];
	bool isIncorrect;

	gets_s(options, 256);
	deleteBeginsAndEndsSpaces(options);
	isIncorrect = false;
	for (int i = 0; options[i] != '\0'; i++) {
		if (('�' < options[i] && options[i] < '�') || !isdigit(options[i])) {
			isIncorrect = true;
			break;
		}
	}
	if (isIncorrect) {
		return 0;
	}


	return atoi(options);
}

extern void deleteBeginsAndEndsSpaces(char* str)
{
	int beginIndex = -1, endIndex = -1;
	for (register int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && beginIndex == -1) {
			beginIndex = i;
		}
		else if (str[i] == ' ' && beginIndex != -1&& endIndex == -1) {
			endIndex = i - 1;
		}
		else if (str[i] != ' ') {
			endIndex = -1;
		}
	}
	int lenOfWord;
	if (endIndex != -1) {
		lenOfWord = endIndex - beginIndex + 1;
	}
	else {
		lenOfWord = strlen(str) - beginIndex;
	}
	for (int i = 0, j = beginIndex; i < lenOfWord; i++, j++) {
		str[i] = str[j];
		if (i == lenOfWord-1 && i+1 != strlen(str)){
			str[i + 1] = '\0';
		}
	}
}