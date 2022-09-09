#pragma once
#include <iostream>
#include <string>
#include <vector>


class Calculator
{
private:

	char m_input[20] = { 0 };
	double m_rightExpressionValue = 0;
	double m_leftExpressionValue = 0;
	double m_result;
	std::vector<char> m_operation;
	std::vector<double> m_numbers;
	void separateNumbersFromSign(const std::string& str);
	void clearTempArray();
	void calculate();
	void eraseValueAndSign(int i);
		
public:

	Calculator() = default;
	~Calculator() = default;
	double calc(const std::string& str);
};

