#include "queue.h"

int main() {
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, *end, *element; //создание начала и конца очереди и ее элементов
	element = new Queue;  // Создаем новый элемент очереди
	int choice, first, size;  //Выбор пользователя, первый элемент очереди и  ее размер
	cout << "Введите размер очереди: ";
	cin >> size;
	while (size < 1) {
		cout << "Введите значение большее, чем 0: ";
		cin >> size;
	}
	cout << "Ввдедите первый элемент очереди: ";
	cin >> first;
	element->number = first;  //Добавляем первый элемент очереди
	element->next = NULL;  //Указываем, что следующий элемент NULL
	begin = end = element;  //Указываем начало и конец очереди

	do {
		cout << "\nВыберите команду:" << endl;
		cout << "1 - Добавление элементов в очередь (при повторении первого элемента выводится очередь ее размер" << endl;
		cout << "2 - Вывод элементов очереди" << endl;
		cout << "3 - Удаление очереди" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			if (size > 1 )  {
				createQueue(&begin, &end, size, first);
			}
			else {
				cout << "Очередь не может быть больше заполнена!";
			}
			break;
		}
		case 2: {
			displayQueue(begin);
			break;
		}
		case 3: {
			deleteQueue(&begin);
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
