#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
//����������� ������
struct list {
    int number;
    list* next;
};
//��������� �������
void insertData(list*&, int);
void printList(list*);
void getSum(list*);
int deleteData(list*&, int);
int searchData(list*, int);
int isEmpty(list*);
void toFile(list*);
void fromFile(list*&);
// ������� �������
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    list* first = nullptr; //��������� �� ������ ������������ ������
    int choice, value;
    do {
        cout << "�������� ������� ������ ����������:" << endl;
        cout << " 1 - ���� �����" << endl;
        cout << " 2 - ����� ������ � ���������� ����" << endl;
        cout << " 3 - ����� ����� ������������� �����, �������������� �� 7" << endl;
        cout << " 4 - �������� �����" << endl;
        cout << " 5 - ����� �����" << endl;
        cout << " 6 - ������ ������ � ����" << endl;
        cout << " 7 - ���������� ������ �� �����" << endl;
        cout << " 0 - �����" << endl;
        cout << "��� �����: ";
        cin >> choice;
        switch (choice) {
        case 1: {  //���� �����
            cout << "������� �����: ";
            cin >> value;
            insertData(first, value);
            break;
        }
        case 2: {  //������� �������� ������
            if (!isEmpty(first)) {
                printList(first);
            }
            else {
                cout << "������ ����" << endl;
            }
            break;
        }
        case 3: {  //��������� ������� �������� ������������� ����� ������
            if (!isEmpty(first)) {
                getSum(first);
            }
            else {
                cout << "������ ����" << endl;
            }
            break;
        }
        case 4: {  // ������� ����� �� ������
            if (!isEmpty(first)) {
                cout << "������� ��������� �����: ";
                cin >> value;
                if (deleteData(first, value)) {
                    cout << "������� ����� " << value << endl;
                    printList(first);
                }
                else {
                    cout << "����� �� �������" << endl;
                }
            }
            else {
                cout << "������ ����" << endl;
            }
            break;
        }
        case 5: {  //����� ����� � �������
            int search;
            cout << "������� ����� ��� ������: ";
            cin >> search;
            if (searchData(first, search)) {
                cout << "��������� ����� ���� � ������." << endl;
            }
            else {
                cout << "���������� ����� ��� � ������." << endl;
            }
            break;
        }
        case 6: {  //������ ������ � ����
            toFile(first);
            break;
        }
        case 7: {  //������ ������ �� �����
            fromFile(first);
            break;
        }
        case 0: {  //����� �� ���������
            cout << "����� ���������" << endl;
            break;
        }
        default: {  //� ������ ��������� �����
            cout << "������������ �����" << endl;
            break;
        }
        }
    } while (choice != 0);
    //�������� ������, ������� �������
    list* temp;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete(temp);
    }
    return 0;
}
// ���������� ����� value � ������
void insertData(list*& p, int value) {
    list* newP = new list; //��������� ����� ��� ������ ������ � �������� ��������� �� ���
    if (newP != nullptr) {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else {
        cout << "�������� ���������� �� ���������" << endl;
    }
}
// ����� ������
void printList(list* p) {
    if (p == nullptr) { //���� ����� �� ������ ������
        cout << "������ ����" << endl;
    }
    else {
        cout << "������:" << endl;
        while (p != nullptr) { //���� �� ����� �� ������ ������,
            cout << p->number << " "; //������� ��������
            p = p->next;  //��������� � ������ �������� �� ������
        }
        cout << "NULL" << endl;
    }
}
// ����� ����� ������������� �����, �������������� �� 7
void getSum(list* p) {
    int sum = 0, counter_pos = 0;
    while (p != nullptr) {
        if (p->number > 0 && p->number % 10 == 7) {
            sum += p->number;
            counter_pos++;
        }
        p = p->next;
    }
    if (counter_pos == 0) {
        cout << "� ������ ��� ������������� �����, �������������� �� 7." << endl;
    }
    else {
        cout << "����� ������������� �����, �������������� �� 7: " << sum << endl;
    }
}
// �������� �����
int deleteData(list*& p, int value) {
    list* previous = nullptr, * current = p, * temp;
    while (current != nullptr && current->number != value) { //���� ������ �������, ���� �� ������ ��� �� ��������� �� ����-��������
        previous = current;
        current = current->next;
    }
    if (current != nullptr) {
        temp = current;
        if (previous != nullptr)
            previous->next = current->next;
        else
            p = current->next;
        delete(temp);
        return value;
    }
    return 0;
}
//������ ������? (1-��, 0-���)
int isEmpty(list* p) {
    return p == nullptr;
}
// ����� ����� � ������
int searchData(list* p, int value) {
    while (p != nullptr) {
        if (p->number == value) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
//������ ����� � ����
void toFile(list* p) {
    ofstream ofile("numbers.txt");  //�������� ����� ��� ������
    if (ofile.fail()) {
        cout << "������ �������� �����" << endl;
        exit(1);
    }
    if (!isEmpty(p)) { //��������, �� ������ �� ������
        while (p != nullptr) {
            ofile << p->number << " ";  //������ ��������� ������ � ����
            p = p->next;
        }
    }
    else {
        cout << "������ ����" << endl;
    }
    ofile.close();
    cout << "������ ������� � ����" << endl;
}
//������ ������ �� �����
void fromFile(list*& p) {
    int temp;
    ifstream ifile("numbers.txt");  //�������� ����� ��� ������
    if (ifile.fail()) {
        cout << "������ �������� �����" << endl;
        exit(1);
    }
    while (ifile >> temp) { //������ ������ �� �����
        insertData(p, temp);  //�������� ������
    }
    ifile.close();
    cout << "������ �������� �� �����" << endl;
    printList(p); //����� ����������� ������
}
