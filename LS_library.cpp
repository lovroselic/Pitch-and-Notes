/*
	v 1.0
*/
#include <vector>
#include <numeric>
#include <cmath>
#include <string>
#include "LS_library.h";
#define PI 3.14159265


double to_radians(double deg) {
	return deg * PI / 180;
}
double to_degree(double rad) {
	return rad * 180 / PI;
}

std::string NumberToBin(int n) {
	std::string bin = "";
	do {
		int bit = n % 2;
		bin = std::to_string(bit) + bin;
		n /= 2;
	} while (n > 0);
	return bin;
}

int BinToNumber(std::string bin) {
	int n = 0;
	for (int i = 0; i < bin.size(); i++) {
		int j = bin.size() - 1 - i;
		if (bin[j] == '1') {
			n += std::pow(2, i);
		}
	}
	return n;
}