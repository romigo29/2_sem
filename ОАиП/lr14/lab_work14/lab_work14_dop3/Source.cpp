#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>

using namespace std;

// Функция для создания и инициализации хеш-таблицы зарезервированных слов с подсказками
unordered_map<string, string> createReservedWordsMap() {
    unordered_map<string, string> reservedWords;

    // Заполнение таблицы зарезервированными словами и их описанием (подсказками)
    reservedWords["if"] = "Условно выполняет блок кода.";
    reservedWords["else"] = "Выполняет блок кода, если условие в операторе if ложно.";
    reservedWords["for"] = "Итерирует по диапазону.";
    reservedWords["while"] = "Повторно выполняет блок кода, пока условие истинно.";
    reservedWords["do"] = "Выполняет блок кода один раз, а затем повторяет его выполнение, пока условие истинно.";
    reservedWords["break"] = "Прерывает выполнение ближайшего цикла или оператора switch.";
    reservedWords["continue"] = "Пропускает остаток текущей итерации цикла и переходит к следующей итерации.";
    reservedWords["switch"] = "Выбирает блок кода для выполнения из множества вариантов.";
    reservedWords["case"] = "Определяет блок кода в операторе switch.";
    reservedWords["default"] = "Определяет блок кода по умолчанию в операторе switch, если ни один case не совпал.";
    reservedWords["return"] = "Завершает выполнение функции и, при необходимости, возвращает значение.";
    reservedWords["void"] = "Указывает, что функция не возвращает значение.";
    reservedWords["int"] = "Объявляет переменную целочисленного типа.";
    reservedWords["float"] = "Объявляет переменную типа с плавающей запятой.";
    reservedWords["double"] = "Объявляет переменную типа с двойной точностью.";
    reservedWords["char"] = "Объявляет переменную символьного типа.";
    reservedWords["bool"] = "Объявляет переменную логического типа.";
    reservedWords["struct"] = "Определяет новый тип структуры.";
    reservedWords["typedef"] = "Создает псевдоним для существующего типа данных.";
    reservedWords["sizeof"] = "Возвращает размер переменной или типа данных.";

    return reservedWords; // Возвращаем заполненную хеш-таблицу
}

// Функция для вывода подсказки по слову
void displayHelp(const unordered_map<string, string>& reservedWords, const string& word) {
    auto it = reservedWords.find(word); // Ищем слово в хеш-таблице
    if (it != reservedWords.end()) {
        // Если слово найдено, выводим подсказку
        cout << "Подсказка для '" << word << "': " << it->second << endl;
    }
    else {
        // Если слово не найдено, сообщаем об этом
        cout << "Слово '" << word << "' не найдено среди зарезервированных слов." << endl;
    }
}

// Функция для добавления нового слова с подсказкой
void addWord(unordered_map<string, string>& reservedWords, const string& word, const string& help) {
    reservedWords[word] = help; // Добавляем новое слово и подсказку в хеш-таблицу
    cout << "Слово '" << word << "' добавлено с подсказкой: " << help << endl; // Сообщаем о добавлении
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем и инициализируем хеш-таблицу зарезервированных слов
    unordered_map<string, string> reservedWords = createReservedWordsMap();

    string input;
    while (true) {
        // Запрашиваем ввод слова у пользователя
        cout << "Введите зарезервированное слово (или 'exit' для выхода): ";
        cin >> input;
        if (input == "exit") break; // Если введено 'exit', выходим из цикла

        auto it = reservedWords.find(input); // Ищем введенное слово в хеш-таблице
        if (it != reservedWords.end()) {
            // Если слово найдено, выводим подсказку
            displayHelp(reservedWords, input);
        }
        else {
            // Если слово не найдено, предлагаем пользователю добавить его
            cout << "Слово не найдено. Хотите добавить его? (да/нет): ";
            string response;
            cin >> response;
            if (response == "да") {
                // Если пользователь соглашается, запрашиваем подсказку для нового слова
                cout << "Введите подсказку для слова '" << input << "': ";
                string help;
                cin.ignore();  // Игнорируем оставшийся '\n' в потоке ввода
                getline(cin, help); // Считываем строку с подсказкой
                addWord(reservedWords, input, help); // Добавляем новое слово и подсказку в хеш-таблицу
            }
        }
    }

    return 0;
}
