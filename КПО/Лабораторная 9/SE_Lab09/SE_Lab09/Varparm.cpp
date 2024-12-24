#include "Varparm.h"

namespace Varparm {
	// Функция для работы с параметрами типа int
	int ivarparm(int amm, ...) {
		if (!amm) {
			return 0;
		}
		int product = 1;
		int *var = &amm;
		product *= *(var);
		for (int i = 1; i < amm; i++) {
			product *= *(var + i);
		}
		return product;
	}
	// Функция для работы с параметрами типа short
	int svarparm(short amm, ...) {
		int* var = (int*) & amm;  //явное преобразование типа
		int max = 0;   //пусть максимальный элемент = 0
		for (int i = 0; i <= amm; i++) {
			if (*(var + i) > max) {
				max = *(var + i);
			}
		}
		return max;
	}

	double fvarparm(float n, ...) {
		double sum = (double)n;
		double* ptr = (double*)(&n + 1);
		if (n == FLT_MAX)
			return 0;
		for (int i = 0; ptr[i] != (double)FLT_MAX; i++) {
			sum += ptr[i];
		}
		return sum;
	}

	double dvarparm(double n, ...) {
		double sum = n;
		double* ptr = &n + 1;
		if (n == DBL_MAX)
			return 0;
		for (int i = 0; ptr[i] != DBL_MAX; i++) {
			sum += ptr[i];
		}
		return sum;
	}
}