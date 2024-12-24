#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // ��� ������������� isdigit()
using namespace std;

struct Queue {   // ������� ������� 
    int data;
    Queue* next;
};

void createQueueFromFile(Queue** begin, Queue** end, ifstream& inFile, ofstream& outFile);
void writeQueueToFile(Queue* begin, ofstream& outFile);
void deleteQueue(Queue** begin);

void createQueueFromFile(Queue** begin, Queue** end, ifstream& inFile, ofstream& outFile) {
    string line;
    while (getline(inFile, line)) { // ������ ������ �� �����
        string symbols, digits;
        for (char c : line) {
            if (isdigit(c)) {
                digits += c; // ��������� �����
            }
            else if (!isspace(c)) {
                symbols += c; // ��������� �������, ��������� �������
            }
        }
        if (!digits.empty()) {
            Queue* temp = new Queue; // ������� ����� ������� �������
            temp->data = stoi(digits);  // ����������� ������ � ������� � ����� � ���������� � �������
            temp->next = nullptr;  // ���������, ��� ��������� ������� ������

            if (*begin == nullptr) {
                *begin = temp;  // ���� ������ ������� ������, ������������� ������
            }
            else {
                (*end)->next = temp;  // ����� ������������� ����� � ��������� ���������
            }
            *end = temp;  // ������������� ����� ������� �� ����� �������
            symbols += " " + digits; // ��������� ����� � ����� ������
        }
        symbols += "\n"; // ��������� ������ �������� ������
        outFile << symbols << " " << endl; // ���������� ������ � ������� � ����� �����
    }
    cout << "������� ������� �������" << endl;
}

void writeQueueToFile(Queue* begin, ofstream& outFile) {
    Queue* temp = begin;

    while (temp != nullptr) {  // �������� �� ������� � ���������� ����� � ����
        outFile << temp->data << " ";
        temp = temp->next;
    }
    outFile << endl;
    cout << "����� �� ������� ������� �������� � ����" << endl;
}

void deleteQueue(Queue** begin) {
    Queue* temp;
    while (*begin != nullptr) {  // ������� �������� �������
        temp = *begin;
        *begin = (*begin)->next;
        delete temp;
    }
    cout << "������� ������� �������" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    Queue* begin = nullptr, * end = nullptr; // ������� ������ � ����� �������

    ifstream inFile("f.txt"); // ��������� ���� ��� ������
    ofstream outFile("g.txt"); // ��������� ���� ��� ������

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "������ �������� ������!" << endl;
        return 1;
    }

    createQueueFromFile(&begin, &end, inFile, outFile); // ������� ������� �� ����� ����� f

    inFile.close();
    outFile.close();

    deleteQueue(&begin); // ������� �������

    return 0;
}
