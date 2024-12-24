#include "stdafx.h"

int getDay(char* date) {
    return (date[0] - '0') * 10 + date[1] - '0';
}
