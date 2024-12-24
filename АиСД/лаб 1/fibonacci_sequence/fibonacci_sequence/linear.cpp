#include <iostream>
#include <chrono> // библиотека для вызова функции chrono
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
    cout << "Введите n-ное число из последовательности Фибоначчи: ";
    cin >> N;

    while (cin.fail()) {
        cout << "Неверный ввод. Попробуйте еще раз: ";
        cin.clear(); // сбрасываем флаг ошибки ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // гарантируем, что все символы будут проигнорированы
        cin >> N; // считаем число еще раз
    }

    while (N < 0) {
        cout << "Введено не натуральное число. Попробуйте еще раз: ";
        cin >> N;
    }
    

    // через цикл
    auto start = high_resolution_clock::now(); // начало отсчета времени работы функции
    cout << "Число Фибоначчи под номером " << N << ": " << getSequenceCycle(N) << endl;
    auto end = high_resolution_clock::now(); // конец отсчета времени работы функции
    duration<float>duration = end - start;
    int minutes = duration.count() / 60;
    int seconds = duration.count();
    cout << "Рассчетное время циклом: " << minutes << " минут " << seconds << " секунд" << endl;
    // через рекурсию
    start = high_resolution_clock::now(); 
    cout << "Число Фибоначчи под номером " << N << ": " << getSequenceRecursion(N) << endl;
    end = high_resolution_clock::now(); 
    duration = end - start;
    minutes = duration.count() / 60;
    seconds = duration.count();
    cout << "Рассчетное время рекурсией: " << minutes << " минут " << seconds << " секунд" << endl;
    cout << minutes;
    return 0;
}
