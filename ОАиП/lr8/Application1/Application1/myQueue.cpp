#include<iostream>
using namespace std;
struct Item  {
	int data;
	Item* next;
};
Item* head, * tail;
bool isNull(void) {  //�������� �� �������
	return (head == NULL);
}
void deletFirst() {  //���������� �������� �� ������
	if (isNull())  {
		cout << "������� �����" << endl;
	}
	else  {
		Item* temp = NULL;
		Item* current = head;
		while (!isNull())  {  //���������� ���������, ���� �� ��������� �� ����� �������
			if (current->next == tail) {  //���� ���������, �� ����� ��������� ���������� ������� ��������� �������
				current->next = NULL;
				temp = tail;
				tail = current;
				break;

			}
			current = current->next;  //���������� ��������� �� ��������� �������
		}
		delete temp;
	}
}

void getFromHead() {   //��������� �������� �� �����

	if (isNull())  {
		cout << "������� �����" << endl;
	}
	else  {
		cout << "����� = " << tail->data << endl;
	}
}
void insertToQueue(int x) {  //���������� �������� � ������� 

	Item* p = new Item;  //C������ ����� ���������
	p->data = x;
	p->next = NULL;
	//���� ������� ������, �� � ����� � ������ ������� ��������� �������
	if (isNull()) {
		head = tail = p;
	}
	//����� ���������� ��� �������� ������� ��� ��������� ������
	else {
		Item* previous = NULL;
		Item* current = head;
		//���� ����� ������� ������ ��� ����� ������� ��� ������� �� �����������
		while (current != NULL && x <= current->data) {
			previous = current;  //���������� ��������� �� NULL, ����� ���������� ������� � ����� ������
			current = current->next;
		}
		//���� ������� � ����� ������� �����������,�� ������������� � ������ �������
		if (previous == NULL) {
			p->next = head;
			head = p;
		}
		else {
			//���� ����� ������ ���� �������, �� ������������� ��� � �����
			if (current == NULL) {
				tail->next = p;
				tail = p;
			}
			//���� ����� ���-�� �����
			else {
				p->next = current;
				previous->next = p;
			}
		}
	}
}

void printQueue() {   //����� �������

	Item* p = new Item;
	if (isNull())  {
		cout << "������� �����" << endl;
	}
	else  {
		cout << "������� = ";
		p = head;
		while (!isNull())  {
			if (p != NULL)  {
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else  {
				cout << "NULL" << endl;
				return;
			}
		}
	}
}
void clrQueue()  {  //������� �������

	while (!isNull()) deletFirst();
}
int main()  {
	setlocale(LC_CTYPE, "Russian");
	int choice = 1, z; head = NULL; tail = NULL;
	while (choice != 0)  {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������� � �����" << endl;
		cout << "3 - ������� ������� � �����" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "5 - �������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �������� "; cin >> choice;
		switch (choice)  {
		case 1: {
			cout << "������� �������: "; 
			cin >> z;
			insertToQueue(z);
			printQueue();
			break;
		}
		case 2: {
			getFromHead();
			break;
		}
		case 3: {
			deletFirst();
			break;
		}
		case 4: {
			printQueue();
			break;
		}
		case 5: { 
			clrQueue();
			break; 
		}
		}
	}
	return 0;
}