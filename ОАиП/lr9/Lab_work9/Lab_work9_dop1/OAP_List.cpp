#include "List.h"

void print(void* b) {
	Country* a = (Country*)b;
	cout << a->name << " " << a->capital << " " << a->population << " " << a->area << " " << a->head_lastname << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Object L1 = Create(); 

	unsigned short choice;
	bool rc;

	do {
	
		cout << "\n0. Выход из приложения\n";
		cout << "1. Ввод элементов списка с клавиатуры\n";
		cout << "2. Вывод элементов списка в консольное окно\n";
		cout << "3. Удаление заданного элемента\n";
		cout << "4. Поиск информации\n";
		cout << "5. Расчет элементов списка\n";
		cout << "6. Удаление списка\n"; 
		cout << "Введите вариант работы приложения: ";
		cin >> choice;
		switch (choice)
		{
		case 1: { //Ввод элементов структуры с клавиатуры
			Country* newCountry = new Country;

			cout << "Название страны: ";
			cin >> newCountry->name;
			cout << "Столица страны: ";
			cin >> newCountry->capital;
			cout << "Численность населения страны: ";
			cin >> newCountry->population;
			cout << "Площадь страны: ";
			cin >> newCountry->area;
			cout << "Фамилия главы страны: ";
			cin >> newCountry->head_lastname;

			L1.Insert(newCountry);
			break;
		}
		case 2: { //Вывод элементов структуры в консольное окно
			cout << "Список:" << endl;
			L1.PrintList(print); // Выводим обновленный список
			break;
		}
		case 3: { //Удаление заданного элемента

			char deleteName[20];
			cout << "Введите необходимую страну: ";
			cin >> deleteName;
			rc = L1.Delete(deleteName);
			if (rc) {
				cout << "Элемент удален" << endl;
			}
			else {
				cout << "Элемент не найден" << endl;
			}
			break;
		}
		case 4: { //Поиск информации
			char searchName[20];
			cout << "Введите необходимую страну: ";
			cin >> searchName;

			Element* find = L1.Search(searchName);
			if (find != NULL) {
				Country* countryInfo = (Country*)find->Data;
				cout << "Информация о стране: " << endl;
				print(countryInfo);
			}
			else {
				cout << "Страна не найдена" << endl;
			}
			break;
		}
		case 5: { // Расчет элементов списка
			cout << "Количество элементов в списке: " << L1.countList() << endl; // Исправлено название метода
			break;
		}
		case 6: { // Удаление списка
			rc = L1.deleteList();  // Удаляем элементы списка
			if (rc) {
				cout << "Список удален" << endl;
			}
			else {
				cout << "Список пуст!" << endl;
			}
			break;
		}
		case 0: { //Выход из программы
			exit(0);
			break;
		}
		default: {
			cout << "Введено некорректное значение. " << endl;
			break;
		}
		}
	} while (choice != 0);

	return 0;
}
