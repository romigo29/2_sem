#include <iostream>
#include <chrono> // ���������� ��� ������ ������� chrono
using namespace std;
using namespace chrono;

int getSequenceCycle(int N);
int getSequenceRecursion(int N);

int getSequenceCycle(int N) {
    if (N == 1) {
        return 0;
    }
    if (N == 2) {
        return 1;
    }
    int sum = 0, n1 = 0, n2 = 1;
    for (int i = 0; i < N - 2; i++) {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return sum;
}

int getSequenceRecursion(int N) {
    if (N == 1) {
        return 0;
    }
    if (N == 2) {
        return 1;
    }

    return getSequenceRecursion(N - 1) + getSequenceRecursion(N - 2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    long long int N;
    cout << "������� n-��� ����� �� ������������������ ���������: ";
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
    

    // ����� ����
    auto start = high_resolution_clock::now(); // ������ ������� ������� ������ �������
    cout << "����� ��������� ��� ������� " << N << ": " << getSequenceCycle(N) << endl;
    auto end = high_resolution_clock::now(); // ����� ������� ������� ������ �������
    duration<float>duration = end - start;
    int minutes = duration.count() / 60;
    int seconds = duration.count();
    cout << "���������� ����� ������: " << minutes << " ����� " << seconds << " ������" << endl;
    // ����� ��������
    start = high_resolution_clock::now(); 
    cout << "����� ��������� ��� ������� " << N << ": " << getSequenceRecursion(N) << endl;
    end = high_resolution_clock::now(); 
    duration = end - start;
    minutes = duration.count() / 60;
    seconds = duration.count();
    cout << "���������� ����� ���������: " << minutes << " ����� " << seconds << " ������" << endl;
    cout << minutes;
    return 0;
}
