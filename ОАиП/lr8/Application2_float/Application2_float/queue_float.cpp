#include <iostream>
using namespace std;

struct Queue {   // ������� ������� 
	double number;
	Queue* next;
};
void createQueue(Queue** begin, Queue** end, int size);
void displayQueue(Queue* begin);
void deleteQueue(Queue** begin);
void ringQueue(Queue** begin);

void createQueue(Queue** begin, Queue** end, int size) {
	Queue* temp;
	double n; //���������� ��� ����� �����
	cout << "������� ��������� �������� �������: " << endl;
	for (int i = 0; i < size; i++) {
		temp = new Queue; // �������� ������ �������� �������
		cin >> n;  // ���� �������� � ����������
		temp->number = n;  // ������ �������� � �������
		temp->next = NULL;  // ���������, ��� ��������� ������� ������
		if (*begin == NULL) {
			*begin = temp;  // ���� ������ ������� ������, ������������� ������
		}
		else {
			(*end)->next = temp;  // ����� ������������� ����� � ��������� ���������
		}
		*end = temp;  // ������������� ����� ������� �� ����� �������
	}
	cout << "������� ������� �������" << endl;
}

void displayQueue(Queue* begin) {
	Queue* temp = begin; // ������� ��������� ��������� temp ��� ������ ��������� �������
	if (temp == NULL) {
		cout << "������� �����!" << endl;
	}
	else {
		while (temp != NULL) {  //������� �������� �� ����� �������
			cout << temp->number << " ";
			temp = temp->next;  //���������� ��������� �� ��������� �������
		}
		cout << endl;
	}
}

void deleteQueue(Queue** begin) {
	Queue* temp;
	while (*begin != NULL) {  //������� ���� ������ ������� �� ��������� NULL
		temp = *begin;
		*begin = (*begin)->next;
		delete temp;
	}
}

void ringQueue(Queue** begin) {

	if (*begin == NULL) {
		return; // �������� �� ������ �������
	}
	Queue* temp = *begin;
	Queue* current = *begin;
	double max = (*begin)->number; // ���������� ��� ������������� �������� � �������
	// ������� ������������ �������� � �������
	while (temp != NULL) {
		if (temp->number > max) {
			max = temp->number;
		}
		temp = temp->next;
	}
	// ���� ������������ ������� �� ��������� � ������ � ������� �� ������� �� ������ ��������
	while ((*begin)->number != max) {
		temp = *begin;
		current = temp->next;
		*begin = current;
		temp->next = nullptr;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, * end = NULL; //�������� ������ � ����� �������
	int size;  //������ �������
	cout << "������� ������ �������: ";
	cin >> size;
	if (size > 0) {
		createQueue(&begin, &end, size);
	}
	else {
		cout << "������� �� ����� ���� ������ ���������!";
	}
	cout << "������� �� ������������ ������: ";
	displayQueue(begin);
	cout << "������� ����� ������������ ������: ";
	ringQueue(&begin);
	displayQueue(begin);
	deleteQueue(&begin);
	return 0;
}

