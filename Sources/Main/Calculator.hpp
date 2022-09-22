#pragma once
#include <iostream>
#include <string>
#include <vector>


class Calculator
{
private:

	char m_input[128] = { 0 };
	double m_result;
	std::vector<char> m_operation;
	std::vector<double> m_numbers;
	void separateNumbersFromSign(const std::string& str);
	void clearTempArray();
	void calculate();
	void eraseValueAndSign(int i);
	void operation(int i);

public:

	Calculator() = default;
	~Calculator() = default;
	double calc(const std::string& str);
};

