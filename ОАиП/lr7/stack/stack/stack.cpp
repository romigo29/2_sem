#include "stack.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int choice; char x;
	Stack* myStack = new Stack; //выделение памяти для стека
	myStack = NULL; //инициализация первого элемента
	do {
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Запись в файл" << endl;
		cout << "4 - Чтение из файла" << endl;
		cout << "5 - Вывод стека" << endl;
		cout << "6 - Определить, есть ли числа в веденном диапазоне чисел" << endl;
		cout << "7 - Очистить стек" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Введите элемент: " << endl;
			cin >> x;
			inputStack(x, myStack);
			break;
		}
		case 2: {
			x = getElement(myStack);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;
		}
		case 3: {
			toFile(myStack);
			break;
		}
		case 4: {
			fromFile(myStack);
			break;
		}
		case 5: {
			cout << "Весь стек: " << endl;
			displayStack(myStack);
			break;
		}

		case 6: {
			if (!defineElement(myStack)) {
				cout << "Нет чисел в стеке, попадающих в введенный диапазон" << endl;
			}
			else {
				cout << "Есть числа в стеке, попадающие в веденные диапазон" << endl;
			}
			break;
		}

		case 7: {
			if (!clearStack(myStack)) {
				cout << "Стек пуст!" << endl;
			}
			else {
				cout << "Стек очищен" << endl;
			}
			break;
		}
		case 0: {
			return 0;
			break;
		}
		default: {
			cout << "Выбран неверный вариант!" << endl;
		}
		}
	} while (choice != 0);

	return 0;
}

