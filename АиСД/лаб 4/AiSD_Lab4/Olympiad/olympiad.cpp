#include <iostream>
#include <ctime> 
#include <cmath>
using namespace std;

void outputArray(int*, int);
void insertSort(int*, int);
int countWinners(int*, int);

void outputArray(int* array, int N) {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
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

int countWinners(int* A, int n) {
    int count = 0, winners = 0;
    for (int i = n - 1; i > 0; i--) {
        if (winners == 3) {
            break;
        }
        else {
            count++;
            if (i == 1 && A[i] == A[0]) {
                count++;
            }
        }
        if (A[i] != A[i - 1]) {
            winners++;
        }
        
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  //устанавливает новую точку отсчета 
    long int N;
    int* B;  //определние массива
    cout << "Введите число призеров (от 1 до 10000): ";
    cin >> N;
    while (N < 0 || N > 10000) {
        cout << "Введено не натуральное число. Попробуйте еще раз: ";
        cin >> N;
    }
    int* A = new int[N]; //выделение динамической памяти дляA массива A
    //заполнение массива A
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 99;
    }
    cout << "Исходный массив: ";
    outputArray(A, N);
    insertSort(A, N);
    cout << "Отсортированный массив: ";
    outputArray(A, N);
    cout << "Количество призеров: " << countWinners(A, N);

    delete[] A;
    return 0;
}
