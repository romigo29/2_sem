#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>

using namespace std;

// Функция для создания хеш-таблицы, содержащей буквы и количество их вхождений
void createHashTable(unordered_map<char, int>& hashTable, const string& input) {
    for (char ch : input) {
        if (isalpha(ch)) { // Проверяем, является ли символ буквой
            hashTable[ch]++; // Увеличиваем счетчик вхождений буквы в хеш-таблице
        }
    }
}

// Функция для вывода хеш-таблицы на экран
void printHashTable(const unordered_map<char, int>& hashTable) {
    for (const auto& entry : hashTable) {
        cout << entry.first << ": " << entry.second << endl; // Выводим букву и количество ее вхождений
    }
}

// Функция для поиска буквы в хеш-таблице
void searchLetter(const unordered_map<char, int>& hashTable, char letter) {
    auto it = hashTable.find(letter); // Ищем букву в хеш-таблице
    if (it != hashTable.end()) {
        cout << "Буква '" << letter << "' найдена с частотой: " << it->second << endl;
    }
    else {
        cout << "Буква '" << letter << "' не найдена в хеш-таблице." << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Запрашиваем у пользователя ввод строки
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    // Создаем хеш-таблицу для хранения букв и их частоты
    unordered_map<char, int> hashTable;

    // Заполняем хеш-таблицу на основе введенной строки
    createHashTable(hashTable, input);

    // Выводим построенную хеш-таблицу на экран
    cout << "Построенная хеш-таблица:" << endl;
    printHashTable(hashTable);

    // Осуществляем поиск буквы, введенной пользователем
    char letter;
    cout << "Введите букву для поиска: ";
    cin >> letter;
    searchLetter(hashTable, letter);

    return 0;
}
