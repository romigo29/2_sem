#include "stdafx.h"
#include "Dictionary.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

//если определено более одного макроса
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)) > 1
#error Установлено более одного макроса!
#endif

	try {
#ifdef TEST_CREATE_01   //Переполнение имени словаря
		Dictionary::Instance test1 = Dictionary::Create((char*)"AAAAAAAAAAAAAAAAAAAAAAAAA", 5);
#endif

#ifdef TEST_CREATE_02   //Переполнение размера словаря
		Dictionary::Instance test2 = Dictionary::Create((char*)"test2 info", 101);
#endif

#ifdef TEST_ADDENTRY_03  //Переполнение словаря
		Dictionary::Instance test3 = Dictionary::Create((char*)"test info3", 0);
		Dictionary::Entry test3_ed = { 1, (char*)"test3_ed" };
		Dictionary::AddEntry(test3, test3_ed);
#endif

#ifdef TEST_ADDENTRY_04   //Дублирование элемента
		Dictionary::Instance test4 = Dictionary::Create((char*)"test4", 2);
		Dictionary::Entry test4_info = { 1, (char*)"test4_info" };
		Dictionary::AddEntry(test4, test4_info);
		Dictionary::AddEntry(test4, test4_info);
#endif

#ifdef TEST_GETENTRY_05  //Элемент в словаре не найден по id
		Dictionary::Instance test5 = Dictionary::Create((char*)"test5", 2);
		Dictionary::Entry test5_info = { 1, (char*)"test5_info" };
		Dictionary::AddEntry(test5, test5_info);
		Dictionary::GetEntry(test5, 2);
#endif

#ifdef TEST_GETENTRY_06  //Элемент в словаре не найден по id
		Dictionary::Instance test6 = Dictionary::Create((char*)"test6", 2);
		Dictionary::Entry test6_info = { 1, (char*)"test6_info" };
		Dictionary::AddEntry(test6, test6_info);
		Dictionary::DelEntry(test6, 2);
#endif

#ifdef TEST_UPDENTRY_07  //Элемент в словаре не найден по id
		Dictionary::Instance test7 = Dictionary::Create((char*)"test7", 2);
		Dictionary::Entry test7_info = { 1, (char*)"test7_info" };
		Dictionary::AddEntry(test7, test7_info);
		Dictionary::UpdEntry(test7, 2, test7_info);
#endif

#ifdef TEST_UPDENTRY_08   //Дублирование элемента
		Dictionary::Instance test8 = Dictionary::Create((char*)"test8", 2);
		Dictionary::Entry test8_info = { 1, (char*)"test8_info" };
		Dictionary::AddEntry(test8, test8_info);
		Dictionary::UpdEntry(test8, 1, test8_info);
#endif

#ifdef TEST_DICTIONARY
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
		Dictionary::Instance d1 = Dictionary::Create((char*)"Преподаватели", 5);    //создание словаря
		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },      //элементы словаря
			e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" };
		Dictionary::AddEntry(d1, e1);                                        //добавление элемента в словарь
		Dictionary::AddEntry(d1, e2);                                        //добавление элемента в словарь
		Dictionary::AddEntry(d1, e3);                                        //добавление элемента в словарь
		Dictionary::AddEntry(d1, e4);                                        //добавление элемента в словарь
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);                 //найти элемент в словаре по идентификатору
		Dictionary::DelEntry(d1, 2);                                         //удалить элемент по идентифкатору
		Dictionary::Entry newentry1 = { 6, "Гурин" };                        //элемент словаря по идентификатору
		Dictionary::UpdEntry(d1, 3, newentry1);                              //заменить элемент словаря по идентификатору
		Dictionary::Print(d1);                                               //распечатать элементы сллваря 
		Dictionary::Instance d2 = Dictionary::Create((char*)"Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);

#endif
	}

	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}