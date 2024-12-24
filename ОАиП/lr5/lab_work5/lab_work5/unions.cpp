#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;
#define LIMIT 100 // ������������ ���������� ����� ��� ������� ���������
// ���������
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

Students university[LIMIT]; // ������ university
int current_size = 0; // ������� ������ �������
// ��������� �������
void inputInfo();
void outputInfo();
void searchInfo();
void deleteInfo();
// ������� �������
int main() {
    SetConsoleOutputCP(1251); // ��� ������������� ��������� ��� ������ � ������
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "\n������� ������� ������ ����������: \n";
        cout << "0. ����� �� ����������\n";
        cout << "1. ���� ��������� ��������� � ����������\n";
        cout << "2. ����� ��������� ��������� � ���������� ����\n";
        cout << "3. �������� �������� ����������������� ����������\n";
        cout << "4. ����� ����������\n";
        cin >> choice;
        switch (choice) {
        case 1: // ���� ��������� ��������� � ����������
            inputInfo();
            break;
        case 2: // ����� ��������� ��������� � ���������� ����
            outputInfo();
            break;
        case 3: // �������� �������� ����������������� ����������
            deleteInfo();
            break;
        case 4: // ����� ����������
            searchInfo();
            break;
        case 0: // ����� �� ���������
            exit(0);
        default:
            cout << "������� ������������ ��������. " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
// ���� ����������
void inputInfo() {
    if (current_size < LIMIT) { // ���� ������ �� ������� �� ������� ���������, �� ������ �����. ����������
        cin.ignore();
        cout << "������� ��� ��������: ";
        cin.getline(university[current_size].full_name, 50);

        cout << "������� ���� ����������� � ������� �� �� ����: ";
        int day, month, year;
        cin >> day >> month >> year;
        university[current_size].entrance.day = day;
        university[current_size].entrance.month = month;
        university[current_size].entrance.year = year;

        int faculty;
        cout << "�������� ��������� (0 - ���, 1 - ���, 2 - ���): ";
        cin >> faculty;
        university[current_size].faculty = static_cast<Faculties>(faculty);

        cin.ignore();
        cout << "������� �������������: ";
        cin.getline(university[current_size].speciality, 50);

        cout << "������� ����� ������: ";
        cin >> university[current_size].group;

        cout << "������� ������� ���� ��������: ";
        cin >> university[current_size].average_point;
  
        cout << "������� ��������� ������. " << endl;
        current_size++; // ����������� current_size ����� ���������� ���� ����� ������ �������� �������
    }
    else { // ����� ������� ��������� � ������������
        cout << "��������� �����������!" << endl;
    }
}
// ����� ����������
void outputInfo() {
    for (int i = 0; i < current_size; i++) { // ���������� ������� ���������� � �������
        cout << "\n������� �" << i + 1 << endl;
        cout << "���: " << university[i].full_name << endl;
        cout << "���� �����������: " << university[i].entrance.day << "." << university[i].entrance.month << "." << university[i].entrance.year << endl;
        cout << "���������: ";
        switch (university[i].faculty) {
        case 0: cout << "��������� �������������� ����������" << endl; break;
        case 1: cout << "���������-������������� ���������" << endl; break;
        case 2: cout << "��������� ��������������� � �����������������" << endl; break;
        default: cout << "�� �����������" << endl; break;
        }
        cout << "�������������: " << university[i].speciality << endl;
        cout << "������: " << university[i].group << endl;
        cout << "������� ����: " << university[i].average_point << endl;
    }
}
// ����� ��������� �� �������� �����
void searchInfo() {
    float GPA; // ���������� ��� �������� ����� ��������
    cout << "������� ������� ���� ��������, �� �������� ������ ����� ���������� ���������: ";
    cin >> GPA;
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (GPA == university[i].average_point) { // ���� ����� ������� ������, �� ������� ���������� � ���
            found = true;
            cout << "���: " << university[i].full_name << endl;
            cout << "���� �����������: " << university[i].entrance.day << "." << university[i].entrance.month << "." << university[i].entrance.year << endl;
            cout << "���������: ";
            switch (university[i].faculty) {
            case 0: cout << "��������� �������������� ����������" << endl; break;
            case 1: cout << "���������-������������� ���������" << endl; break;
            case 2: cout << "��������� ��������������� � �����������������" << endl; break;
            default: cout << "�� �����������" << endl; break;
            }
            cout << "�������������: " << university[i].speciality << endl;
            cout << "������: " << university[i].group << endl;
            cout << "������� ����: " << university[i].average_point << endl;
            break;
        }
    }
    if (!found) {
        cout << "��������� � ����� ������� ������ �� �������." << endl;
    }
}
// �������� ��������� �� ���������
void deleteInfo() {
    float GPA; // ���������� ��� �������� ����� ��������
    cout << "������� ������� ���� ��������, �������� ������ ������� ��� �� ���������: ";
    cin >> GPA;
    bool found = false; // �� ��������� ���������, ��� ������� �� ������
    for (int i = 0; i < current_size; i++) {
        if (GPA == university[i].average_point) { // ���� ����� ������� ������, �� ������� ��� �� ���������
            found = true;
            for (int j = i; j < current_size - 1; j++) {
                university[j] = university[j + 1];
            }
            current_size--;
            cout << "����������� ���������� �������." << endl;
            break;
        }
    }
    if (!found) {
        cout << "��������� � ����� ������� ������ �� �������." << endl;
    }
}
