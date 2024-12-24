#include <iostream>   // подключение библиотеки для работы с вводом/выводом данных на экран
using namespace std; // подключение стандартного пространства имен
// прототипы функций
int delNegative(int n, ...);

int delNegative(int n, ...) {
	int* ptr = &n;
	int counter_zero = 0; // счетчик нулей для добавления
	for (int i = 1; i <= n; i++) {
		if (*(ptr) < 0) {
			counter_zero++;
		}
		else
			return i;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");  // подключение русского алфавита
	cout << delNegative(3, 7, 2, 9);
	cout << delNegative(5, -1, 0, 8, 4, -2);
	cout << delNegative(8, 0, 7, -3, -2, 6, -1, 1, 9);
	return 0;  // возвращение значения 0 по окончанию программы 
}
