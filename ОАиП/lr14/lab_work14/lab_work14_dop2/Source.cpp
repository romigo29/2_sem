#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// ������� ��� �������� ���-������� �� ���� ���������� �����
void createHashTable(unordered_map<string, int>& hashTable, const string& filename) {
    ifstream file(filename); // ��������� ���� ��� ������
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����." << endl;
        return;
    }

    string word;
    while (file >> word) {
        hashTable[word]++; // ����������� ������� ��������� ����� � ���-�������
    }

    file.close(); // ��������� ����
}

// ������� ��� ������ ���-������� �� �����
void printHashTable(const unordered_map<string, int>& hashTable) {
    for (const auto& entry : hashTable) {
        cout << entry.first << ": " << entry.second << endl; // ������� ����� � ���������� ��� ���������
    }
}

// ������� ��� ������ ����� � ���-�������
void searchWord(const unordered_map<string, int>& hashTable, const string& word) {
    auto it = hashTable.find(word); // ���� ����� � ���-�������
    if (it != hashTable.end()) {
        cout << "����� '" << word << "' ������� � ��������: " << it->second << endl;
    }
    else {
        cout << "����� '" << word << "' �� ������� � ���-�������." << endl;
    }
}

// ������� ��� �������� ���� ����, ������������ �� ��������� �����
void deleteWordsStartingWith(unordered_map<string, int>& hashTable, char letter) {
    for (auto it = hashTable.begin(); it != hashTable.end(); ) {
        if (it->first[0] == letter) {
            it = hashTable.erase(it); // ������� ����� � �������� �������� �� ��������� �������
        }
        else {
            ++it; // ��������� � ���������� ��������
        }
    }
}

int main() {
    // ������ ����������� ������� (�� ������������ ��������, ��� ��� unordered_map ��������� �������� ���)
    int tableSize;
    cout << "������� �������������� ���������� ��������� ���� � ����� (����������� ���-�������): ";
    cin >> tableSize;

    // ������� ���-������� ��� �������� ���� � �� �������
    unordered_map<string, int> hashTable;
    hashTable.reserve(tableSize); // ����������� ����� � ���-������� ��� ��������� �������������

    // ��������� ����� �� ����� � ������� ���-�������
    string filename;
    cout << "������� ��� �����: ";
    cin >> filename;
    createHashTable(hashTable, filename);

    // ������� ����������� ���-������� �� �����
    cout << "����������� ���-�������:" << endl;
    printHashTable(hashTable);

    // ������������ ����� �����, ���������� �������������
    string word;
    cout << "������� ����� ��� ������: ";
    cin >> word;
    searchWord(hashTable, word);

    // ������� ��� �����, ������������ �� ��������� �����
    char letter;
    cout << "������� ����� ��� �������� ���� ����, ������������ �� ���: ";
    cin >> letter;
    deleteWordsStartingWith(hashTable, letter);

    // ������� ���-������� ����� �������� ����
    cout << "���-������� ����� �������� ����, ������������ �� ����� '" << letter << "':" << endl;
    printHashTable(hashTable);

    return 0;
}
