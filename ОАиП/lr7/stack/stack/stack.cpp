#include "stack.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int choice; char x;
	Stack* myStack = new Stack; //��������� ������ ��� �����
	myStack = NULL; //������������� ������� ��������
	do {
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ������ � ����" << endl;
		cout << "4 - ������ �� �����" << endl;
		cout << "5 - ����� �����" << endl;
		cout << "6 - ����������, ���� �� ����� � �������� ��������� �����" << endl;
		cout << "7 - �������� ����" << endl;
		cout << "0 - �����" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "������� �������: " << endl;
			cin >> x;
			inputStack(x, myStack);
			break;
		}
		case 2: {
			x = getElement(myStack);
			if (x != -1)
				cout << "����������� �������: " << x << endl;
			break;
		}
		case 3: {
			toFile(myStack);
			break;
		}
		case 4: {
			fromFile(myStack);
			break;
		}
		case 5: {
			cout << "���� ����: " << endl;
			displayStack(myStack);
			break;
		}

		case 6: {
			if (!defineElement(myStack)) {
				cout << "��� ����� � �����, ���������� � ��������� ��������" << endl;
			}
			else {
				cout << "���� ����� � �����, ���������� � �������� ��������" << endl;
			}
			break;
		}

		case 7: {
			if (!clearStack(myStack)) {
				cout << "���� ����!" << endl;
			}
			else {
				cout << "���� ������" << endl;
			}
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

