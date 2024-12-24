#include "stdafx.h"

int main() {
    setlocale(LC_ALL, "Rus");
     char date[9];
     cout << "Введите дату в формате ДДММГГГГ:" << endl;
     cin >> date;
     if (!isDateValid(date)) {
        while (!isDateValid(date)) {
            cout << "Введено некорретное значение даты. Попробуйте еще раз" << endl; cin >> date;
        }
     }
     // год, високосный год, день, месяц
     int year = getYear(date);
     int leap_year = isYearLeap(year);
     int day = getDay(date);
     int month = getMonth(date);
     int months_list[] = { 31, 28 + leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
     //високосность года
     if (leap_year) {
        cout << "Год високосный" << endl;
     }
     else {
        cout << "Год не является високосным" << endl;
            }
     // порядковый номер + название месяца + день программиста
     cout << "Введенный день имеет порядковый номер - " << getOrderOfDay(leap_year, day, month, months_list) << endl;
     cout << "Введенный месяц даты: " << getMonthName(month) << endl;

     cout << "В " << year << " году День программиста выпадает на " << 13 - leap_year << " сентября " << endl;
     // от текущей даты до др
     char current_date[9], birth_date[9];
     cout << "Введите текущую дату: " << endl;
     cin >> current_date;
     if (!isDateValid(current_date)) {
        while (!isDateValid(current_date)) {
            cout << "Введено некорретное значение даты. Попробуйте еще раз" << endl; cin >> current_date;
        }
     }
     cout << "Введите дату дня рождения: " << endl;
     cin >> birth_date;
     if (!isDateValid(birth_date)) {
        while (!isDateValid(birth_date)) {
            cout << "Введено некорретное значение даты. Попробуйте еще раз" << endl; cin >> birth_date;
        }
     }
     cout << "До дня рождения осталось дней: " << leftUntilBirthday(current_date, birth_date, months_list) << endl;
     return 0;
}
