#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;
//���������, ���������� ����� �����
struct Address {
	char name[NAME_SIZE];  //��� ��������
	char city[CITY_SIZE];  //������ �����
	Address* next;  //��������� ������� � ������
	Address* prev;  //���������� ������� � ������
};
//���� ���������
int menu() {
	short choice;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. �������� �� �����" << endl;
	cout << "3. ������� ��������� ������ � �������� ���������" << endl;
	cout << "4. ����� �� �����" << endl;
	cout << "5. �����" << endl;
	cout << "6. �����" << endl;
	cout << endl;
	do {
		cout << "��� �����: ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	return choice;
}
//���������� �������� � ����� ������
void insertElement(Address* e, Address** phead, Address** plast) {
	Address* p = *plast;  //��������� ��������� �� ����� ������
	if (*plast == NULL) {  //���� ������ ����
		e->next = NULL;
		e->prev = NULL;
		*plast = e;  //������������� ������ ������ �� ����������� �������
		*phead = e;  //������������� ����� ������ �� ����������� �������
	}
	else {  //���� � ������ ���� ��������
		p->next = e;  //���������, ��� ��������� ������� � ������������ ����� - ��� ����������� �������
		e->next = NULL;  //��������� �������
		e->prev = p;  //���������� ��� ������������ � ������
		*plast = e;  //����� ������ �������������� �� ����������� ������� 
	}
}
// �������� �������� � ���� ��� �������� � ���������� 
Address* setElement() {
	Address* temp = new Address();  //
	if (!temp) {
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.ignore(cin.rdbuf()->in_avail());  //������� ������ ��� ����������� �����
	cin.clear();
	cin.getline(temp->name, NAME_SIZE - 1, '\n');

	cout << "������� �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//����� ������ �� �����
void outputList(Address** phead, Address** plast) {
	Address* t = *phead;  //��������� �� ������ ������
	while (t) {  //���� ��������� �� NULL, ������� ������
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
// ����� ����� � ������
void findName(char name[NAME_SIZE], Address** phead) {
	Address* t = *phead;  //��������� �� ������ ������
	while (t) {  //����� ��������
		if (!strcmp(name, t->name)) {  //���� ������� ������, ������� �� ������
			break;
		}
		t = t->next;
	}
	if (!t) {
		cerr << "��� �� �������" << endl;
	}
	else {
		cout << t->name << ' ' << t->city << endl;
	}
}
// �������� �����
void deleteByName(char name[NAME_SIZE], Address** phead, Address** plast) {
	struct Address* t = *phead;  //��������� �� ������ ������
	while (t) {
		if (!strcmp(name, t->name)) {  //���� ������� ������, ������� �� ������
			break;
		}
		t = t->next;
	}
	if (!t) {
		cerr << "��� �� �������" << endl;
	}
	else {
		if (*phead == t) {  //���� ������� ��������� � ������ ������
			*phead = t->next;
			if (*phead) {
				(*phead)->prev = NULL;
			}
			else {
				*plast = NULL;
			}
		}
		else {   //���� ������� ���-�� �� � ������
			t->prev->next = t->next;
			if (t != *plast) {
				t->next->prev = t->prev;
			}
			else {
				*plast = t->prev;
			}
		}
		delete t;
		cout << "������� ������" << endl;
	}
}
//������� ����� ��������� ������ � �������� ���������
int countX(char city[CITY_SIZE], Address** phead, Address** plast) {
	struct Address* t = *phead;  //��������� �� ������ ������
	int counter = 0; //������� ������������� ���������
	while (t) {
		if (!strcmp(city, t->city)) {  //���� ������� ������, ����������� �������
			counter++;
		}
		t = t->next;
	}
	return counter;
}
//������� �������
int main() {
	Address* head = NULL;  //�������� ��������� �� ������ ������
	Address* last = NULL;  //�������� ��������� �� ����� ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		switch (menu()) {
		case 1: {
			insertElement(setElement(), &head, &last);
			break;
		}
		case 2: {
			char dname[NAME_SIZE];
			cout << "������� ���: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			cin.getline(dname, NAME_SIZE - 1, '\n');
			deleteByName(dname, &head, &last);
			break;
		}
		case 3: {
			char dcity[CITY_SIZE];
			cout << "������� �����: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			cin.getline(dcity, CITY_SIZE - 1, '\n');
			cout << "������� ����������: " << countX(dcity, &head, &last);
			break;
		}
		case 4: {
			outputList(&head, &last);
			break;
		}
		case 5: {
			char fname[NAME_SIZE];
			cout << "������� ���: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			findName(fname, &head);
			break;
		}

		case 6: {
			exit(0);
		}
		default: {
			exit(1);
		}
		}
	}
	return 0;
}

