#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

struct Country {
    char name[20];
    char capital[20];
    unsigned int population;
    double area;
    char head_lastname[20];
    Country* next;
};

struct Element {
    Element* Prev;
    Element* Next;
    void* Data;
    Element(Element* prev, void* data, Element* next) {
        Prev = prev;
        Data = data;
        Next = next;
    }
    Element* GetNext() {
        return Next;
    };
    Element* GetPrev() {
        return Prev;
    };
};

struct Object {
    Element* Head;
    Object() {
        Head = NULL;
    };
    ~Object(); // Деструктор для освобождения памяти
    Element* GetFirst() {
        return Head;
    };
    Element* GetLast();
    Element* Search(char* data);
    void Insert(Country* data);
    bool Delete(char* data);
    bool Delete(Element* data);
    void PrintList(void(*f)(void*));
    void PrintList(void(*f)(void*), Element*);
    int countList(); 
    bool deleteList(); 
};

Object Create();


