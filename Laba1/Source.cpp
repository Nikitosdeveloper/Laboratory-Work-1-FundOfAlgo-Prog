#include "Header.h"

extern void menu() {

	russianAlphabet();

	printf("Вас приветствует система учёта студентов БГУИР\n");

	while (true)
	{
		printf("Выберете нужную команду\n");
		printf("1 - прочитать информацию о студентах из файла\n");
		printf("2 - записать информацию о студентах в файл (информация находившаяся в файле будет утеряна)\n");
		printf("3 - добавить информацию о новом студенте\n");
		printf("4 - напечатать информацию о всех студентах на экран\n");
		printf("5 - напечатать информацию о стундентах-троешниках на экран\n");
		printf("6 - обновить информацию о студенте\n");
		printf("7 - удалить информацию о студенте\n");
		printf("8 - отсортировать всех список студентов\n");
		printf("9 - выйти из системы учёта студентов БГУИР\n");
		printf("Ваша команда: ");
		int options = inputIntOptions();

		switch (options)
		{
		case 1:
			readFromFile();
			break;
		case 2:
			writeToFile();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			printStudents();
			break;
		case 5:
			printStudentsWhoHasMarksThree();
			break;
		case 6:
			updateStudent();
			break;
		case 7:
			deleteStudent();
			break;
		case 8:
			sortStudent();
			break;
		case 9:
			printf("Спасибо за использование системы учёта\n");
			return;
		default:
			printf("Неверная команда, попробуйте ещё раз\n");
			break;
		}
		printf("\n\n");
	}
}

int main() {

	menu();

	return 0;
}