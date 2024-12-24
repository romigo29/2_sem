#include "queue.h"

void createQueue(Queue** begin, Queue** end, int size, int first) {

	int n, current_size = 0; //���������� ��� ����� �����, �������� ������� �������
	cout << "������� ��������� �������� �������: " << endl;
	for (int i = 1; i < size; i++) {
		Queue* temp = new Queue; // �������� ��������� �� �������
		temp->next = NULL;  //���������, ��� ��������� ������� ������
		cin >> n;  // ������ ����� � ����������
		temp->number = n;  // ��������� �������� ����� � �������
		(*end)->next = temp;    //��������� next ���������� �������� ������� ��������������� �� ����� �������
		*end = temp;  //����� ������� ��������� �� ������� temp
		current_size++;  //����������� ������ ������� �������

		if (n == first) {
			displayQueueAndSize((*begin), current_size);
		}
	}
	cout << "������� ������� �������" << endl;
}

void displayQueue(Queue* begin) {
	Queue* temp = begin; // ������� ��������� ��������� temp ��� ������ ��������� �������
	if (temp == NULL) {
		cout << "������� �����!" << endl;
	}
	else {	
		cout << "�������� �������: ";
		while (temp != NULL) {  //������� �������� �� ����� �������
			cout << temp->number << " ";
			temp = temp->next;  //���������� ��������� �� ��������� �������
		}
		cout << endl;
		delete temp;  //������� temp �� ��������� ������ � ��������
	}
}

void deleteQueue(Queue** begin) {

	if (begin == NULL) {
		cout << "������� �����!" << endl;
	}
	else {
		Queue * temp = new Queue; // ������� ��������� ��������� temp ��� �������� �������
		while (*begin != NULL) {  //������� ���� ������ ������� �� ��������� NULL
			temp = *begin;
			*begin = (*begin)->next;
			delete temp;
		}
		cout << "������� ������� �������!" << endl;
	}
}

void displayQueueAndSize(Queue* begin, int size) {

	displayQueue(begin);
	cout << "������ �������: " << size << endl;
}