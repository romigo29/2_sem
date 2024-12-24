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
    cout << "Введите число натуральное число N: "; 
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

    int variant = 0, left_border = 1, right_border = N;
    cout << "\nЗагадайте число от 1 до " << N << ". Я попробую угадать" << endl;
    while (variant != 3) {
        int average = (left_border + right_border) / 2;
        cout << "Мое предположение: " << average << "  (1 - мало, 2 - много, 3 - угадали)" << endl; cin >> variant;
        
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
            cout << "Ура!" << endl;
            cout << "Максимальное количество шагов = ";
            getLogarithm(N);
            break;
            }
        default: {
            cout << "Выберите вышеуказанные цифры!" << endl;
            break;
            }
        }
    }
    return 0;
}
