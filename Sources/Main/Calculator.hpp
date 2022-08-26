#pragma once
#include <iostream>
#include <string>
#include <stack>

class Calculator
{
private:
	
	char m_input[20] = { 0 };
	const char* m_const_operation = "+-/*";
	double m_rezult = 0.0;
	std::stack<char> m_stackOperation;
	std::stack<double> m_stackNumbers;
public:
	
	Calculator() = default;
	Calculator(const Calculator& right);
	~Calculator() = default;
	Calculator& operator=(const Calculator& right);
	double calc (const std::string& input);
	void clear(char(&ch_temp)[20]);
};

