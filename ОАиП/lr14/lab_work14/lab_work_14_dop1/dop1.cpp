#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>

using namespace std;

// ������� ��� �������� ���-�������, ���������� ����� � ���������� �� ���������
void createHashTable(unordered_map<char, int>& hashTable, const string& input) {
    for (char ch : input) {
        if (isalpha(ch)) { // ���������, �������� �� ������ ������
            hashTable[ch]++; // ����������� ������� ��������� ����� � ���-�������
        }
    }
}

// ������� ��� ������ ���-������� �� �����
void printHashTable(const unordered_map<char, int>& hashTable) {
    for (const auto& entry : hashTable) {
        cout << entry.first << ": " << entry.second << endl; // ������� ����� � ���������� �� ���������
    }
}

// ������� ��� ������ ����� � ���-�������
void searchLetter(const unordered_map<char, int>& hashTable, char letter) {
    auto it = hashTable.find(letter); // ���� ����� � ���-�������
    if (it != hashTable.end()) {
        cout << "����� '" << letter << "' ������� � ��������: " << it->second << endl;
    }
    else {
        cout << "����� '" << letter << "' �� ������� � ���-�������." << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ����������� � ������������ ���� ������
    string input;
    cout << "������� ������: ";
    getline(cin, input);

    // ������� ���-������� ��� �������� ���� � �� �������
    unordered_map<char, int> hashTable;

    // ��������� ���-������� �� ������ ��������� ������
    createHashTable(hashTable, input);

    // ������� ����������� ���-������� �� �����
    cout << "����������� ���-�������:" << endl;
    printHashTable(hashTable);

    // ������������ ����� �����, ��������� �������������
    char letter;
    cout << "������� ����� ��� ������: ";
    cin >> letter;
    searchLetter(hashTable, letter);

    return 0;
}
