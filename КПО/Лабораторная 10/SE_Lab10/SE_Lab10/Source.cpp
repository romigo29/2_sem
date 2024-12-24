#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // определить количество целых чисел в std::vector равных заданному.
	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1); // Подсчет количества элементов, равных 3
	cout << "число: " << target1 << " количество: " << num_items1 << endl; // лямбда-выражение для подсчета элементову кратных З.
	int num_items3 = count_if(v.begin(), v.end(), [](int i)
		{
			return i % 3 == 0; 
		});
	cout << "количество элементов, кратных 3 : " << num_items3 << endl;
	cout << "\n Лямбда , захват переменных" << endl; // лямбда-выражение, захват переменных 
	for (auto i : v) [i]() {
		if (i % 3 == 0) cout << i << " "; 
		}
	();

		cout << "\nЛямбда с параметрами" << endl; // Вывод вначетий кратных З. Значения будем передавать как параметр у обычной фукнции
	for (auto i : v)[](auto i) {
		if (i % 3 == 0) cout << i << " ";
		}(i);

	cout << endl << "Лямбда без параметров" << endl; // Вывод значений кратных З. // Значения передаются через захват переменных при этом пропустим скобки для добавления пі
	for (auto i : v) [i] {
		if (i % 3 == 0) cout << i << " "; 
		}();
}