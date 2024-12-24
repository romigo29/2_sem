#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

// Структура для хранения информации о жильцах
struct Resident {
    int apartmentNumber;  // Номер квартиры
    string name;          // Имя жильца
    Resident* next;       // Указатель на следующего жильца в цепочке

    Resident(int num, const string& resName) : apartmentNumber(num), name(resName), next(nullptr) {}
};

// Хеш-функция на основе исключающего ИЛИ
int hashFunction(int key, int tableSize) {
    return key ^ ((key >> 16) ^ (key >> 8)) % tableSize; // Используется XOR для хеширования
}

// Функция для вставки нового жильца в хеш-таблицу
void insertResident(Resident** table, int tableSize, int apartmentNumber, const string& name) {
    int index = hashFunction(apartmentNumber, tableSize); // Получаем индекс для вставки
    Resident* newResident = new Resident(apartmentNumber, name); // Создаем нового жильца
    newResident->next = table[index]; // Присваиваем новому жильцу следующий элемент в цепочке
    table[index] = newResident; // Обновляем указатель на начало цепочки
}

// Функция для удаления жильца из хеш-таблицы
void removeResident(Resident** table, int tableSize, int apartmentNumber) {
    int index = hashFunction(apartmentNumber, tableSize); // Получаем индекс для поиска
    Resident* entry = table[index]; // Начинаем поиск с начала цепочки
    Resident* prev = nullptr; // Инициализируем указатель на предыдущий элемент

    // Ищем нужного жильца или достигаем конца цепочки
    while (entry != nullptr && entry->apartmentNumber != apartmentNumber) {
        prev = entry; // Сохраняем текущий элемент как предыдущий
        entry = entry->next; // Переходим к следующему элементу в цепочке
    }

    // Если жилец не найден, выводим сообщение и выходим из функции
    if (entry == nullptr) {
        cout << "Жилец не найден в квартире " << apartmentNumber << endl;
        return;
    }

    // Если удаляемый жилец находится в начале списка
    if (prev == nullptr) {
        table[index] = entry->next; // Обновляем указатель на начало цепочки
    }
    else {
        prev->next = entry->next; // Иначе пропускаем удаляемый элемент в цепочке
    }

    delete entry; // Освобождаем память, выделенную под удаляемого жильца
}

// Функция для отображения содержимого хеш-таблицы
void displayTable(Resident** table, int tableSize) {
    // Проходим по всем индексам таблицы
    for (int i = 0; i < tableSize; ++i) {
        cout << "Индекс " << i << ": ";
        Resident* entry = table[i]; // Начинаем с начала цепочки
        // Пока не достигнут конец цепочки
        while (entry != nullptr) {
            cout << "[Квартира " << entry->apartmentNumber << ": " << entry->name << "] -> ";
            entry = entry->next; // Переходим к следующему элементу в цепочке
        }
        cout << "nullptr" << endl; // Выводим nullptr, когда цепочка закончена
    }
}

// Функция для отображения меню
void displayMenu() {
    cout << "Выберите вариант:\n";
    cout << "1. Добавить жильца\n";
    cout << "2. Удалить жильца\n";
    cout << "3. Показать хеш-таблицу\n";
    cout << "4. Выйти\n";
    cout << "Введите ваш выбор: ";
}

// Главная функция
int main() {
    // Установка кодировки для работы с кириллицей в консоли Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int tableSize = 10; // Размер хеш-таблицы
    Resident* table[tableSize] = { nullptr }; // Создание массива указателей на жильцов

    // Цикл работы программы
    while (true) {
        displayMenu(); // Отображаем меню
        int choice;
        cin >> choice; // Получаем выбор пользователя

        switch (choice) {
        case 1: { // Добавить жильца
            int apartmentNumber;
            string name;
            cout << "Введите номер квартиры: ";
            cin >> apartmentNumber;
            cout << "Введите имя жильца: ";
            cin.ignore();  // Очистка буфера ввода
            getline(cin, name); // Считываем имя с пробелами
            insertResident(table, tableSize, apartmentNumber, name); // Вызываем функцию добавления
            break;
        }
        case 2: { // Удалить жильца
            int apartmentNumber;
            cout << "Введите номер квартиры для удаления: ";
            cin >> apartmentNumber;
            removeResident(table, tableSize, apartmentNumber); // Вызываем функцию удаления
            break;
        }
        case 3: // Показать хеш-таблицу
            displayTable(table, tableSize); // Вызываем функцию отображения
            break;
        case 4: // Выйти из программы
            cout << "Выход из программы.\n";
            return 0;
        default: // Некорректный ввод
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    }

    return 0;
}
