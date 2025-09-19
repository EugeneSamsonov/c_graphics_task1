#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
	do { \
		fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
		abort(); \
	} while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
	return a + b;
}

int edu_sub(int a, int b) {
	return a - b;
}

int edu_mult(int a, int b) {
	return a * b;
}

int edu_div(int a, int b) {
	return a / b;
}

int edu_mod(int a, int b) {
	return a % b;
}

int edu_pow(int a, int b) {
	if (b == 0) return 1;

	int base = a;
	for (int i = 1; i < b; ++i){
		a *= base;
	}
	return a;
}

int edu_abs(int a) {
	if (a < 0) return a * -1;
	
	return a;
}

int edu_gcd(int a, int b) {
	if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int edu_lcm(int a, int b) {
	return abs(a * b)/edu_gcd(a, b);
}

int edu_int_sqrt(int a) {
	if (a < 0) return -1;
	if (a == 0 || a == 1) return a;

	int start = 1, end = a, result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (mid * mid == a)
			return mid;
		if (mid * mid < a) {
			start = mid + 1;
			result = mid;
		} else {
			end = mid - 1;
		}
	}
	return result;
}

int edu_sgn(int a) {
	if (a < 0) return -1; 
	else if (a == 0) return 0;
	else return 1;
}

int edu_fact(int a) {
	if (a == 0) return 1;

	int res = 1;
	for (int i = 1; i <= a; ++i) {
		res *= i;
	}
	
	return res;
}
