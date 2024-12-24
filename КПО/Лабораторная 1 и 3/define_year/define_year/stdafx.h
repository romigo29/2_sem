#pragma once
#include <iostream>
#include <cctype>
using namespace std;
//прототипы функций
bool isDateValid(char* date);
int isYearLeap(int year);
int getDay(char* date);
int getMonth(char* date);
int getYear(char* date);
int getOrderOfDay(int leap_year, int day, int month, int* months_list);
int leftUntilBirthday(char* current_date, char* birth_date, int* months_list);
const char* getMonthName(int month);
