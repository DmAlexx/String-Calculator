#pragma once
#include <iostream>
#include <string>
#include <stack>

class Calculator
{
private:

	char m_input[20] = { 0 };
	double m_result = 0.0;
	double m_rightExpressionValue = 0;
	double m_leftExpressionValue = 0;
	std::stack<char> m_stackOperation;
	std::stack<double> m_stackNumbers;
	void clearTempArray(char(&m_input)[20]);
	void fillStacksFirstElement(int i, double& temp, std::string str);
	void fillStacks(int i, double temp, std::string input);
	void getExpressionValue();
	void sortStacks();

public:

	Calculator() = default;
	~Calculator() = default;
	double calc(const std::string& str);
};

