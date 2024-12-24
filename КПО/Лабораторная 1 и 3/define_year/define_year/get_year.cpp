#include "stdafx.h"

int getYear(char* date) {
    return ((date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + date[7] - '0');
}