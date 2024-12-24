#include "Heap.h"
#include <iostream>
using namespace std;
// Принимает два указателя на void, которые приводятся к указателям на AAA
heap::CMP cmpAAA(void* a1, void* a2) {
    // Приведение указателей к типу AAA
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL; // Инициализация результата сравнения как EQUAL
    // Сравниваем значения x элементов типа AAA
    if (A1->x > A2->x) {
        rc = heap::GREAT; // Если значение x первого элемента больше, результат - GREAT
    }
    else if (A2->x > A1->x) {
        rc = heap::LESS; // Если значение x второго элемента больше, результат - LESS
    }
    return rc;
    // Удаляем макросы для предотвращения конфликтов с другими частями кода
#undef A2
#undef A1 
}
//главная фукнция
int main()  {
    setlocale(LC_ALL, "rus");
    int k, choice;
    heap::Heap h1 = heap::create(30, cmpAAA);   //Создание кучи
    for (;;)  {
        cout << "1 - вывод кучи на экран" << endl;
        cout << "2 - добавить элемент" << endl;
        cout << "3 - удалить максимальный элемент" << endl;
        cout << "4 - удалить минимальный элемент" << endl; 
        cout << "5 - удалить i-ый элемент" << endl; 
        cout << "6 - объединить две кучи" << endl; 
        cout << "7 - вывод минимального значения в куче" << endl; 
        cout << "8 - вывод максимального значения в куче" << endl; 
        cout << "9 - очистить кучу" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl; cin >> choice;
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
            cout << "введите ключ" << endl; cin >> k;
            a->x = k;
            h1.insert(a);
            break;
        }
        case 3: {
            h1.extractMax();
            break;
        }
        case 4: {  // Добавляем обработчик для удаления минимального элемента
            h1.extractMin();
            break;
        }
        case 5: { // Добавляем обработчик для удаления i-ого элемента
            int i;
            cout << "введите индекс элемента для удаления" << endl; cin >> i;
            h1.extractI(i);
            break;
        }
        case 6: { // Добавляем обработчик для объединения двух куч
            heap::Heap h2 = heap::create(20, cmpAAA); // Создание второй кучи
            // Добавляем элементы во вторую кучу h2, если нужно
            h1.unionHeap(h2);
            break;
        }
        case 7: { // Добавляем обработчик для вывода минимального значения в куче
            h1.getMin();
            break;
        }
        case 8: {  // Добавляем обработчик для вывода максимального значения в куче
            h1.getMax();
            break;
        }
        case 9: {
            h1.clear(); // Очистить кучу
            break;
        }
        default: {
            cout << endl << "Введена неверная команда!" << endl;
        }
        }
    }
    return 0;
}