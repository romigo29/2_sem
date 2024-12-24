#include "stack.h"

void inputStack(int x, Stack*& myStack) {   //Добавление элемента х в стек
	Stack* element = new Stack; //выделение памяти для нового элемента
	element->data = x; //запись элемента x в поле data
	element->next = myStack; //перенос вершины на следующий элемент 
	myStack = element; //сдвиг вершины на позицию вперед
}

int getElement(Stack*& myStack) {
	if (myStack == NULL) {
		cout << "Стек пуст!" << endl;
		return -1; // если стек пуст - возврат (-1)
	}
	else {
		Stack* element = myStack; // element - переменная для хранения адреса элемента
		int x = myStack->data; // запись элемента из поля data в переменную x
		myStack = myStack->next; // перенос вершины
		delete element; // освобождение памяти
		return x;
	}
}

void toFile(Stack*& myStack) {
	ofstream ofile("myStack.txt");
	if (ofile.fail()) {
		cout << "\nОшибка открытия файла";
		exit(1);
	}

	Stack* temp = myStack; // Создаем временный указатель для обхода стека
	while (temp != NULL) {
		ofile << temp->data << " "; // Записываем данные элемента в файл
		temp = temp->next; // Переходим к следующему элементу стека
	}

	ofile.close();
	cout << "Стек записан в файл myStack.txt\n";
}

void fromFile(Stack*& myStack) {
	ifstream ifile("myStack.txt");
	int temp;
	if (ifile.fail()) {
		cout << "\nОшибка открытия файла";
		exit(1);
	}

	while (ifile >> temp) {
		inputStack(temp, myStack); // Используем ссылку на указатель myStack для добавления элемента в стек
	}

	ifile.close();
	cout << "\nСтек считан из файла myStack.txt\n\n";
}

void displayStack(Stack*& myStack) {  // Вывод стека
	Stack* temp = myStack;
	if (temp == NULL)
		cout << "Стек пуст!" << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


int clearStack(Stack*& myStack) {
	if (myStack == NULL) {   //если стек пуст
		return 0;
	}
	while (myStack != NULL) {   //пока стек не пуст
		Stack* temp = myStack;   //временная переменная для текущего элемента стека
		myStack = myStack->next;  //переключаемся на следующей элемент стека
		delete temp;   //удаялем текущий элемент
	}
	return 1;
}

//определение элемента  в границе диапазона чисел
int defineElement(Stack*& myStack) {
	int a, b; //левая и правая границы диапазона чисел
	cout << "Введите диапазон чисел [a, b]: ";
	cin >> a >> b;
	int element;
	while (myStack != NULL) {
		element = getElement(myStack);  //извлечение элемента
		if (a <= element && element <= b) { //если элемент попадает в диапазон чисел 
			return 1;
		}
	}
	return 0;
}

