#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string> 
#define LIMIT 100 // ������������ ���������� ��������� ��� ������� ��������

using namespace std;

// �����������
union Ucars {
    char brand[20];
    char color[20];
    char number[20];
    char release_date[20];
    char body[20];
    char last_check[20];
    char owner[20];
} note[LIMIT];

// ���������
struct Cars {
    string brand;
    string color;
    string number;
    string release_date;
    string body;
    string last_check;
    string owner;
} cars[LIMIT];

int current_size = 0; // ������� ������ �������

// ��������� �������
void inputInfo();
void outputInfo();
void searchInfo();

int main() {
    SetConsoleOutputCP(1251); // ��� ������������� ��������� ��� ������ � ������
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "\n������� ������� ������ ����������: \n";
        cout << "0. ����� �� ����������\n";
        cout << "1. ���� ������ � ���������� � ������ ���������� � ����\n";
        cout << "2. ������ ���������� �� ����� � ����� �� �� ����� �\n";
        cout << "3. ����� ���������� �� ���������\n";
        cin >> choice;
        switch (choice) {
        case 1: { // ���� ��������� ��������� � ���������� � ������ � ����
            inputInfo();
            break;
        }
        case 2: { // ������ �� ����� � ����� ��������� ��������� � ���������� ����
            outputInfo();
            break;
        }
        case 3: { // ����� ���������� �� ���������
            searchInfo();
            break;
        }
        case 0: { // ����� �� ���������
            exit(0);
            break;
        }
        default: {
            cout << "������� ������������ ��������. " << endl;
            break;
        }
        }
    } while (choice != 0);
    return 0;
}

void inputInfo() {
    if (current_size < LIMIT) { // ���� ������ �� ������� �� ������� ���������, �� ������ �����. ����������
        cout << "������� ������� ������ �������? - ";
        short int amount;
        cin >> amount;
        cin.ignore(); // ������� ������ �����

        ofstream ofile("cars.txt"); // ������� ���� ��� ���������� ����� ������
        if (!ofile) { // � ������ ������ �������� �����
            cout << "���� �� ������� �������!" << endl;
            exit(1);
        }

        // ���� ���������� � ���������� � ������ �� � ����
        for (int i = 0; i < amount; i++) {
            cout << "������ �" << i + 1 << ": " << endl;
            cout << "������� ����� ����������: ";
            cin.getline(note[i].brand, 20);
            ofile << note[i].brand << ";";
            cars[i].brand = note[i].brand;

            cout << "������� ����: ";
            cin.getline(note[i].color, 20);
            ofile << note[i].color << ";";
            cars[i].color = note[i].color;

            cout << "������� ��������� �����: ";
            cin.getline(note[i].number, 20);
            ofile << note[i].number << ";";
            cars[i].number = note[i].number;

            cout << "������� ���� �������: ";
            cin.getline(note[i].release_date, 20);
            ofile << note[i].release_date << ";";
            cars[i].release_date = note[i].release_date;

            cout << "������� ��� ������: ";
            cin.getline(note[i].body, 20);
            ofile << note[i].body << ";";
            cars[i].body = note[i].body;

            cout << "������� ���������� �������: ";
            cin.getline(note[i].last_check, 20);
            ofile << note[i].last_check << ";";
            cars[i].last_check = note[i].last_check;

            cout << "������� ���������: ";
            cin.getline(note[i].owner, 20);
            cars[i].owner = note[i].owner;
            ofile << note[i].last_check << ";" << endl;
            
            current_size++;
        }
        cout << "���������� ������� �������� � ����" << endl;
        ofile.close(); // �������� �����
    }
    else { // ����� ������� ��������� � ������������
        cout << "��������� �����������!" << endl;
    }
}

void outputInfo() {
    ifstream ifile("cars.txt"); // �������� ������� ������ ifstream ��� ������
    if (!ifile) { // � ������ ������ �������� �����
        cout << "���� �� ������� �������!" << endl;
        exit(1);
    }

    int i = 0;
    while (ifile.getline(note[i].brand, 20, ';')) {
        cout << "\n������ �" << i + 1 << endl;
        cout << "�����: " << note[i].brand << endl;

        ifile.getline(note[i].color, 20, ';');
        cout << "����: " << note[i].color << endl;

        ifile.getline(note[i].number, 20, ';');
        cout << "��������� �����: " << note[i].number << endl;

        ifile.getline(note[i].release_date, 20, ';');
        cout << "���� �������: " << note[i].release_date << endl;

        ifile.getline(note[i].body, 20, ';');
        cout << "��� ������: " << note[i].body << endl;

        ifile.getline(note[i].last_check, 20, ';');
        cout << "���� ���������� ����������: " << note[i].last_check << endl;

        ifile.getline(note[i].owner, 20, ';');
        cout << "��������: " << note[i].owner << endl;

        i++;
    }
    ifile.close();
}

void searchInfo() {
    string owner; // ���������� ��� ������ �� ���������
    cout << "������� ��� ��������� ��� ������: ";
    cin >> owner;
    bool found = false; //�� ��������� ���������, ��� �������� �� ������
    for (int i = 0; i < current_size; i++) {
        if (cars[i].owner.find(owner) != string::npos) { // ���� ��������� �������� ������, �� ������� ���������� � ���
            cout << "\n���������� �� ��������� " << owner << ":" << endl;
            cout << "�����: " << cars[i].brand << endl;
            cout << "����: " << cars[i].color << endl;
            cout << "��������� �����: " << cars[i].number << endl;
            cout << "���� �������: " << cars[i].release_date << endl;
            cout << "��� ������: " << cars[i].body << endl;
            cout << "���� ���������� ����������: " << cars[i].last_check << endl;
            cout << "��������: " << cars[i].owner << endl;

            found = true; // �������������, ��� �������� ������
        }
    }
    if (!found) { // ����� ������� ��������� �� ������
        cout << "��� ���������� � ��������� " << owner << endl;
    }
}
