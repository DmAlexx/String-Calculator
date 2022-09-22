#include "Calculator.hpp"

double Calculator::calc(const std::string& str)
{
	separateNumbersFromSign(str);
	calculate();
	return m_result;
}

void Calculator::separateNumbersFromSign(const std::string& str)
{
	double temp = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		switch (str[i])
		{
		case '+':
		case '-':
		case '/':
		case '*':
			m_operation.push_back(str[i]);
			m_numbers.push_back(temp);
			temp = 0;
			clearTempArray();
			break;
		case '(':
		case ')':
			m_operation.push_back(str[i]);
			clearTempArray();
			break;
		default:
			m_input[i] = str[i];
			temp = atof(m_input);
		}
	}
	m_numbers.push_back(temp);
}

void Calculator::clearTempArray()
{
	for (int i = 0; i < sizeof(m_input); ++i)
	{
		m_input[i] = ' ';
	}
}

void Calculator::eraseValueAndSign(int i)
{
	m_numbers.erase(m_numbers.begin() + i);
	m_operation.erase(m_operation.begin() + i);
}

void Calculator::operation(int i)
{
	if (m_operation[i] == '-')
	{
		m_numbers[i + 1] = m_numbers[i] - m_numbers[i + 1];
	}
	if (m_operation[i] == '+')
	{
		m_numbers[i + 1] = m_numbers[i] + m_numbers[i + 1];
	}
	if (m_operation[i] == '*')
	{
		m_numbers[i + 1] = m_numbers[i] * m_numbers[i + 1];
	}
	if (m_operation[i] == '/')
	{
		m_numbers[i + 1] = m_numbers[i] / m_numbers[i + 1];
	}
}

void Calculator::calculate()
{
	int i = 0;
	while (!m_operation.empty())
	{
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '*' || i + 1 < m_operation.size() && m_operation[i + 1] == '/')
			{
				++i;
			} 
			if (i + 1 < m_operation.size() && m_operation[i + 1] == ')')
			{
				m_operation.erase(m_operation.begin() + i + 1);
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				m_operation.erase(m_operation.begin() + i + 1);
				++i;
				operation(i);
				eraseValueAndSign(i);
			}
			else
			{
				operation(i);
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
			}
	}
	m_result = m_numbers[0];
}