#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;
#define LIMIT 100 // максимальное количество стран для массива структуру
// структура
enum Faculties {
    INFORMATION_TECHNOLOGY = 0,
    ENGINEERING_ECONOMICS,
    PRINTTECHNOLOGIES
};

struct Students {
    char full_name[50];
    struct entrance_date {
        unsigned day : 5;
        unsigned month : 4;
        unsigned year : 12;
    } entrance;
    Faculties faculty;
    char speciality[40];
    short int group;
    float average_point;
};

Students university[LIMIT]; // массив university
int current_size = 0; // текущий размер массива
// прототипы функций
void inputInfo();
void outputInfo();
void searchInfo();
void deleteInfo();
// главная функция
int main() {
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
        cin >> choice;
        switch (choice) {
        case 1: // Ввод элементов структуры с клавиатуры
            inputInfo();
            break;
        case 2: // Вывод элементов структуры в консольное окно
            outputInfo();
            break;
        case 3: // Удаление заданной структурированной переменной
            deleteInfo();
            break;
        case 4: // Поиск информации
            searchInfo();
            break;
        case 0: // Выход из программы
            exit(0);
        default:
            cout << "Введено некорректное значение. " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
// ввод информации
void inputInfo() {
    if (current_size < LIMIT) { // если массив не выходит за пределы заданного, то вводим соотв. информацию
        cin.ignore();
        cout << "Введите ФИО студента: ";
        cin.getline(university[current_size].full_name, 50);

        cout << "Введите дату поступления в формате ДД ММ ГГГГ: ";
        int day, month, year;
        cin >> day >> month >> year;
        university[current_size].entrance.day = day;
        university[current_size].entrance.month = month;
        university[current_size].entrance.year = year;

        int faculty;
        cout << "Выберите факультет (0 - ФИТ, 1 - ИЭФ, 2 - ПИМ): ";
        cin >> faculty;
        university[current_size].faculty = static_cast<Faculties>(faculty);

        cin.ignore();
        cout << "Введите специальность: ";
        cin.getline(university[current_size].speciality, 50);

        cout << "Введите номер группы: ";
        cin >> university[current_size].group;

        cout << "Введите средний балл студента: ";
        cin >> university[current_size].average_point;
  
        cout << "Элемент структуры создан. " << endl;
        current_size++; // увеличиваем current_size после заполнения всех полей нового элемента массива
    }
    else { // иначе выводим сообщение о переполнении
        cout << "Структура переполнена!" << endl;
    }
}
// вывод информации
void outputInfo() {
    for (int i = 0; i < current_size; i++) { // поочередно выводим информацию о странах
        cout << "\nСтудент №" << i + 1 << endl;
        cout << "ФИО: " << university[i].full_name << endl;
        cout << "Дата поступления: " << university[i].entrance.day << "." << university[i].entrance.month << "." << university[i].entrance.year << endl;
        cout << "Факультет: ";
        switch (university[i].faculty) {
        case 0: cout << "Факультет информационных технологий" << endl; break;
        case 1: cout << "Инженерно-экономический факультет" << endl; break;
        case 2: cout << "Факультет принттехнологий и медиакоммуникаций" << endl; break;
        default: cout << "не определился" << endl; break;
        }
        cout << "Специальность: " << university[i].speciality << endl;
        cout << "Группа: " << university[i].group << endl;
        cout << "Средний балл: " << university[i].average_point << endl;
    }
}
// поиск студентов по среднему баллу
void searchInfo() {
    float GPA; // переменная для среднего балла студента
    cout << "Введите средний балл студента, по которому хотите найти информацию подробнее: ";
    cin >> GPA;
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (GPA == university[i].average_point) { // если такой студент найден, то выводим информацию о нем
            found = true;
            cout << "ФИО: " << university[i].full_name << endl;
            cout << "Дата поступления: " << university[i].entrance.day << "." << university[i].entrance.month << "." << university[i].entrance.year << endl;
            cout << "Факультет: ";
            switch (university[i].faculty) {
            case 0: cout << "Факультет информационных технологий" << endl; break;
            case 1: cout << "Инженерно-экономический факультет" << endl; break;
            case 2: cout << "Факультет принттехнологий и медиакоммуникаций" << endl; break;
            default: cout << "не определился" << endl; break;
            }
            cout << "Специальность: " << university[i].speciality << endl;
            cout << "Группа: " << university[i].group << endl;
            cout << "Средний балл: " << university[i].average_point << endl;
            break;
        }
    }
    if (!found) {
        cout << "Студентов с таким средним баллом не найдено." << endl;
    }
}
// удаление студентов из структуры
void deleteInfo() {
    float GPA; // переменная для среднего балла студента
    cout << "Введите средний балл студента, которого хотите удалить его из структуры: ";
    cin >> GPA;
    bool found = false; // по умолчанию считается, что студент не найден
    for (int i = 0; i < current_size; i++) {
        if (GPA == university[i].average_point) { // если такой студент найден, то удаляем его из структуры
            found = true;
            for (int j = i; j < current_size - 1; j++) {
                university[j] = university[j + 1];
            }
            current_size--;
            cout << "Структурная переменная удалена." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Студентов с таким средним баллом не найдено." << endl;
    }
}
