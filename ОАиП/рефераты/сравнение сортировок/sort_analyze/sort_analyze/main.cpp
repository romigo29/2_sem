#include <iostream>
#include <chrono> // библиотека для вызова функции chrono
#include <ctime> 
using namespace std;
using namespace chrono;

void outputSortedArray(int*, int);
void heapify(int* A, int N, int pos);
void heapSort(int* A, int N);
void quickSort(int* B, int first, int last);
void merge(int* C, int first, int last);
void mergeSort(int* C, int low, int high);
void insertSort(int* D, int n);

void outputSortedArray(int* array, int N) {
    cout << "Отсортирванные элементы массива: ";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
//Построение пирамиды для пирамидальной сортировки
void heapify(int* A, int N, int pos) {
    int max = 0;
    int temp = 0;
    int left = 0;
    int right = 0;

    for (;;) {
        left = 2 * pos + 1;
        right = left + 1;
        if (left >= N) {
            return;
        }
        else if (right >= N) {
            max = left;
        }
        else if (A[left] > A[right]) {
            max = left;
        }
        else {
            max = right;
        }
        if (A[pos] > A[max]) {
            return;
        }

        temp = A[pos];
        A[pos] = A[max];
        A[max] = temp;

        pos = max;
    }
}
//Пирамидальная сортировка 
void heapSort(int* A, int N) {

    for (int i = N / 2; i >= 0; --i) {
        heapify(A, N, i);  //Строим пирамиду, перегруппировывая массив
    }

    for (int i = N - 1; i > 0; i--) {
        //Перемещаем текущий корень в конец
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        //Продолжаем выстраивать пирамиду
        heapify(A, i, 0);
    }
}

//Быстрая сортировка 
void quickSort(int* E, int first, int last) {
    // Объявление переменных
    int mid, count;
    int f = first, l = last;

    mid = E[(f + l) / 2];      // Выбор опорного элемента

    // Цикл разделения элементов массива
    do {
        // Поиск элемента, который больше или равен опорному, слева от опорного
        while (E[f] < mid) {
            f++;
        }
        // Поиск элемента, который меньше или равен опорному, справа от опорного
        while (E[l] > mid) {
            l--;
        }
        // Обмен элементами, чтобы все элементы слева от опорного были меньше или равны ему,
        // а все элементы справа - больше или равны
        if (f <= l) {
            count = E[f];
            E[f] = E[l];
            E[l] = count;
            f++;
            l--;
        }
    } while (f < l); // Повторять, пока индексы не пересекутся

    // Рекурсивный вызов функции для подмассивов слева и справа от опорного элемента
    if (first < l) {
        quickSort(E, first, l);
    }
    if (f < last) {
        quickSort(E, f, last);
    }
}
//Функция, сливающая массивы
void merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2; 			//вычисление среднего элемента
    start = first; 					//начало левой части
    final = middle + 1; 				//начало правой части
    for (j = first; j <= last; j++)		 //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)  A[j] = mas[j];  //возвращение результата в список
    delete[]mas;
};
//Сортировка слиянием
void mergeSort(int* A, int first, int last) {
    if (first < last)
    {
        mergeSort(A, first, (first + last) / 2); 	//сортировка левой части
        mergeSort(A, (first + last) / 2 + 1, last); 	//сортировка правой части
        merge(A, first, last); 				//слияние двух частей
    }
};

//Сортировка Шелла(вставками)
void insertSort(int* D, int n) {
    int buff, j;
    for (int i = 1; i < n; i++) {
        buff = D[i];
        for (j = i - 1; j >= 0 && D[j] > buff; j--) {
            D[j + 1] = D[j];
        }
        D[j + 1] = buff;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  //устанавливаем новую точку отсчета времени
    int N;
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
    //выделение динамической памяти для остальных массивов
    int* B = new int[N], * C = new int[N], * D = new int[N], * E = new int[N];
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
    // пирамидальная сортировка сортировка
    auto start = high_resolution_clock::now();
    heapSort(A, N);
    auto end = high_resolution_clock::now();
    duration<double, milli>duration = end - start;
    cout << "\nРассчетное время пирамидальной сортировкой: " << duration.count() << " секунд" << endl;
    outputSortedArray(A, N);
    // быстрая сортировка
    start = high_resolution_clock::now();
    quickSort(B, 0, N - 1);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Рассчетное время быстрой сортировкой: " << duration.count() << " секунд" << endl;
    outputSortedArray(B, N);
    // сортировка слиянием
    start = high_resolution_clock::now();
    quickSort(C, 0, N - 1);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Рассчетное время сортировкой слянием: " << duration.count() << " секунд" << endl;
    outputSortedArray(C, N);
    // сортировка Шелла
    start = high_resolution_clock::now();
    insertSort(D, N);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Рассчетное время сортировкой Шелла: " << duration.count() << " секунд" << endl;
    outputSortedArray(D, N);

    delete[] A, B, C, D, E;
    return 0;
}
