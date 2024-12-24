#include <iostream>
#include <chrono> // библиотека для вызова функции chrono
#include <ctime> 
#include <cmath>
using namespace std;
using namespace chrono;

void outputSortedArray(int*, int);
void bubbleSort(int* B, int n);
void insertSort(int* C, int n);
void choiceSort(int* D, int n);
void quickSort(int* E, int first, int last);

void outputSortedArray(int* array, int N) {
    cout << "Отсортирванные элементы массива: ";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int* B, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (B[i] > B[j]) {
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }
}

void insertSort(int* C, int n) {
    int buff, j;
    for (int i = 1; i < n; i++) {
        buff = C[i];
        for (j = i - 1; j >= 0 && C[j] > buff; j--) {
            C[j + 1] = C[j];
        }
        C[j + 1] = buff;
    }
}

void choiceSort(int* D, int n) {
    int min, buff;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            min = (D[j] < D[min]) ? j : min;
        }
        if (i != min) {
            buff = D[i];
            D[i] = D[min];
            D[min] = buff;
        }
    }
}

void quickSort(int* E, int first, int last) {
    int mid, count;
    int f = first, l = last;
    mid = E[(f + l) / 2];
    do {
        while (E[f] < mid) {
            f++;
        }
        while (E[l] > mid) {
            l--;
        }
        if (f <= l) {
            count = E[f];
            E[f] = E[l];
            E[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) {
        quickSort(E, first, l);
    }
    if (f < last) {
        quickSort(E, f, last);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  //устанавливает новую точку отсчета 
    long int N;
    int *B, *C, *D, *E;  //определние массивов
    cout << "Введите размер N массива A: ";
    cin >> N;
    while (N < 0) {
        cout << "Введено не натуральное число. Попробуйте еще раз: ";
        cin >> N;
    }
    int* A = new int[N]; //выделение динамической памяти дляA массива A
    //заполнение массива A
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 99;
    }
    ////выделение динамической памяти для остальных массивов
    B = new int[N]; 
    C = new int[N]; 
    D = new int[N]; 
    E = new int[N]; 
    //вывод массива
    cout << "Элементы массива A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
        //копирование элементов из массива A в остальные массивы
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
    }
    // пузырьковая сортировка
    auto start = high_resolution_clock::now(); // начало отсчета времени работы функции
    bubbleSort(B, N);
    cout << endl;
    auto end = high_resolution_clock::now(); // конец отсчета времени работы функции
    duration<double, milli>duration = end - start;
    cout << "Рассчетное время пузырьковой сортировкой: " << duration.count() << " секунд" << endl;
    outputSortedArray(B, N);
    // сортировка Шелла
    start = high_resolution_clock::now(); 
    insertSort(C, N);
    end = high_resolution_clock::now(); 
    duration = end - start;
    cout << "Рассчетное время сортировкой Шелла: "  << duration.count() << " секунд" << endl;
    outputSortedArray(C, N);
    // сортировка выбора
    start = high_resolution_clock::now();
    choiceSort(D, N);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Рассчетное время сортировкой выбора: " << duration.count() << " секунд" << endl;
    outputSortedArray(D, N);
    // быстрая сортировка
    start = high_resolution_clock::now();
    quickSort(E, 0, N - 1);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Рассчетное время быстрой сортировкой: " << duration.count() << " секунд" << endl;
    outputSortedArray(E, N);

    delete[] A, B, C, D, E;
    return 0;
}
