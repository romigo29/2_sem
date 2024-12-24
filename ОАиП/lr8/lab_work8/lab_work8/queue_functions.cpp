#include "queue.h"

void createQueue(Queue** begin, Queue** end, int size, int first) {

	int n, current_size = 0; //переменная для ввода числа, текущего размера очереди
	cout << "Введите следующие элементы очереди: " << endl;
	for (int i = 1; i < size; i++) {
		Queue* temp = new Queue; // Создание указателя на очередь
		temp->next = NULL;  //указываем, что следующий элемент пустой
		cin >> n;  // Вводим число с клавиатуры
		temp->number = n;  // Добавляем значения числа в очередь
		(*end)->next = temp;    //Указатель next последнего элемента очереди устанавливается на новый элемент
		*end = temp;  //конец очереди указывает на элемент temp
		current_size++;  //Увеличиваем размер текущей очереди

		if (n == first) {
			displayQueueAndSize((*begin), current_size);
		}
	}
	cout << "Очередь успешно создана" << endl;
}

void displayQueue(Queue* begin) {
	Queue* temp = begin; // Создаем временный указатель temp для вывода элементов очереди
	if (temp == NULL) {
		cout << "Очередь пуста!" << endl;
	}
	else {	
		cout << "Элементы очереди: ";
		while (temp != NULL) {  //Выводим элементы до конца очереди
			cout << temp->number << " ";
			temp = temp->next;  //Перемещаем указатель на следующий элемент
		}
		cout << endl;
		delete temp;  //Удаляем temp по окончании работы с очередью
	}
}

void deleteQueue(Queue** begin) {

	if (begin == NULL) {
		cout << "Очередь пуста!" << endl;
	}
	else {
		Queue * temp = new Queue; // Создаем временный указатель temp для удаления очереди
		while (*begin != NULL) {  //Удаляем пока начало очереди не достигнет NULL
			temp = *begin;
			*begin = (*begin)->next;
			delete temp;
		}
		cout << "Очередь успешно удалена!" << endl;
	}
}

void displayQueueAndSize(Queue* begin, int size) {

	displayQueue(begin);
	cout << "Размер очереди: " << size << endl;
}