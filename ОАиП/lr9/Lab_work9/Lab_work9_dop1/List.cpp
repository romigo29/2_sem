#include "List.h"

Object::~Object() {
    while (Head != NULL) { // ���� ���� �������� � ������
        Element* temp = Head;
        Head = Head->Next; // ��������� � ���������� ��������
        delete temp; // ������� ������� �������
    }
}

Element* Object::GetLast() {
    Element* e = Head;
    Element* rc = e;
    while (e != NULL) { // ���� �� ��������� ����� ������
        rc = e; // ���������� ������� �������
        e = e->Next; // ��������� � ���������� ��������
    }
    return rc;
}

Element* Object::Search(char* data) {
    Element* rc = Head;
    while ((rc != NULL) && (strcmp((char*)rc->Data, data) != 0)) { // ���� �� ������ ������ �������
        rc = rc->Next; // ��������� � ���������� ��������
    }
    return rc;
}

void Object::Insert(Country * data) {
    if (Head == NULL) { // ���� ������ ����
        Head = new Element(NULL, data, NULL); // ������� ����� �������
    }
    else { // ���� � ������ ��� ���� ��������
        Element* last = GetLast(); // �������� ��������� �������
        last->Next = new Element(last, data, NULL); // ��������� ����� ������� � ����� ������
    }
}

bool Object::Delete(Element* e) {
    if (e == NULL) return false; // ���� ���������� ������� NULL, ���������� false

    if (e->Next != NULL)
        e->Next->Prev = e->Prev; // ��������� ��������� �������� ���������
    if (e->Prev != NULL)
        e->Prev->Next = e->Next;
    else
        Head = e->Next; // ���� ������� ������ �������, ��������� ��������� �� ������ ������
    delete e; // ������� �������
    return true;
}

bool Object::Delete(char* data) {
    return Delete(Search(data)); // ������� �������, ��������� �� ������
}

void Object::PrintList(void(*f)(void*)) {
    Element* e = Head;
    while (e != NULL) { // ���� ���� �������� � ������
        f(e->Data); // �������� ������� ��� ������ ������ ��������
        e = e->GetNext(); // ��������� � ���������� ��������
    }
}

void Object::PrintList(void(*f)(void*), Element* e) {
    f(e->Data); // �������� ������� ��� ������ ������ ��������
}

int Object::countList() {
    int nElements = 0; //������� ��������� � ������
    Element* e = Head;
    while (e != NULL) {  // ���� ���� �������� � ������
        nElements++;  // �������� ������� ��� ������ ������ ��������
        e = e->GetNext();// ��������� � ���������� ��������
    }
    return nElements;
}

bool Object::deleteList() {
    if (Head == NULL)   {  //���� ������ ����
        return false;
    }

    while (Head != NULL) {  //���� ������ �� ����
        Element* e = Head;
        Head = Head->GetNext(); // ��������� � ���������� ��������
        delete e;  // ������� ������� ������� 
    }
    return true;
}

// ����������� ������� Create ��� �������� ������� Object
Object Create() {
    return Object();
}