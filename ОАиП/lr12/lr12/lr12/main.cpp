#include "Heap.h"
#include <iostream>
using namespace std;
// ��������� ��� ��������� �� void, ������� ���������� � ���������� �� AAA
heap::CMP cmpAAA(void* a1, void* a2) {
    // ���������� ���������� � ���� AAA
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL; // ������������� ���������� ��������� ��� EQUAL
    // ���������� �������� x ��������� ���� AAA
    if (A1->x > A2->x) {
        rc = heap::GREAT; // ���� �������� x ������� �������� ������, ��������� - GREAT
    }
    else if (A2->x > A1->x) {
        rc = heap::LESS; // ���� �������� x ������� �������� ������, ��������� - LESS
    }
    return rc;
    // ������� ������� ��� �������������� ���������� � ������� ������� ����
#undef A2
#undef A1 
}
//������� �������
int main()  {
    setlocale(LC_ALL, "rus");
    int k, choice;
    heap::Heap h1 = heap::create(30, cmpAAA);   //�������� ����
    for (;;)  {
        cout << "1 - ����� ���� �� �����" << endl;
        cout << "2 - �������� �������" << endl;
        cout << "3 - ������� ������������ �������" << endl;
        cout << "4 - ������� ����������� �������" << endl; 
        cout << "5 - ������� i-�� �������" << endl; 
        cout << "6 - ���������� ��� ����" << endl; 
        cout << "7 - ����� ������������ �������� � ����" << endl; 
        cout << "8 - ����� ������������� �������� � ����" << endl; 
        cout << "9 - �������� ����" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl; cin >> choice;
        switch (choice) {
        case 0: {
            exit(0);
        }
        case 1: {
            h1.scan(0);
            break;
        }
        case 2: {
            AAA* a = new AAA;
            cout << "������� ����" << endl; cin >> k;
            a->x = k;
            h1.insert(a);
            break;
        }
        case 3: {
            h1.extractMax();
            break;
        }
        case 4: {  // ��������� ���������� ��� �������� ������������ ��������
            h1.extractMin();
            break;
        }
        case 5: { // ��������� ���������� ��� �������� i-��� ��������
            int i;
            cout << "������� ������ �������� ��� ��������" << endl; cin >> i;
            h1.extractI(i);
            break;
        }
        case 6: { // ��������� ���������� ��� ����������� ���� ���
            heap::Heap h2 = heap::create(20, cmpAAA); // �������� ������ ����
            // ��������� �������� �� ������ ���� h2, ���� �����
            h1.unionHeap(h2);
            break;
        }
        case 7: { // ��������� ���������� ��� ������ ������������ �������� � ����
            h1.getMin();
            break;
        }
        case 8: {  // ��������� ���������� ��� ������ ������������� �������� � ����
            h1.getMax();
            break;
        }
        case 9: {
            h1.clear(); // �������� ����
            break;
        }
        default: {
            cout << endl << "������� �������� �������!" << endl;
        }
        }
    }
    return 0;
}