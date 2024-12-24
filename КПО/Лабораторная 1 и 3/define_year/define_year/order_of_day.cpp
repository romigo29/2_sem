#include "stdafx.h"

int getOrderOfDay(int leap_year, int day, int month, int *months_list) {
    
    int dayOrder = 0;
  
    for (int i = 0; i < month - 1; i++) {
        dayOrder += months_list[i];
    }
    dayOrder += day;
    return dayOrder;
}