#include<iostream>
using namespace std;
struct Item  {
	int data;
	Item* next;
};
Item* head, * tail;
bool isNull(void) {  //Проверка на пустоту
	return (head == NULL);
}
void deletFirst() {  //Извлечение элемента из начала
	if (isNull())  {
		cout << "Очередь пуста" << endl;
	}
	else  {
		Item* temp = NULL;
		Item* current = head;
		while (!isNull())  {  //Перебираем указатель, пока не доберемся до конца очереди
			if (current->next == tail) {  //если добрались, то через временную переменную удаляем последний элемент
				current->next = NULL;
				temp = tail;
				tail = current;
				break;

			}
			current = current->next;  //Перемещаем указатель на следующий элемент
		}
		delete temp;
	}
}

void getFromHead() {   //Получение элемента из конца

	if (isNull())  {
		cout << "Очередь пуста" << endl;
	}
	else  {
		cout << "Конец = " << tail->data << endl;
	}
}
void insertToQueue(int x) {  //Добавление элемента в очередь 

	Item* p = new Item;  //Cоздаем новый указатель
	p->data = x;
	p->next = NULL;
	//Если очередь пустая, то в конец и начало очереди добавляем элемент
	if (isNull()) {
		head = tail = p;
	}
	//Иначе перебираем все элементы очереди для установки нового
	else {
		Item* previous = NULL;
		Item* current = head;
		//Пока новый элемент меньше или равно текущих или очередь не закончилась
		while (current != NULL && x <= current->data) {
			previous = current;  //перебираем указатель до NULL, чтобы установить жлемент в конец строки
			current = current->next;
		}
		//Если элемент с более высоким приоритетом,то устанавливаем в начало очереди
		if (previous == NULL) {
			p->next = head;
			head = p;
		}
		else {
			//Если число меньше всех текущих, то устанавливаем его в конец
			if (current == NULL) {
				tail->next = p;
				tail = p;
			}
			//Если число где-то между
			else {
				p->next = current;
				previous->next = p;
			}
		}
	}
}

void printQueue() {   //Вывод очереди

	Item* p = new Item;
	if (isNull())  {
		cout << "Очередь пуста" << endl;
	}
	else  {
		cout << "Очередь = ";
		p = head;
		while (!isNull())  {
			if (p != NULL)  {
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else  {
				cout << "NULL" << endl;
				return;
			}
		}
	}
}
void clrQueue()  {  //Очистка очереди

	while (!isNull()) deletFirst();
}
int main()  {
	setlocale(LC_CTYPE, "Russian");
	int choice = 1, z; head = NULL; tail = NULL;
	while (choice != 0)  {
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с конца" << endl;
		cout << "3 - извлечь элемент с конца" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие "; cin >> choice;
		switch (choice)  {
		case 1: {
			cout << "Введите элемент: "; 
			cin >> z;
			insertToQueue(z);
			printQueue();
			break;
		}
		case 2: {
			getFromHead();
			break;
		}
		case 3: {
			deletFirst();
			break;
		}
		case 4: {
			printQueue();
			break;
		}
		case 5: { 
			clrQueue();
			break; 
		}
		}
	}
	return 0;
}