#include <iostream>
#include <ctime>   // ��� ������ � ��������
#include <cstdlib> // ��� ������� rand()
#include <Windows.h>

using namespace std;

// ������� ��� ����������� ����������
void bubbleSort(int arr[], int n) {
    // ������� ���� �������� �� ���� ��������� �������
    for (int i = 0; i < n - 1; ++i) {
        // ���������� ���� ���������� ���� ��������� � ������ �� �������, ���� ��� � ������������ �������
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // ����� ����������
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ������� ��� ������� ���� �����������
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // ������ ������ ����������
    int n2 = r - m;     // ������ ������� ����������

    // ������� ��������� ������� ��� �������� ��������
    int* L = new int[n1];
    int* R = new int[n2];

    // �������� ������ �� ������������� ������� �� ��������� �������
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // ������� ��� ������� �� ��������� ��������
    int i = 0, j = 0, k = l;

    // ���������� ��������� ������� ������� � �������� ������
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // �������� ���������� �������� �� L[], ���� ����
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // �������� ���������� �������� �� R[], ���� ����
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // ����������� ��������� �������
    delete[] L;
    delete[] R;
}

// ������� ��� ���������� ��������
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // ������� �������� �������
        int m = l + (r - l) / 2;

        // ���������� ��������� ������ � ������ ��������
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // ������� ��������������� ��������
        merge(arr, l, m, r);
    }
}

// ������� ��� ���������� �������
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // ���� ����������� ������� � ����������������� ����� �������
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ������ ��������� ����������� ������� � ������ ���������
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// ������� ��� ���������� ������� �������
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // ������� ��� �������
        int j = i - 1;
        // �������� �������� �������, ����� ���������� ����� ��� �������
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; // ��������� �������
    }
}

// ������� ��� ���������� ������� �����
void shellSort(int arr[], int n) {
    // ��������� ��� ����� �� 2 ������ ���
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // ��������� �������� � �������� �����
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������ �������� ��� �������������
    int sizes[] = { 1000, 2000, 3000, 4000, 5000 };

    // �������� �� ������� ������� �������
    for (int size : sizes) {
        // ������� ������ A � ��������� ���������� �������
        int* A = new int[size];
        for (int i = 0; i < size; ++i) {
            A[i] = rand() % 10000; // ��������� ������ ���������� ������� �� 0 �� 9999
        }

        // ������� ������ B � �������� �������� � ������� ��������� �� A
        int* B = new int[size / 2];
        int index = 0;
        for (int i = 0; i < size; i += 2) {
            B[index++] = A[i];
        }

        clock_t start, end;

        // ����������� ����������
        start = clock(); // ���������� ����� ������ ����������
        bubbleSort(B, size / 2); // ��������� ����������� ����������
        end = clock(); // ���������� ����� ��������� ����������
        double bubbleSortTime = double(end - start) / CLOCKS_PER_SEC; // ��������� ����� ����������
        cout << "������ �������: " << size << ", ����� ����������� ����������: " << bubbleSortTime << " ������" << endl;

        // �������� �������� ����� ��� ���������� ��������
        index = 0;
        for (int i = 0; i < size; i += 2) {
            B[index++] = A[i];
        }

        // ���������� ��������
        start = clock(); // ���������� ����� ������ ����������
        mergeSort(B, 0, size / 2 - 1); // ��������� ���������� ��������
        end = clock(); // ���������� ����� ��������� ����������
        double mergeSortTime = double(end - start) / CLOCKS_PER_SEC; // ��������� ����� ����������
        cout << "������ �������: " << size << ", ����� ���������� ��������: " << mergeSortTime << " ������" << endl;

        // �������� �������� ����� ��� ���������� �������
        index = 0;
        for (int i = 0; i < size; i += 2) {
            B[index++] = A[i];
        }

        // ���������� �������
        start = clock(); // ���������� ����� ������ ����������
        selectionSort(B, size / 2); // ��������� ���������� �������
        end = clock(); // ���������� ����� ��������� ����������
        double selectionSortTime = double(end - start) / CLOCKS_PER_SEC; // ��������� ����� ����������
        cout << "������ �������: " << size << ", ����� ���������� �������: " << selectionSortTime << " ������" << endl;

        // �������� �������� ����� ��� ���������� ������� �������
        index = 0;
        for (int i = 0; i < size; i += 2) {
            B[index++] = A[i];
        }

        // ���������� ������� �������
        start = clock(); // ���������� ����� ������ ����������
        insertionSort(B, size / 2); // ��������� ���������� ������� �������
        end = clock(); // ���������� ����� ��������� ����������
        double insertionSortTime = double(end - start) / CLOCKS_PER_SEC; // ��������� ����� ����������
        cout << "������ �������: " << size << ", ����� ���������� ������� �������: " << insertionSortTime << " ������" << endl;

        // �������� �������� ����� ��� ���������� ������� �����
        index = 0;
        for (int i = 0; i < size; i += 2) {
            B[index++] = A[i];
        }

        // ���������� ������� �����
        start = clock(); // ���������� ����� ������ ����������
        shellSort(B, size / 2); // ��������� ���������� ������� �����
        end = clock(); // ���������� ����� ��������� ����������
        double shellSortTime = double(end - start) / CLOCKS_PER_SEC; // ��������� ����� ����������
        cout << "������ �������: " << size << ", ����� ���������� ������� �����: " << shellSortTime << " ������" << endl;

        // ����������� ������, ���������� ��� �������
        delete[] A;
        delete[] B;

        cout << "----------------------------------------" << endl;
    }

    return 0;
}
