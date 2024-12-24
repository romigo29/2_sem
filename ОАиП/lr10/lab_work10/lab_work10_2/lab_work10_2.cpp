#include <iostream>
using namespace std;

const int MAX = 100; // Максимальное количество стран
int matrix[MAX][MAX]; // Матрица смежности
int colors[MAX]; // Цвета стран: 0 (не окрашена), 1 и 2 (две группы)

int n; // Количество стран

bool canColor(int country, int color) {
    for (int i = 0; i < n; ++i) {
        if (matrix[country][i] && colors[i] == color) {
            return false; // Если есть смежная страна с тем же цветом, вернуть false
        }
    }
    return true;
}

bool colorCountries(int country) {
    if (country == n) { // Если все страны были окрашены
        return true;
    }

    for (int c = 1; c <= 2; ++c) {
        if (canColor(country, c)) {
            colors[country] = c; // Окрасить страну в цвет c

            if (colorCountries(country + 1)) { // Рекурсивно окрасить следующую страну
                return true;
            }

            colors[country] = 0; // Откатить окраску текущей страны
        }
    }

    return false; // Не удалось окрасить текущую страну
}

int main() {

    setlocale(LC_ALL, "rus");
    cout << "Введите количество стран: ";
    cin >> n;

    cout << "Введите матрицу смежности:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (colorCountries(0)) {
        cout << "Страны можно разделить на две группы с минимальным количеством смежных пар.\n";
        cout << "Группа 1:\n";
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 1) {
                cout << i << " ";
            }
        }
        cout << "\nГруппа 2:\n";
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 2) {
                cout << i << " ";
            }
        }
    }
    else {
        cout << "Невозможно разделить страны на две группы с минимальным количеством смежных пар.\n";
    }

    return 0;
}
