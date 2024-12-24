#include <iostream>
#include <chrono> // ���������� ��� ������ ������� chrono
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
    cout << "�������������� �������� �������: ";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
//���������� �������� ��� ������������� ����������
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
//������������� ���������� 
void heapSort(int* A, int N) {

    for (int i = N / 2; i >= 0; --i) {
        heapify(A, N, i);  //������ ��������, ����������������� ������
    }

    for (int i = N - 1; i > 0; i--) {
        //���������� ������� ������ � �����
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        //���������� ����������� ��������
        heapify(A, i, 0);
    }
}

//������� ���������� 
void quickSort(int* E, int first, int last) {
    // ���������� ����������
    int mid, count;
    int f = first, l = last;

    mid = E[(f + l) / 2];      // ����� �������� ��������

    // ���� ���������� ��������� �������
    do {
        // ����� ��������, ������� ������ ��� ����� ��������, ����� �� ��������
        while (E[f] < mid) {
            f++;
        }
        // ����� ��������, ������� ������ ��� ����� ��������, ������ �� ��������
        while (E[l] > mid) {
            l--;
        }
        // ����� ����������, ����� ��� �������� ����� �� �������� ���� ������ ��� ����� ���,
        // � ��� �������� ������ - ������ ��� �����
        if (f <= l) {
            count = E[f];
            E[f] = E[l];
            E[l] = count;
            f++;
            l--;
        }
    } while (f < l); // ���������, ���� ������� �� �����������

    // ����������� ����� ������� ��� ����������� ����� � ������ �� �������� ��������
    if (first < l) {
        quickSort(E, first, l);
    }
    if (f < last) {
        quickSort(E, f, last);
    }
}
//�������, ��������� �������
void merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2; 			//���������� �������� ��������
    start = first; 					//������ ����� �����
    final = middle + 1; 				//������ ������ �����
    for (j = first; j <= last; j++)		 //��������� �� ������ �� �����
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)  A[j] = mas[j];  //����������� ���������� � ������
    delete[]mas;
};
//���������� ��������
void mergeSort(int* A, int first, int last) {
    if (first < last)
    {
        mergeSort(A, first, (first + last) / 2); 	//���������� ����� �����
        mergeSort(A, (first + last) / 2 + 1, last); 	//���������� ������ �����
        merge(A, first, last); 				//������� ���� ������
    }
};

//���������� �����(���������)
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
    srand(time(NULL));  //������������� ����� ����� ������� �������
    int N;
    cout << "������� ������ N ������� A: ";
    cin >> N;
    while (N < 0) {
        cout << "������� �� ����������� �����. ���������� ��� ���: ";
        cin >> N;
    }
    int* A = new int[N]; //��������� ������������ ������ ���A ������� A
    //���������� ������� A
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 99;
    }
    //��������� ������������ ������ ��� ��������� ��������
    int* B = new int[N], * C = new int[N], * D = new int[N], * E = new int[N];
    //����� �������
    cout << "�������� ������� A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
        //����������� ��������� �� ������� A � ��������� �������
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
    }
    // ������������� ���������� ����������
    auto start = high_resolution_clock::now();
    heapSort(A, N);
    auto end = high_resolution_clock::now();
    duration<double, milli>duration = end - start;
    cout << "\n���������� ����� ������������� �����������: " << duration.count() << " ������" << endl;
    outputSortedArray(A, N);
    // ������� ����������
    start = high_resolution_clock::now();
    quickSort(B, 0, N - 1);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "���������� ����� ������� �����������: " << duration.count() << " ������" << endl;
    outputSortedArray(B, N);
    // ���������� ��������
    start = high_resolution_clock::now();
    quickSort(C, 0, N - 1);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "���������� ����� ����������� �������: " << duration.count() << " ������" << endl;
    outputSortedArray(C, N);
    // ���������� �����
    start = high_resolution_clock::now();
    insertSort(D, N);
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "���������� ����� ����������� �����: " << duration.count() << " ������" << endl;
    outputSortedArray(D, N);

    delete[] A, B, C, D, E;
    return 0;
}
