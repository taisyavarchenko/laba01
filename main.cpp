#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "STUDENT.h"
#include "GROUP.h"

int main() {
	GROUP group;
	int item; // выбираемый пункт меню

	do {
		system("cls"); // очищаем экран
		// выводим меню
		cout << "What do you want to do?" << endl;
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Print group" << endl;
		cout << "4. Print students with average score more then 4" << endl;
		cout << "5. Quit" << endl;
		cout << ">";
		cin >> item; // считываем пункт меню

		try {
			// обрабатываем некорректный ввод
			if (item < 1 || item > 5) {
				throw string("Incorrect item.");
			}

			// в зависимости от выбранного пункта выполняем действие
			switch (item) {
			case 1: {
				STUDENT student;
				cout << "Enter information about new student" << endl;
				cin >> student; // считыванием студента
				group.AddStudent(student);
			}
					break;

			case 2:
				group.RemoveStudent();
				break;

			case 3:
				cout << group;
				break;

			case 4:
				group.PrintByKey();
				break;
			}
		}
		// ловим исключения
		catch (string s) {
			cout << s << endl;
		}

		if (item != 5) {
			system("pause"); // задерживаем экран
		}

	} while (item != 5); // повторяем, пока не решим выйти


	return 0;
}
