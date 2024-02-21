#include "Header.h"

extern void menu() {

	russianAlphabet();

	printf("��� ������������ ������� ����� ��������� �����\n");

	while (true)
	{
		printf("�������� ������ �������\n");
		printf("1 - ��������� ���������� � ��������� �� �����\n");
		printf("2 - �������� ���������� � ��������� � ���� (���������� ������������ � ����� ����� �������)\n");
		printf("3 - �������� ���������� � ����� ��������\n");
		printf("4 - ���������� ���������� � ���� ��������� �� �����\n");
		printf("5 - ���������� ���������� � ����������-���������� �� �����\n");
		printf("6 - �������� ���������� � ��������\n");
		printf("7 - ������� ���������� � ��������\n");
		printf("8 - ������������� ���� ������ ���������\n");
		printf("9 - ����� �� ������� ����� ��������� �����\n");
		printf("���� �������: ");
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
			printf("������� �� ������������� ������� �����\n");
			return;
		default:
			printf("�������� �������, ���������� ��� ���\n");
			break;
		}
		printf("\n\n");
	}
}

int main() {

	menu();

	return 0;
}