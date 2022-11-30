#pragma once
#ifndef CODEABBEY
#define CODEABBEY

std::string joinVector(const std::vector<std::string>& data, const std::string separator);

template <typename T>
std::string joinVector(const std::vector<T>& data, const std::string separator) {
	std::string result = "";
	if (data.size() == 0) return result;
	result += std::to_string(data.at(0));
	if (data.size() > 1) {
		for (auto i = 1; i < data.size(); i++) {
			result += separator;
			result += std::to_string(data.at(i));
		}
	}
	return result;
}

std::vector<std::string> loadData(std::string name);
std::vector<std::string> splitString(std::string str, const std::string separator);
std::vector<std::string> splitString(std::string str);
std::vector<int> stringVectorToInt(std::vector<std::string>& vct);
std::vector<int> splitToInt(std::string str, const std::string separator);
std::vector<int> splitToInt(std::string str);
std::string Compact(std::string str);
std::string Pack(std::vector<std::string>& cell);
std::string StringToUpper(std::string str);
std::vector<std::string> IntToHex(std::vector<int>& ints);

#endif // !CODEABBEY
