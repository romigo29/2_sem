#include "List.h"

Object::~Object() {
    while (Head != NULL) { // Пока есть элементы в списке
        Element* temp = Head;
        Head = Head->Next; // Переходим к следующему элементу
        delete temp; // Удаляем текущий элемент
    }
}

Element* Object::GetLast() {
    Element* e = Head;
    Element* rc = e;
    while (e != NULL) { // Пока не достигнем конца списка
        rc = e; // Запоминаем текущий элемент
        e = e->Next; // Переходим к следующему элементу
    }
    return rc;
}

Element* Object::Search(char* data) {
    Element* rc = Head;
    while ((rc != NULL) && (strcmp((char*)rc->Data, data) != 0)) { // Пока не найдем нужный элемент
        rc = rc->Next; // Переходим к следующему элементу
    }
    return rc;
}

void Object::Insert(Country * data) {
    if (Head == NULL) { // Если список пуст
        Head = new Element(NULL, data, NULL); // Создаем новый элемент
    }
    else { // Если в списке уже есть элементы
        Element* last = GetLast(); // Получаем последний элемент
        last->Next = new Element(last, data, NULL); // Добавляем новый элемент в конец списка
    }
}

bool Object::Delete(Element* e) {
    if (e == NULL) return false; // Если переданный элемент NULL, возвращаем false

    if (e->Next != NULL)
        e->Next->Prev = e->Prev; // Обновляем указатели соседних элементов
    if (e->Prev != NULL)
        e->Prev->Next = e->Next;
    else
        Head = e->Next; // Если удаляем первый элемент, обновляем указатель на голову списка
    delete e; // Удаляем элемент
    return true;
}

bool Object::Delete(char* data) {
    return Delete(Search(data)); // Удаляем элемент, найденный по данным
}

void Object::PrintList(void(*f)(void*)) {
    Element* e = Head;
    while (e != NULL) { // Пока есть элементы в списке
        f(e->Data); // Вызываем функцию для вывода данных элемента
        e = e->GetNext(); // Переходим к следующему элементу
    }
}

void Object::PrintList(void(*f)(void*), Element* e) {
    f(e->Data); // Вызываем функцию для вывода данных элемента
}

int Object::countList() {
    int nElements = 0; //счетчик элементов в списке
    Element* e = Head;
    while (e != NULL) {  // Пока есть элементы в списке
        nElements++;  // Вызываем функцию для вывода данных элемента
        e = e->GetNext();// Переходим к следующему элементу
    }
    return nElements;
}

bool Object::deleteList() {
    if (Head == NULL)   {  //если список пуст
        return false;
    }

    while (Head != NULL) {  //если список не пуст
        Element* e = Head;
        Head = Head->GetNext(); // Переходим к следующему элементу
        delete e;  // Удаляем текущий элемент 
    }
    return true;
}

// Определение функции Create для создания объекта Object
Object Create() {
    return Object();
}