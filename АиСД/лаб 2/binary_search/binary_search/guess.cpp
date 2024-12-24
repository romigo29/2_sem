#include <iostream>
#include <cmath>
using namespace std;
void getLogarithm(int n);

void getLogarithm(int n) {

    int steps = ceil(log2(n));
    cout << steps << endl;
    for (int i = 0; i < steps + 1; i++) {
        cout << n << endl;
        n = (n + 1) / 2;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    
    int N;
    cout << "������� ����� ����������� ����� N: "; 
    cin >> N;
    while (cin.fail()) {
        cout << "�������� ����. ���������� ��� ���: ";
        cin.clear(); // ���������� ���� ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �����������, ��� ��� ������� ����� ���������������
        cin >> N; // ������� ����� ��� ���
    }

    while (N < 0) {
        cout << "������� �� ����������� �����. ���������� ��� ���: ";
        cin >> N;
    }

    int variant = 0, left_border = 1, right_border = N;
    cout << "\n��������� ����� �� 1 �� " << N << ". � �������� �������" << endl;
    while (variant != 3) {
        int average = (left_border + right_border) / 2;
        cout << "��� �������������: " << average << "  (1 - ����, 2 - �����, 3 - �������)" << endl; cin >> variant;
        
        switch (variant) {
        case 1: {
            left_border = average;
            break;
            }
        case 2: {
            right_border = average;
            break;
            }
        case 3: {
            cout << "���!" << endl;
            cout << "������������ ���������� ����� = ";
            getLogarithm(N);
            break;
            }
        default: {
            cout << "�������� ������������� �����!" << endl;
            break;
            }
        }
    }
    return 0;
}
