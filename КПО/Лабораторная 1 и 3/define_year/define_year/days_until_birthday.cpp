#include "stdafx.h"

int leftUntilBirthday(char* current_date, char* birth_date, int* months_list) {
    int daysLeft = 0;
    int day_current = getDay(current_date);
    int month_current = getMonth(current_date);
    int day_birth = getDay(birth_date);
    int month_birth = getMonth(birth_date);
    int year = getYear(current_date);
    int leap_year = isYearLeap(year);
    if (month_current < month_birth) { // если др еще будет в этом году
        for (int i = month_current; i < month_birth; i++) {
            daysLeft += months_list[i - 1];
        }
    }
    if (month_current > month_birth) { //если др был в предыдщуем мес€це
        for (int i = month_birth; i < month_current; i++) {
            daysLeft += months_list[i - 1];
        }
        daysLeft = 365 + leap_year - daysLeft;
    }
    if (month_current == month_birth && day_current > day_birth) { //если др был в текущем мес€це
        daysLeft += 365 + leap_year;
    }
    daysLeft += day_birth;
    daysLeft -= day_current;
    return daysLeft;
}