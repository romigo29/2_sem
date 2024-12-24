#include "stack.h"

void inputStack(int x, Stack*& myStack) {   //���������� �������� � � ����
	Stack* element = new Stack; //��������� ������ ��� ������ ��������
	element->data = x; //������ �������� x � ���� data
	element->next = myStack; //������� ������� �� ��������� ������� 
	myStack = element; //����� ������� �� ������� ������
}

int getElement(Stack*& myStack) {
	if (myStack == NULL) {
		cout << "���� ����!" << endl;
		return -1; // ���� ���� ���� - ������� (-1)
	}
	else {
		Stack* element = myStack; // element - ���������� ��� �������� ������ ��������
		int x = myStack->data; // ������ �������� �� ���� data � ���������� x
		myStack = myStack->next; // ������� �������
		delete element; // ������������ ������
		return x;
	}
}

void toFile(Stack*& myStack) {
	ofstream ofile("myStack.txt");
	if (ofile.fail()) {
		cout << "\n������ �������� �����";
		exit(1);
	}

	Stack* temp = myStack; // ������� ��������� ��������� ��� ������ �����
	while (temp != NULL) {
		ofile << temp->data << " "; // ���������� ������ �������� � ����
		temp = temp->next; // ��������� � ���������� �������� �����
	}

	ofile.close();
	cout << "���� ������� � ���� myStack.txt\n";
}

void fromFile(Stack*& myStack) {
	ifstream ifile("myStack.txt");
	int temp;
	if (ifile.fail()) {
		cout << "\n������ �������� �����";
		exit(1);
	}

	while (ifile >> temp) {
		inputStack(temp, myStack); // ���������� ������ �� ��������� myStack ��� ���������� �������� � ����
	}

	ifile.close();
	cout << "\n���� ������ �� ����� myStack.txt\n\n";
}

void displayStack(Stack*& myStack) {  // ����� �����
	Stack* temp = myStack;
	if (temp == NULL)
		cout << "���� ����!" << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


int clearStack(Stack*& myStack) {
	if (myStack == NULL) {   //���� ���� ����
		return 0;
	}
	while (myStack != NULL) {   //���� ���� �� ����
		Stack* temp = myStack;   //��������� ���������� ��� �������� �������� �����
		myStack = myStack->next;  //������������� �� ��������� ������� �����
		delete temp;   //������� ������� �������
	}
	return 1;
}

//����������� ��������  � ������� ��������� �����
int defineElement(Stack*& myStack) {
	int a, b; //����� � ������ ������� ��������� �����
	cout << "������� �������� ����� [a, b]: ";
	cin >> a >> b;
	int element;
	while (myStack != NULL) {
		element = getElement(myStack);  //���������� ��������
		if (a <= element && element <= b) { //���� ������� �������� � �������� ����� 
			return 1;
		}
	}
	return 0;
}

