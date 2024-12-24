#include "stdafx.h"

int getMonth(char* date) {
    return (date[2] - '0') * 10 + date[3] - '0';
}