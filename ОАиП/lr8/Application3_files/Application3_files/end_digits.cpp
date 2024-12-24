#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Для использования isdigit()
using namespace std;

struct Queue {   // создаем очередь 
    int data;
    Queue* next;
};

void createQueueFromFile(Queue** begin, Queue** end, ifstream& inFile, ofstream& outFile);
void writeQueueToFile(Queue* begin, ofstream& outFile);
void deleteQueue(Queue** begin);

void createQueueFromFile(Queue** begin, Queue** end, ifstream& inFile, ofstream& outFile) {
    string line;
    while (getline(inFile, line)) { // Читаем строку из файла
        string symbols, digits;
        for (char c : line) {
            if (isdigit(c)) {
                digits += c; // Сохраняем цифры
            }
            else if (!isspace(c)) {
                symbols += c; // Сохраняем символы, игнорируя пробелы
            }
        }
        if (!digits.empty()) {
            Queue* temp = new Queue; // Создаем новый элемент очереди
            temp->data = stoi(digits);  // Преобразуем строку с цифрами в число и записываем в элемент
            temp->next = nullptr;  // Указываем, что следующий элемент пустой

            if (*begin == nullptr) {
                *begin = temp;  // Если начало очереди пустое, устанавливаем начало
            }
            else {
                (*end)->next = temp;  // Иначе устанавливаем связь с последним элементом
            }
            *end = temp;  // Устанавливаем конец очереди на новый элемент
            symbols += " " + digits; // Добавляем цифры в конец строки
        }
        symbols += "\n"; // Добавляем символ перевода строки
        outFile << symbols << " " << endl; // Записываем строку с цифрами в конец файла
    }
    cout << "Очередь успешно создана" << endl;
}

void writeQueueToFile(Queue* begin, ofstream& outFile) {
    Queue* temp = begin;

    while (temp != nullptr) {  // Проходим по очереди и записываем числа в файл
        outFile << temp->data << " ";
        temp = temp->next;
    }
    outFile << endl;
    cout << "Числа из очереди успешно записаны в файл" << endl;
}

void deleteQueue(Queue** begin) {
    Queue* temp;
    while (*begin != nullptr) {  // Удаляем элементы очереди
        temp = *begin;
        *begin = (*begin)->next;
        delete temp;
    }
    cout << "Очередь успешно удалена" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    Queue* begin = nullptr, * end = nullptr; // Создаем начало и конец очереди

    ifstream inFile("f.txt"); // Открываем файл для чтения
    ofstream outFile("g.txt"); // Открываем файл для записи

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    createQueueFromFile(&begin, &end, inFile, outFile); // Создаем очередь из чисел файла f

    inFile.close();
    outFile.close();

    deleteQueue(&begin); // Удаляем очередь

    return 0;
}
