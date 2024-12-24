#pragma once
using namespace std;
//Элементы кучи
struct AAA  {
    int x;
    void print() const;  //печать значений
};
namespace heap  {
    //типы сравения
    enum CMP  {
        LESS = -1, EQUAL = 0, GREAT = 1
    };
    struct Heap   {
        int size;  
        int maxSize;  
        void** storage; // данные 
        CMP(*compare)(void*, void*);
        Heap(int maxsize, CMP(*f)(void*, void*))  {
            size = 0;  //начальный размер
            storage = new void* [maxSize = maxsize];  //хранилище элементов
            compare = f;
        };
        int left(int ix) const;  //Получение левого потомка
        int right(int ix) const;  //Получение правого потомка
        int parent(int ix);  //Получение предка
        bool isFull() const  {
            return (size >= maxSize);
        };
        bool isEmpty() const   {
            return (size <= 0);
        };
        bool isLess(void* x1, void* x2) const  {
            return compare(x1, x2) == LESS;
        };
        bool isGreat(void* x1, void* x2) const  {
            return compare(x1, x2) == GREAT;
        };
        bool isEqual(void* x1, void* x2) const   {
            return compare(x1, x2) == EQUAL;
        };
        void swap(int i, int j);
        void heapify(int ix);
        void insert(void* x);
        void* extractMax();
        void* extractMin(); //прототип функции удаления минимального элемента
        void* extractI(int i); // прототип функции удаления i-ого элемента
        void unionHeap(Heap& other); // прототип функции объединения двух куч
        void getMin(); // прототип функции вывода минимального значения в куче
        void getMax(); // прототип функции вывода максимального значения в куче
        void scan(int i) const;
        void clear(); //фукнция очистки кучи
      
    };
    Heap create(int maxsize, CMP(*f)(void*, void*));
};
