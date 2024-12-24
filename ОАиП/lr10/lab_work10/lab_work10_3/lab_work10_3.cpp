#include <iostream>
using namespace std;

const int n=  5;
int numbers[5] = { 1, 2, 3, 4, 5 };  //Массив с числами

void replaceDigits(int [], int, int );
void swapDigits(int&, int&);
//Меняем цифры местами
void swapDigits(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//Функция для вывода генерации и вывода перестановок
void replaceDigits(int[], int size, int index) {
    if (index == size) { //Если индекс равен размеру массива, значит, мы завершили перестановку
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << " ";  //Выводим получившееся число
        }
        cout << endl;
    }
    else { //Иначе продолжаем переставлять числа 
        for (int i = index; i < size; i++) {  //Начинаем пербирать с начального индекс index
            swapDigits(numbers[i], numbers[index]); //Меняем текущий элемент с элементом на позиции index
            replaceDigits(numbers, size, index + 1); //Вызываем рекурсию для следующего индекса
            swapDigits(numbers[i], numbers[index]); // Возвращаем элементы на исходные места для следующей итерации
        }
    }
}

int main()  {
    setlocale(LC_ALL, "rus");
    cout << "Перестановки чисел: " << endl;
    replaceDigits(numbers, n, 0);
    return 0;
}

