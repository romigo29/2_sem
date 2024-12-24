#include "Heap.h"
#include <iostream>
#include <iomanip>
//Печать элементов из кучи
void AAA::print() const {
	cout << x;
}
namespace heap  {
	Heap create(int maxsize, CMP(*f)(void*, void*))  { // Создание кучи с заданным максимальным размером и функцией сравнения
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix) const  { //Получение индекса левого потомка
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix) const  {  //Получение индекса правого потомка
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)  { //Получение индекса родительского элемента
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)  { // Метод для обмена элементов
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)  {  // Метод для преобразования кучи в кучу
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)  {
			if (isGreat(storage[l], storage[ix])) {
				irl = l;
			}
			if (r > 0 && isGreat(storage[r], storage[irl])) {
				irl = r;
			}
			if (irl != ix)  {
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)  {  // Метод для вставки элемента в кучу
		int i;
		if (!isFull())  {
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))  {
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	// Метод для извлечения максимального элемента из кучи
	void* Heap::extractMax()  {  
		void* rc = nullptr;
		if (!isEmpty())  {
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	//Вывод значений элементов на экран
	void Heap::scan(int i) const {
		int probel = 20; // Начальное количество пробелов перед каждым значением
		cout << '\n'; // Переход на новую строку перед выводом значений
		// Проверяем, пуста ли куча
		if (size == 0) {
			cout << "Куча пуста"; // Если куча пуста, выводим соответствующее сообщение
		}
		// Проходим по всем элементам кучи для вывода значений
		for (int u = 0, y = 0; u < size; u++) {
			cout << setw(probel + 10) << setfill(' '); // Устанавливаем отступ перед значением
			// Выводим значение элемента, приведенное к типу AAA
			((AAA*)storage[u])->print();
			// Проверяем, нужно ли переходить на новую строку для вывода следующего уровня
			if (u == y) {
				cout << '\n'; // Переходим на новую строку
				if (y == 0) {
					y = 2; // Если это первый уровень, устанавливаем следующий уровень на 2
				}
				else {
					y += y * 2; // Иначе увеличиваем следующий уровень в два раза
				}
			}
			// Уменьшаем количество пробелов перед следующим значением в два раза
			probel /= 2;
		}
		cout << '\n'; // Переход на новую строку после вывода всех значений
	}
	// Удаление минимального элемента
	void* Heap::extractMin()  {
		void* rc = nullptr;
		if (!isEmpty())  {
			rc = storage[size - 1];
			size--;
			heapify(0);
		}
		return rc;
	}
	// Удаление i-ого элемента
	void* Heap::extractI(int i)  {
		void* rc = nullptr;
		if (!isEmpty() && i >= 0 && i < size) {
			rc = storage[i];
			storage[i] = storage[size - 1];
			size--;
			heapify(0);
		}
		return rc;
	}
	// Объединение двух куч
	void Heap::unionHeap(Heap& other)  {
		for (int i = 0; i < other.size; i++)  {
			insert(other.storage[i]);
		}
		other.size = 0; //очищение дополнительной кучи
	}
	// Вывод минимального значения в куче
	void Heap::getMin()  {
		if (!isEmpty()) {
			// Инициализируем минимальное значение как значение первого элемента
			void* minVal = storage[0];
			// Проходим по всем элементам кучи, начиная со второго
			for (int i = 1; i < size; ++i) {
				// Если текущий элемент меньше минимального, обновляем минимальное значение
				if (compare(storage[i], minVal) == LESS) {
					minVal = storage[i];
				}
			}
			cout << "Минимальный элемент в куче: ";
			((AAA*)minVal)->print();
			cout << endl;
		}
		else {
			cout << "Куча пуста" << endl;
		}
	}
	// Вывод максимального значения в куче
	void Heap::getMax()  {
		if (!isEmpty())  {
			cout << "Максимальный элемент в куче: ";
			((AAA*)storage[0])->print();
			cout << std::endl;
		}
		else  {
			cout << "Куча пуста" << endl;
		}
	}
	// Функция для очистки кучи (удаление всех элементов)
	void Heap::clear() {
		for (int i = 0; i < size; ++i) {
			delete (AAA*)storage[i]; // Освобождаем память для каждого элемента
		}
		size = 0; // Устанавливаем размер кучи в 0
		cout << "Куча очищена!" << endl;
	}
}