#include "stdafx.h"

const char* getMonthName(int month) {
	const char* months[12] = {"€нварь", "февраль", "март", "апрель", "май", "июнь", "июль", "август",
	"сент€брь", "окт€брь", "но€брь", "декабрь" };
	const char* month_name = months[month - 1];
	return month_name;
}