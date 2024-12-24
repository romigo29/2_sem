#include "Call.h"

int main(){

	setlocale(LC_ALL, "rus");

	int a = 1, b = 3, c = 5, d = 7;

	Call::cdecl_func(a, b, c);

	Call::stdcall_func(a, b, c);

	Call::fastcall_func(a, b, c, d);


	return 0;
}

