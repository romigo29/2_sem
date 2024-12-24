#include <iostream>
using namespace std;

namespace Call {

	int _cdecl cdecl_func(int a, int b, int c) {
		return a + b + c;
	}

	int _stdcall stdcall_func(int a, int& b, int& c) {
		return a * b * c;
	}

	int _fastcall fastcall_func(int a, int b, int c, int d) {
		return a + b + c + d;
	}
}
