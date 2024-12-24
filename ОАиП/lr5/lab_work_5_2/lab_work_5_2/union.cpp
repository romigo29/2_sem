#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string> 
#define LIMIT 100 // максимальное количество элементов для массива структур

using namespace std;

// объединение
union Ucars {
    char brand[20];
    char color[20];
    char number[20];
    char release_date[20];
    char body[20];
    char last_check[20];
    char owner[20];
} note[LIMIT];

// структура
struct Cars {
    string brand;
    string color;
    string number;
    string release_date;
    string body;
    string last_check;
    string owner;
} cars[LIMIT];

int current_size = 0; // текущий размер массива

// Прототипы функций
void inputInfo();
void outputInfo();
void searchInfo();

int main() {
    SetConsoleOutputCP(1251); // для распознавания кириллицы при записи в массив
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "\nВведите вариант работы приложения: \n";
        cout << "0. Выход из приложения\n";
        cout << "1. Ввод данных с клавиатуры и запись информации в файл\n";
        cout << "2. Чтение информации из файла и вывод ее на экран и\n";
        cout << "3. Поиск информации по владельцу\n";
        cin >> choice;
        switch (choice) {
        case 1: { // Ввод элементов структуры с клавиатуры и запись в файл
            inputInfo();
            break;
        }
        case 2: { // Чтение из файла и вывод элементов структуры в консольное окно
            outputInfo();
            break;
        }
        case 3: { // Поиск информации по владельцу
            searchInfo();
            break;
        }
        case 0: { // Выход из программы
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

void inputInfo() {
    if (current_size < LIMIT) { // Если массив не выходит за пределы заданного, то вводим соотв. информацию
        cout << "Сколько записей хотите сделать? - ";
        short int amount;
        cin >> amount;
        cin.ignore(); // Очистка буфера ввода

        ofstream ofile("cars.txt"); // Открыть файл для добавления новых данных
        if (!ofile) { // В случае ошибки открытия файла
            cout << "Файл не удалось открыть!" << endl;
            exit(1);
        }

        // Ввод информации с клавиатуры и запись ее в файл
        for (int i = 0; i < amount; i++) {
            cout << "Запись №" << i + 1 << ": " << endl;
            cout << "Введите марку автомобиля: ";
            cin.getline(note[i].brand, 20);
            ofile << note[i].brand << ";";
            cars[i].brand = note[i].brand;

            cout << "Введите цвет: ";
            cin.getline(note[i].color, 20);
            ofile << note[i].color << ";";
            cars[i].color = note[i].color;

            cout << "Введите заводской номер: ";
            cin.getline(note[i].number, 20);
            ofile << note[i].number << ";";
            cars[i].number = note[i].number;

            cout << "Введите дату выпуска: ";
            cin.getline(note[i].release_date, 20);
            ofile << note[i].release_date << ";";
            cars[i].release_date = note[i].release_date;

            cout << "Введите тип кузова: ";
            cin.getline(note[i].body, 20);
            ofile << note[i].body << ";";
            cars[i].body = note[i].body;

            cout << "Введите последнего осмотра: ";
            cin.getline(note[i].last_check, 20);
            ofile << note[i].last_check << ";";
            cars[i].last_check = note[i].last_check;

            cout << "Введите владельца: ";
            cin.getline(note[i].owner, 20);
            cars[i].owner = note[i].owner;
            ofile << note[i].last_check << ";" << endl;
            
            current_size++;
        }
        cout << "Информация успешно записана в файл" << endl;
        ofile.close(); // Закрытие файла
    }
    else { // Иначе выводим сообщение о переполнении
        cout << "Структура переполнена!" << endl;
    }
}

void outputInfo() {
    ifstream ifile("cars.txt"); // Создание объекта класса ifstream для чтения
    if (!ifile) { // В случае ошибки открытия файла
        cout << "Файл не удалось открыть!" << endl;
        exit(1);
    }

    int i = 0;
    while (ifile.getline(note[i].brand, 20, ';')) {
        cout << "\nЗапись №" << i + 1 << endl;
        cout << "Марка: " << note[i].brand << endl;

        ifile.getline(note[i].color, 20, ';');
        cout << "Цвет: " << note[i].color << endl;

        ifile.getline(note[i].number, 20, ';');
        cout << "Заводской номер: " << note[i].number << endl;

        ifile.getline(note[i].release_date, 20, ';');
        cout << "Дата выпуска: " << note[i].release_date << endl;

        ifile.getline(note[i].body, 20, ';');
        cout << "Тип кузова: " << note[i].body << endl;

        ifile.getline(note[i].last_check, 20, ';');
        cout << "Дата последнего техосмотра: " << note[i].last_check << endl;

        ifile.getline(note[i].owner, 20, ';');
        cout << "Владелец: " << note[i].owner << endl;

        i++;
    }
    ifile.close();
}

void searchInfo() {
    string owner; // Переменная для поиска по владельцу
    cout << "Введите имя владельца для поиска: ";
    cin >> owner;
    bool found = false; //по умолчанию считается, что владелец не найден
    for (int i = 0; i < current_size; i++) {
        if (cars[i].owner.find(owner) != string::npos) { // Если введенный владелец найден, то выводим информацию о нем
            cout << "\nИнформация по владельцу " << owner << ":" << endl;
            cout << "Марка: " << cars[i].brand << endl;
            cout << "Цвет: " << cars[i].color << endl;
            cout << "Заводской номер: " << cars[i].number << endl;
            cout << "Дата выпуска: " << cars[i].release_date << endl;
            cout << "Тип кузова: " << cars[i].body << endl;
            cout << "Дата последнего техосмотра: " << cars[i].last_check << endl;
            cout << "Владелец: " << cars[i].owner << endl;

            found = true; // Устанавливаем, что владелец найден
        }
    }
    if (!found) { // Иначе выводим сообщение об ошибке
        cout << "Нет информации о владельце " << owner << endl;
    }
}
