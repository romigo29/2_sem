#include <iostream>
#include <ctime> 
#include <cmath>
using namespace std;

void outputArray(int*, int);
void goodsSort(int* B, int n);

void outputArray(int* array, int N) {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swapElements(int* B, int el1, int el2) {
    int temp = B[el2];
    B[el2] = B[el1];
    B[el1] = temp;
}

void goodsSort(int* A, int n) {
    int even = 1;
    for (int i = 0; i < n - 1; i++) {
        if (even <= i) {
            even = even + 2;
            continue;
        }

        if (A[i] < A[even]) {
            swapElements(A, i, even);
            even = even + 2;
            i++;
        }
    }
    if (A[n - 1] < A[n - 2]) {
        swapElements(A, n - 1, n - 2);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  //������������� ����� ����� ������� 
    long int N;
    int* B;  //���������� �������
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
    cout << "�������� ������: ";
    outputArray(A, N);
    // ���������� ���������
    goodsSort(A, N);
    cout << endl;
    cout << "�������������� �������� �������: ";
    outputArray(A, N);
    
    delete[] A;
    return 0;
}
