#pragma once
#ifndef LS_LIB
#define LS_LIB

template <typename T>
double average(std::vector<T>& vect) {
	auto const count = static_cast<float>(vect.size());
	return std::accumulate(vect.begin(), vect.end(), 0.0) / count;
}

template <typename T>
double st_dev(std::vector<T>& vect) {
	const double avg = average(vect);
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}

template <typename T1, typename T2>
double st_dev(std::vector<T1>& vect, T2 avg) {
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}

double to_radians(double deg);
double to_degree(double rad);
std::string NumberToBin(int n);
int BinToNumber(std::string bin);

#endif // !LS_LIB

