#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

// ��������� ��� �������� ���������� � �������
struct Resident {
    int apartmentNumber;  // ����� ��������
    string name;          // ��� ������
    Resident* next;       // ��������� �� ���������� ������ � �������

    Resident(int num, const string& resName) : apartmentNumber(num), name(resName), next(nullptr) {}
};

// ���-������� �� ������ ������������ ���
int hashFunction(int key, int tableSize) {
    return key ^ ((key >> 16) ^ (key >> 8)) % tableSize; // ������������ XOR ��� �����������
}

// ������� ��� ������� ������ ������ � ���-�������
void insertResident(Resident** table, int tableSize, int apartmentNumber, const string& name) {
    int index = hashFunction(apartmentNumber, tableSize); // �������� ������ ��� �������
    Resident* newResident = new Resident(apartmentNumber, name); // ������� ������ ������
    newResident->next = table[index]; // ����������� ������ ������ ��������� ������� � �������
    table[index] = newResident; // ��������� ��������� �� ������ �������
}

// ������� ��� �������� ������ �� ���-�������
void removeResident(Resident** table, int tableSize, int apartmentNumber) {
    int index = hashFunction(apartmentNumber, tableSize); // �������� ������ ��� ������
    Resident* entry = table[index]; // �������� ����� � ������ �������
    Resident* prev = nullptr; // �������������� ��������� �� ���������� �������

    // ���� ������� ������ ��� ��������� ����� �������
    while (entry != nullptr && entry->apartmentNumber != apartmentNumber) {
        prev = entry; // ��������� ������� ������� ��� ����������
        entry = entry->next; // ��������� � ���������� �������� � �������
    }

    // ���� ����� �� ������, ������� ��������� � ������� �� �������
    if (entry == nullptr) {
        cout << "����� �� ������ � �������� " << apartmentNumber << endl;
        return;
    }

    // ���� ��������� ����� ��������� � ������ ������
    if (prev == nullptr) {
        table[index] = entry->next; // ��������� ��������� �� ������ �������
    }
    else {
        prev->next = entry->next; // ����� ���������� ��������� ������� � �������
    }

    delete entry; // ����������� ������, ���������� ��� ���������� ������
}

// ������� ��� ����������� ����������� ���-�������
void displayTable(Resident** table, int tableSize) {
    // �������� �� ���� �������� �������
    for (int i = 0; i < tableSize; ++i) {
        cout << "������ " << i << ": ";
        Resident* entry = table[i]; // �������� � ������ �������
        // ���� �� ��������� ����� �������
        while (entry != nullptr) {
            cout << "[�������� " << entry->apartmentNumber << ": " << entry->name << "] -> ";
            entry = entry->next; // ��������� � ���������� �������� � �������
        }
        cout << "nullptr" << endl; // ������� nullptr, ����� ������� ���������
    }
}

// ������� ��� ����������� ����
void displayMenu() {
    cout << "�������� �������:\n";
    cout << "1. �������� ������\n";
    cout << "2. ������� ������\n";
    cout << "3. �������� ���-�������\n";
    cout << "4. �����\n";
    cout << "������� ��� �����: ";
}

// ������� �������
int main() {
    // ��������� ��������� ��� ������ � ���������� � ������� Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int tableSize = 10; // ������ ���-�������
    Resident* table[tableSize] = { nullptr }; // �������� ������� ���������� �� �������

    // ���� ������ ���������
    while (true) {
        displayMenu(); // ���������� ����
        int choice;
        cin >> choice; // �������� ����� ������������

        switch (choice) {
        case 1: { // �������� ������
            int apartmentNumber;
            string name;
            cout << "������� ����� ��������: ";
            cin >> apartmentNumber;
            cout << "������� ��� ������: ";
            cin.ignore();  // ������� ������ �����
            getline(cin, name); // ��������� ��� � ���������
            insertResident(table, tableSize, apartmentNumber, name); // �������� ������� ����������
            break;
        }
        case 2: { // ������� ������
            int apartmentNumber;
            cout << "������� ����� �������� ��� ��������: ";
            cin >> apartmentNumber;
            removeResident(table, tableSize, apartmentNumber); // �������� ������� ��������
            break;
        }
        case 3: // �������� ���-�������
            displayTable(table, tableSize); // �������� ������� �����������
            break;
        case 4: // ����� �� ���������
            cout << "����� �� ���������.\n";
            return 0;
        default: // ������������ ����
            cout << "�������� �����. ���������� ��� ���.\n";
            break;
        }
    }

    return 0;
}
