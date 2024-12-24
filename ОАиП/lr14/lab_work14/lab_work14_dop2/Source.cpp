#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Функция для создания хеш-таблицы из слов текстового файла
void createHashTable(unordered_map<string, int>& hashTable, const string& filename) {
    ifstream file(filename); // Открываем файл для чтения
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return;
    }

    string word;
    while (file >> word) {
        hashTable[word]++; // Увеличиваем счетчик вхождений слова в хеш-таблице
    }

    file.close(); // Закрываем файл
}

// Функция для вывода хеш-таблицы на экран
void printHashTable(const unordered_map<string, int>& hashTable) {
    for (const auto& entry : hashTable) {
        cout << entry.first << ": " << entry.second << endl; // Выводим слово и количество его вхождений
    }
}

// Функция для поиска слова в хеш-таблице
void searchWord(const unordered_map<string, int>& hashTable, const string& word) {
    auto it = hashTable.find(word); // Ищем слово в хеш-таблице
    if (it != hashTable.end()) {
        cout << "Слово '" << word << "' найдено с частотой: " << it->second << endl;
    }
    else {
        cout << "Слово '" << word << "' не найдено в хеш-таблице." << endl;
    }
}

// Функция для удаления всех слов, начинающихся на указанную букву
void deleteWordsStartingWith(unordered_map<string, int>& hashTable, char letter) {
    for (auto it = hashTable.begin(); it != hashTable.end(); ) {
        if (it->first[0] == letter) {
            it = hashTable.erase(it); // Удаляем слово и получаем итератор на следующий элемент
        }
        else {
            ++it; // Переходим к следующему элементу
        }
    }
}

int main() {
    // Задаем размерность таблицы (не используется напрямую, так как unordered_map управляет размером сам)
    int tableSize;
    cout << "Введите предполагаемое количество различных слов в файле (размерность хеш-таблицы): ";
    cin >> tableSize;

    // Создаем хеш-таблицу для хранения слов и их частоты
    unordered_map<string, int> hashTable;
    hashTable.reserve(tableSize); // Резервируем место в хеш-таблице для повышения эффективности

    // Считываем слова из файла и создаем хеш-таблицу
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;
    createHashTable(hashTable, filename);

    // Выводим построенную хеш-таблицу на экран
    cout << "Построенная хеш-таблица:" << endl;
    printHashTable(hashTable);

    // Осуществляем поиск слова, введенного пользователем
    string word;
    cout << "Введите слово для поиска: ";
    cin >> word;
    searchWord(hashTable, word);

    // Удаляем все слова, начинающиеся на указанную букву
    char letter;
    cout << "Введите букву для удаления всех слов, начинающихся на нее: ";
    cin >> letter;
    deleteWordsStartingWith(hashTable, letter);

    // Выводим хеш-таблицу после удаления слов
    cout << "Хеш-таблица после удаления слов, начинающихся на букву '" << letter << "':" << endl;
    printHashTable(hashTable);

    return 0;
}
