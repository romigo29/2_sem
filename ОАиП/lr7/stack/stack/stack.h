#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
	int data; //�������������� �������
	Stack* next; //��������� �� ��������� �������
};
void displayStack(Stack*& myStack);
int getElement(Stack*& myStack);
void inputStack(int x, Stack*& myStack);
void toFile(Stack*& myStack);
void fromFile(Stack*& myStack);
int defineElement(Stack*& myStack);
int clearStack(Stack*& MyStack);
