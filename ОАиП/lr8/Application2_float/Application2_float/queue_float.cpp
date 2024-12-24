#include <iostream>
using namespace std;

struct Queue {   // создаем очередь 
	double number;
	Queue* next;
};
void createQueue(Queue** begin, Queue** end, int size);
void displayQueue(Queue* begin);
void deleteQueue(Queue** begin);
void ringQueue(Queue** begin);

void createQueue(Queue** begin, Queue** end, int size) {
	Queue* temp;
	double n; //переменная для ввода числа
	cout << "Введите следующие элементы очереди: " << endl;
	for (int i = 0; i < size; i++) {
		temp = new Queue; // Создание нового элемента очереди
		cin >> n;  // Ввод значения с клавиатуры
		temp->number = n;  // Запись значения в элемент
		temp->next = NULL;  // Указываем, что следующий элемент пустой
		if (*begin == NULL) {
			*begin = temp;  // Если начало очереди пустое, устанавливаем начало
		}
		else {
			(*end)->next = temp;  // Иначе устанавливаем связь с последним элементом
		}
		*end = temp;  // Устанавливаем конец очереди на новый элемент
	}
	cout << "Очередь успешно создана" << endl;
}

void displayQueue(Queue* begin) {
	Queue* temp = begin; // Создаем временный указатель temp для вывода элементов очереди
	if (temp == NULL) {
		cout << "Очередь пуста!" << endl;
	}
	else {
		while (temp != NULL) {  //Выводим элементы до конца очереди
			cout << temp->number << " ";
			temp = temp->next;  //Перемещаем указатель на следующий элемент
		}
		cout << endl;
	}
}

void deleteQueue(Queue** begin) {
	Queue* temp;
	while (*begin != NULL) {  //Удаляем пока начало очереди не достигнет NULL
		temp = *begin;
		*begin = (*begin)->next;
		delete temp;
	}
}

void ringQueue(Queue** begin) {

	if (*begin == NULL) {
		return; // Проверка на пустую очередь
	}
	Queue* temp = *begin;
	Queue* current = *begin;
	double max = (*begin)->number; // Переменная для максимального значения в очереди
	// Находим максимальное значение в очереди
	while (temp != NULL) {
		if (temp->number > max) {
			max = temp->number;
		}
		temp = temp->next;
	}
	// Пока максимальный элемент не находится в начале и очередь не состоит из одного элемента
	while ((*begin)->number != max) {
		temp = *begin;
		current = temp->next;
		*begin = current;
		temp->next = nullptr;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, * end = NULL; //создание начала и конца очереди
	int size;  //Размер очереди
	cout << "Введите размер очереди: ";
	cin >> size;
	if (size > 0) {
		createQueue(&begin, &end, size);
	}
	else {
		cout << "Очередь не может быть больше заполнена!";
	}
	cout << "Очередь до циклического сдвига: ";
	displayQueue(begin);
	cout << "Очередь после циклического сдвига: ";
	ringQueue(&begin);
	displayQueue(begin);
	deleteQueue(&begin);
	return 0;
}

