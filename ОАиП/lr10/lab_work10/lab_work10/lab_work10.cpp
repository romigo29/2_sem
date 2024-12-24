#include <iostream>
using namespace std;

double factorial(double n) {  //Вычисляем факториал значения n
    if (!n) {
        return 1;
    }
    else  {
        return n * factorial(n - 1);
    }
}

double y(double x, double n) {
 
    return pow(x ,n) / factorial(n); //Используем рекурсию для вычисления функции
}

int main()  {

    setlocale(LC_ALL, "rus");
    double n, x;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите n: ";
    cin >> n;
    cout << "Результат: " << y(x, n) << endl;
    return 0;
}
