#include <iostream>
#include <windows.h>
using namespace std;
struct Tree //������
{
	int key; //����
	Tree* Left, * Right;
};
Tree* makeTree(Tree* Root); //�������� ������
Tree* list(int i); //�������� ������ ��������
Tree* insertElem(Tree* Root, int key); //���������� ������ ��������
Tree* search(Tree* n, int key); //����� �������� �� �����
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
int view(Tree* t, int level); //����� ������
bool delAll(Tree* t); //������� ������
int getCoincidences(Tree* t, int k, int amount);

int k, amount = 0;
Tree* Root = NULL; //��������� �� ������
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key, choice;
	Tree* rc;
	for (;;)
	{
		cout << "1 - �������� ������\n";
		cout << "2 - ���������� ��������\n";
		cout << "3 - ����� �� �����\n";
		cout << "4 - �������� ��������\n";
		cout << "5 - ����� ������\n";
		cout << "6 - ������� ������\n";
		cout << "7 - ����� ���������� ������, �������� ������� ����� k\n";
		cout << "0 - �����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice) {
		case 1: {
			Root = makeTree(Root);
			break;
		}
		case 2: {
			cout << "\n������� ����: ";
			cin >> key;
			insertElem(Root, key);
			break;
		}
		case 3: {
			cout << "\n������� ����: ";
			cin >> key;
			rc = search(Root, key);
			break;
		}
		case 4: {
			cout << "\n������� ��������� ����: ";
			cin >> key;
			Root = delet(Root, key);
			break;
		}
		case 5: {
			if (Root->key >= 0) {
				cout << "������ ��������� �� 90 ����. �����" << endl;
				view(Root, 0);
			}
			else {
				cout << "������ ������\n";
				break;
			}
		}
		case 6: {
			delAll(Root);
			break;
		}
		case 7: {
			cout << "������� ����� k: ";
			cin >> k;
			cout << "���������� ������, �������� ������� ����� k: " << getCoincidences(Root, k, amount) << endl;
			break;
		}
		case 0: {
			exit(0);
		}
		}
	}
	return 0;
}
Tree* makeTree(Tree* Root) {  //�������� ������
	int key;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL) {  // ���� ������ �� �������
		cout << "������� ���� �����: ";
		cin >> key;
		Root = list(key); // ��������� ��������� �� ������
	}
	while (1) {   //���������� ���������
		cout << "\n������� ����: ";
		cin >> key;
		if (key < 0) {
			break; //������� ������ (���� < 0) 
		}
		insertElem(Root, key);
	}
	return Root;
}
Tree* list(int i) //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key) //���������� ������ ��������
{
	Tree* Prev; // Prev - ������� ����� �������
	Prev = t;
	int find = 0; // ������� ������
	while (t && !find) {
		if (key == t->key) {
			find = 1; //����� ������ ���� ���������
		}
		else {
			if (key < t->key) {
				t = t->Left;
			}
			else {
				t = t->Right;
			}
		}
	}
	if (!find) {  //������� ����� � ������� Prev

		t = list(key); //��������� ����� ���� 
		if (key < Prev->key) {  // � �������������� ���� 
			Prev->Left = t; //������� �� ����� �����,
		}
		else {
			Prev->Right = t; // ���� �� ������
		}
	}
	return t;
}
Tree* delet(Tree* Root, int key) //�������� �������� �� �����
{ // Del, Prev_Del - ��������� ������� � ��� ����������;
// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R; //�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; //�� ����� �����
		else
			Prev_Del->Right = R; //�� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}
Tree* search(Tree* n, int key) {  //����� �������� �� �����

	Tree* rc = n;
	if (rc != NULL) {
		if (key < (key, n->key)) {
			rc = search(n->Left, key);
		}
		else
			if (key > (key, n->key)) {
				rc = search(n->Right, key);
			}
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

int view(Tree* t, int level) //����� ������
{
	if (t) {
		view(t->Right, level + 1); //����� ������� ���������
		for (int i = 0; i < level; i++) {
			cout << " ";
		}
		int tm = t->key;
		cout << tm << ' ';
		view(t->Left, level + 1); //����� ������ ���������
		return 0;
	}
	return 1;
}
bool delAll(Tree* t) {  //������� ������

	if (t != NULL) {
		delAll(t->Left);
		delAll(t->Right);
		delete t;
		return true;
	}
	return false;
}
int getCoincidences(Tree* t, int k, int amount) {
	if (t == nullptr) {  // ���� ������ ������
		return 0;
	}

	if (t->key == k) {
		amount++;  // ����������� �������, ���� ���� ������� ������� ����� k
	}

	// ���������� ������� ����� � ������ ����������, �������� ���������� ����������
	amount += getCoincidences(t->Left, k, amount);
	amount += getCoincidences(t->Right, k, amount);

	return amount;
}

