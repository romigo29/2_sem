#include <iostream> // ����������� ���������� ��� ������ � ������/������� ������
using namespace std; // ����������� ������������ ������������ ����
// ��������� �������
void delNegative(int* n, ...);
void outputArray(int* array);
// ������� �������� ������������� ��������� � ���������� 0 � ����� �������
void delNegative(int* n, ...) {
    int size = *n; //������ �������
    int* ptr = n; // ��������� �� ������ ������� �������
    for (int i = 1; i <= size; i++) {
        if (*(ptr + i) < 0) {
            for (int j = i; j < size; j++) { // ���������� �������� �� ���� ������� �����
                *(ptr + j) = *(ptr + j + 1);
            }
            *(ptr + size) = 0; // ��������� ��������� ������� �����
            size--; // ��������� ������ �������
            i--; // ��������� ������� ������� ������
        }
    }
}
// ������� ������ ��������
void outputArray(int* array) {
    int size = *array;
    for (int i = 1; i <= size; i++) {
        cout << array[i] << " "; // �������� ��������� �������� �� �������, ��� ��� ������ ������� - ��� ������ �������
    }
    cout << endl;
}
// ������� �������
int main()
{
    setlocale(LC_ALL, "RUS");
    int arr1[4] = { 3, 7, -2, 9 }; // ������ 1
    int arr2[8] = { 5, -1, 10, 8, 4, -2 }; // ������ 2
    int arr3[9] = { 8, 0, 7, -3, -2, 6, -1, 1, 9 }; // ������ 3
    //����� �������� ����������
    cout << "������ ������: "; outputArray(arr1);
    cout << "������ ������: "; outputArray(arr2);
    cout << "������ ������: "; outputArray(arr3);
    // ������ ������� 
    delNegative(arr1);
    delNegative(arr2);
    delNegative(arr3);
    cout << "������� ����� �����������: " << endl;
    //����� �������� ����������
    cout << "������ ������: "; outputArray(arr1);
    cout << "������ ������: "; outputArray(arr2);
    cout << "������ ������: "; outputArray(arr3);

    return 0;
}
