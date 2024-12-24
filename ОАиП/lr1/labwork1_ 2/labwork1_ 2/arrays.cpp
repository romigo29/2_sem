#include <iostream> // подключение библиотеки для работы с вводом/выводом данных
using namespace std; // подключение стандартного пространства имен
// прототипы функций
void delNegative(int* n, ...);
void outputArray(int* array);
// функции удаления отрицательных элементов и добавления 0 в конец массива
void delNegative(int* n, ...) {
    int size = *n; //размер массива
    int* ptr = n; // указатель на первый элемент массива
    for (int i = 1; i <= size; i++) {
        if (*(ptr + i) < 0) {
            for (int j = i; j < size; j++) { // перемещаем элементы на одну позицию влево
                *(ptr + j) = *(ptr + j + 1);
            }
            *(ptr + size) = 0; // заполняем последний элемент нулем
            size--; // уменьшаем размер массива
            i--; // проверяем текущий элемент заново
        }
    }
}
// функция вывода массивов
void outputArray(int* array) {
    int size = *array;
    for (int i = 1; i <= size; i++) {
        cout << array[i] << " "; // начинаем считывать элементы со второго, так как первый элемент - это размер массива
    }
    cout << endl;
}
// Главная функция
int main()
{
    setlocale(LC_ALL, "RUS");
    int arr1[4] = { 3, 7, -2, 9 }; // массив 1
    int arr2[8] = { 5, -1, 10, 8, 4, -2 }; // массив 2
    int arr3[9] = { 8, 0, 7, -3, -2, 6, -1, 1, 9 }; // массив 3
    //вывод массивов поочередно
    cout << "Первый массив: "; outputArray(arr1);
    cout << "Второй массив: "; outputArray(arr2);
    cout << "Третий массив: "; outputArray(arr3);
    // вызовы функции 
    delNegative(arr1);
    delNegative(arr2);
    delNegative(arr3);
    cout << "Массивы после модификации: " << endl;
    //вывод массивов поочередно
    cout << "Первый массив: "; outputArray(arr1);
    cout << "Второй массив: "; outputArray(arr2);
    cout << "Третий массив: "; outputArray(arr3);

    return 0;
}
