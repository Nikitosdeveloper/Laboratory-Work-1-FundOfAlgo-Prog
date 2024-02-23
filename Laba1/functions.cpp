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

		fscanf_s(file, "Количество студентов: %d\n", &countStudents);

		allocationMemory();

		for (register int i = 0; i < countStudents; i++) {
			fscanf_s(file, "Фамилия и инициалы: %s %s\n", students[i].surname,sizeof(students[i].surname), students[i].inicials, sizeof(students[i].surname));
			fscanf_s(file, "Год Рождения: %d\n", &students[i].yearOfBirth);
			fscanf_s(file, "Год поступления в БГУИР: %d\n", &students[i].yearOfAdmission);
			fscanf_s(file, "Оценка по физике: %d\n", &students[i].studentsRecordBook.physicsMark);
			fscanf_s(file, "Оценка по высшей математике: %d\n", &students[i].studentsRecordBook.higherMathMark);
			fscanf_s(file, "Оценка по информатике: %d\n", &students[i].studentsRecordBook.computerScienceMark);
			calculateMiddleMark(i);
		}

		fclose(file);
		printf("Информация о студентах успешно прочитана из файла\n");
	}
	else {
		printf("Произошла неизвестная ошибка =(\n");
	}
}

extern void writeToFile() {
	FILE* file;
	fopen_s(&file, "Students.txt", "w");
	if (file != NULL) {
		fprintf(file,"Количество студентов: %d\n", countStudents);
		for (register int i = 0; i < countStudents; i++) {
			fprintf(file, "\nФамилия и инициалы: %s %s\n", students[i].surname, students[i].inicials);
			fprintf(file, "Год Рождения: %d\n", students[i].yearOfBirth);
			fprintf(file, "Год поступления в БГУИР: %d\n", students[i].yearOfAdmission);
			fprintf(file, "Оценка по физике: %d\n", students[i].studentsRecordBook.physicsMark);
			fprintf(file, "Оценка по высшей математике: %d\n", students[i].studentsRecordBook.higherMathMark);
			fprintf(file, "Оценка по информатике: %d\n", students[i].studentsRecordBook.computerScienceMark);
		}

		fclose(file);
		printf("Информация о студентах успешно записана в файл\n");
	}
	else {
		printf("Произошла неизвестная ошибка =(\n");
	}
}

extern void addStudent() {
	countStudents++;
	allocationMemory();
	int index = countStudents - 1;
	printf("Введите информацию о новом студенте:\n");
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
	printf("Список студентов\n");
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
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
		printf("\n|  №|Фамилия");
		for (register int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|Год рождения|Год поступления|Отметка Физика|Отметка высшая математика|Отметка информатика|\n");
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
	printf("Список студентов у которых есть отметка 3:\n");
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
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
		printf("\n|  №|Фамилия");
		for (register int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|Год рождения|Год поступления|Отметка Физика|Отметка высшая математика|Отметка информатика|\n");
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
			printf("Списко студентов пуст\n");
		}
	}
}

void updateStudent()
{
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
	}
	else {
		int index;
		do {
			printf("Выберете номер студента, информацию о котором вы хотите изменить: ");

			index = inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("Вы ввели некорректный номер студента, попробуйте ещё раз\n");
			}
		} while (index == 0);
		index--;
		int options;
		do {
			printf("Выберете параметр, который вы хотите изменить\n");
			printf("1 - фамилию\n");
			printf("2 - инициалы\n");
			printf("3 - год рождения\n");
			printf("4 - год поступления в БГУИР\n");
			printf("5 - оценку в зачётке\n");
			printf("Параметр для изменения: ");
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
					printf("Выберете дисциплину по которой вы хотите изменить оценку\n");
					printf("1 - физика\n");
					printf("2 - высшая математика\n");
					printf("3 - информатика\n");
					printf("Номер дисциплины: ");
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
						printf("Вы ввели неправильный номер дисциплины, попробуйте ещё раз\n");
						break;
					}
				} while (!disciplineIndex);
				calculateMiddleMark(index);
				break;
			default:
				printf("Вы выбрали неверный параметр, попробуйте ещё раз\n");
				break;
			}
		} while (!options);
		printf("Данные студента успешно обновлены\n");
	}
}

extern void deleteStudent() {
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
	}
	else {
		int index;
		do {
			printf("Выберете номер студента, информацию о котором вы удалить: ");

			index = inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("Вы ввели некорректный номер студента, попробуйте ещё раз\n");
			}

		} while (index == 0);
		index--;
		for (register int i = index; i < countStudents-1; i++) {
			students[i] = students[i+1];
		}
		countStudents--;
		allocationMemory();
		printf("Студент успешно удалён\n");
	}
}

extern void sortStudent() {
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
	}
	else {
		bool isIncorrect = false;
		int options;
		do {
			printf("Выберете параметр по которому, вы хотите отсортировать студентов\n");
			printf("1 - по фамилии(в алфавитном порядке)\n");
			printf("2 - по среднему баллу\n");
			printf("Ваш параметр: ");
			options = inputIntOptions();
			isIncorrect = false;
			if (options != 1 && options != 2) {
				isIncorrect = true;
				printf("Вы выбрали неверный параметр, попробуйте ещё раз\n");
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

		printf("Студенты успешно отсортированы\n");
	}
}

extern char* inputSurname() {
	static char surname[256];
	bool isIncorrect;
	do
	{
		printf("Введите фамилиию: ");
		gets_s(surname, 256);
		deleteBeginsAndEndsSpaces(surname);
		isIncorrect = false;
		if (strlen(surname) == 0) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; surname[i] != '\0'; i++) {
				if ((('А' > surname[i] || surname[i] > 'я'))
					&& surname[i] != '-' && !isalpha(surname[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		
		if (isIncorrect) {
			printf("Некорректная фамилия, попробуйте ещё раз\n");
		}

	} while (isIncorrect);
	return surname;
}

extern char* inputInitials() {
	static char inicials[256];
	bool isIncorrect;
	do
	{
		printf("Введите инициалы: ");
		gets_s(inicials, 256);
		deleteBeginsAndEndsSpaces(inicials);
		isIncorrect = false;
		if (strlen(inicials) != 4 && strlen(inicials) != 5) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; inicials[i] != '\0'; i++) {
				if (('А' > inicials[i] || inicials[i] > 'я')
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
				else if(('А' <= inicials[i] && inicials[i] <= 'я') && 
					((i != 0 && i != 2) && strlen(inicials) == 4 ||
					  (i!= 0 && i != 3) && strlen(inicials) == 5)){
					isIncorrect = true;
					break;
				}
			}
		}
		if (isIncorrect) {
			printf("Некорректные инициалы, попробуйте ещё раз\n");
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
		printf("Введите год рождения: ");
		gets_s(yearOfBirth, 256);
		deleteBeginsAndEndsSpaces(yearOfBirth);
		isIncorrect = false;
		if (strlen(yearOfBirth) != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfBirth[i] != '\0'; i++) {
				if (('А' < yearOfBirth[i] && yearOfBirth[i] < 'я') || !isdigit(yearOfBirth[i])) {
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
			printf("Некорректный год рождения, попробуйте ещё раз\n");
		}

	} while (isIncorrect);
}

extern int inputYearOfAdmission(int yearOfBirth) {
	char yearOfAdmission[256];
	bool isIncorrect;
	do
	{
		printf("Введите год поступления в БГУИР: ");
		gets_s(yearOfAdmission, 256);
		deleteBeginsAndEndsSpaces(yearOfAdmission);
		isIncorrect = false;
		if (strlen(yearOfAdmission) != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfAdmission[i] != '\0'; i++) {
				if (('А' < yearOfAdmission[i] && yearOfAdmission[i] < 'я') || !isdigit(yearOfAdmission[i])) {
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
			printf("Некорректный год поступления в БГУИР, попробуйте ещё раз\n");
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
			printf("Введите оценку по физике: ");
			break;
		case CODE_HIGHER_MATH:
			printf("Введите оценку по высшей матиматике: ");
			break;
		case CODE_COMPUTER_SCIENCE:
			printf("Введите оценку по информатике: ");
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
				if (('А' < mark[i] && mark[i] < 'я') || !isdigit(mark[i])) {
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
			printf("Некорректная оценка, попробуйте ещё раз\n");
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
		if (('А' < options[i] && options[i] < 'я') || !isdigit(options[i])) {
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