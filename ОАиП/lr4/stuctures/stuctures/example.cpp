#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>
#define LIMIT 100 // максимальное количество стран для массива структур
//прототипы функций
using namespace std;
void inputInfo();
void outputInfo();
void searchInfo();
void deleteCountry();
void writeInfo();
void readInfo();
// структура
struct Goverment
{
	char name[16];
	char capital[16];
	unsigned int population;
	unsigned int area;
	char president[16];
};

Goverment country[LIMIT]; //массив country из объектов country
int current_size = 0; // текущий размер массива

int main()
{
	SetConsoleOutputCP(1251); // для распознавания кириллицы при записи в массив
	SetConsoleCP(1251);
	int choice;
	do {
		cout << "\nВведите вариант работы приложения: \n";
		cout << "0. Выход из приложения\n";
		cout << "1. Ввод элементов структуры с клавиатуры\n";
		cout << "2. Вывод элементов структуры в консольное окно\n";
		cout << "3. Удаление заданной структурированной переменной\n";
		cout << "4. Поиск информации\n";
		cout << "5. Запись информации в файл\n";
		cout << "6. Чтение данных из файла\n";
		cin >> choice;
		switch (choice)
		{
		case 1: { //Ввод элементов структуры с клавиатуры
			inputInfo();
			break;
		}
		case 2: { //Вывод элементов структуры в консольное окно
			outputInfo();
			break;
		}
		case 3: { //Удаление заданной структурированной переменной
			deleteCountry();
			break;
		}
		case 4: { //Поиск информации
			searchInfo();
			break;
		}
		case 5: { //Запись информации в файл
			writeInfo();
			break;
		}
		case 6: { //Чтение данных из файла
			readInfo();
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
}

void inputInfo()
{
	if (current_size < LIMIT) { //если массив не выходит за пределы заданного, то вводим соотв. информацию
		cout << "Введите название: " << endl;
		cin >> country[current_size].name;
		cout << "Введите столицу: " << endl;
		cin >> country[current_size].capital;
		cout << "Введите численность населения: " << endl;
		cin >> country[current_size].population;
		cout << "Введите площадь территории (в км^2): " << endl;
		cin >> country[current_size].area;
		cout << "Введите фамилию президента страны: " << endl;
		cin >> country[current_size].president;
		current_size++;
		cout << "Элемент структуры создан. " << endl;
	}
	else { //иначе выводим сообщение о переполнении
		cout << "Структура переполнена!" << endl;
	}
}

void outputInfo()
{
	for (int i = 0; i < current_size; i++) { //поочередно выводим информацию о странах
		cout << "\nСтрана №" << i + 1 << endl;
		cout << "Название: " << country[i].name << endl;
		cout << "Столица: " << country[i].capital << endl;
		cout << "Численность населения: " << country[i].population << endl;
		cout << "Площадь страны: " << country[i].area << endl;
		cout << "Президент страны: " << country[i].president << endl;
	}
}

void searchInfo() {
	char country_name[20]; //переменная для поиска страны
	cout << "По какой стране вы хотите найти информацию? " << endl;
	cin >> country_name;
	for (int i = 0; i < 1; i++) {
		if (!strcmp(country_name, country[i].name)) { //если введенная страна найдена, то выводим информацию о ней
			cout << "Информация о выбранной стране: " << country_name << endl;
			cout << "Столица: " << country[i].capital << endl;
			cout << "Численность населения: " << country[i].population << endl;
			cout << "Площадь страны: " << country[i].area << endl;
			cout << "Президент страны: " << country[i].president << endl;
		}
		else { //иначе выводим сообщение об ошибке
			cout << "Страна была введена неверно" << endl;
		}
	}
}

void deleteCountry() {
	char country_name[20]; //переменная для поиска страны
	cout << "Введите страну, которую хотите удалить из структуры: " << endl;
	cin >> country_name;
	for (int i = 0; i < current_size; i++) {
		if (!strcmp(country_name, country[i].name)) { //если введенная страна найдена, то удаляем ее из структуры
			for (int j = i; j < current_size - 1; j++) {
				country[j] = country[j + 1];
			}
			current_size--;
			cout << "Структурная переменная очищена. " << endl;
		}
		else {  //иначе выводим сообщение об ошибке
			cout << "Страна не была найдена" << endl;
		}
	}
}

void writeInfo() {
	ofstream ofile("countries.txt"); // создание объекта класса ofstream для записи
	if (ofile.fail()) {  // в случае ошибки открытия файла
		cout << "Файл не удалось открыть!" << endl;
		exit(1);
	}
	for (int i = 0; i < current_size; i++) { //записываем информацию в файл
		ofile << country[i].name << " " << country[i].capital << " " << country[i].population << " " << country[i].area << " " << country[i].president << " " << endl;
	}
	ofile.close(); //закрытие файла
	cout << "Информация о странах успешна записана в файл";
}

void readInfo() {
	ifstream ifile("countries.txt"); // создание объекста класса ifstream для чтения
	if (ifile.fail()) { // в случае ошибки открытия файла
		cout << "Файл не удалось открыть!" << endl;
		exit(1);
	}

	current_size++; //увеличиваем размера массива для будущей записи страны
	for (int i = 0; i < current_size; i++) { //читаем информацию о тсране из файла
		ifile >> country[i].name >> country[i].capital >> country[i].population >> country[i].area >> country[i].president;
		
	}
	ifile.close(); //закрытие файла
	cout << "Информация из файла успешно прочитана и записана в структуру";

}
