#include "queue.h"

int main() {
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, *end, *element; //�������� ������ � ����� ������� � �� ���������
	element = new Queue;  // ������� ����� ������� �������
	int choice, first, size;  //����� ������������, ������ ������� ������� �  �� ������
	cout << "������� ������ �������: ";
	cin >> size;
	while (size < 1) {
		cout << "������� �������� �������, ��� 0: ";
		cin >> size;
	}
	cout << "�������� ������ ������� �������: ";
	cin >> first;
	element->number = first;  //��������� ������ ������� �������
	element->next = NULL;  //���������, ��� ��������� ������� NULL
	begin = end = element;  //��������� ������ � ����� �������

	do {
		cout << "\n�������� �������:" << endl;
		cout << "1 - ���������� ��������� � ������� (��� ���������� ������� �������� ��������� ������� �� ������" << endl;
		cout << "2 - ����� ��������� �������" << endl;
		cout << "3 - �������� �������" << endl;
		cout << "0 - �����" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			if (size > 1 )  {
				createQueue(&begin, &end, size, first);
			}
			else {
				cout << "������� �� ����� ���� ������ ���������!";
			}
			break;
		}
		case 2: {
			displayQueue(begin);
			break;
		}
		case 3: {
			deleteQueue(&begin);
			break;
		}

		case 0: {
			return 0;
			break;
		}
		default: {
			cout << "������ �������� �������!" << endl;
		}
		}
	} while (choice != 0);

	return 0;
}
