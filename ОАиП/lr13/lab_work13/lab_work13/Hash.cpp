#include "Hash.h"
#include <iostream>

int HashFunction(int key, int size) // Мультипликативная хеш-функция
{
	double A = (sqrt(5) - 1) / 2; // Число Кнута
	double hashValue = size * (key * A - int(key * A)); // Вычисляем значение хеша
	return static_cast<int>(hashValue); // Возвращаем значение хеша как целое число
}
//Функция вычисления следующего хэша
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}

//Создание хэш-таблицы с введенным размером
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//Создание хэш-таблицы
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i) //Заполнение таблицы пустыми ячейками согласно размеру
		data[i] = NULL;
}
//Вставка ключ-элемента в таблицу
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size);
			i != size && !b; j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL) //Если ячейка не пустая и не удалена
			{
				data[j] = d; //Вставляем элемент
				N++;  //Увеличиваем количество заполненных ячеек
				b = true;
			}
	return b;
}
//Поиска ключа
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size); data[j] != NULL && i
			!= size && !b; j = HashFunction(key, size))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//Поиск элемента
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//Удаление элемента из таблицы по заданному ключу
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//Удаление по значению
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//Проверка, является ячейка заполненной, пустой или удаленной
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << " пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << " удален" << std::endl;
			else
				f((this->data)[i]);
	}
}