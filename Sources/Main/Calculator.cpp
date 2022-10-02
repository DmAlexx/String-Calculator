#include "Calculator.hpp"

double Calculator::calc(const std::string& str)
{
	separateNumbersFromSign(str);
	calculate();
	return m_result;
}

//Function that parsing string to signs and numbers
//Place signs and numbers to vectors
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

//Arithmetical operations with numbers
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

//Logic, priority of operation
void Calculator::calculate()
{
	int i = 0;
	while (!m_operation.empty())
	{
		switch (m_operation[i])
		{
		case '(':
		case ')':
			m_operation.erase(m_operation.begin() + i);
			break;
		case '*':
		case '/':
			
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				++i;
				break;
			}
			else
			{
				operation(i);
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
				break;
			}
		case '-':
		case '+':
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '*' || i + 1 < m_operation.size() && m_operation[i + 1] == '/')
			{
				++i;
				break;
			}
			else
			{
				operation(i);
				eraseValueAndSign(i);
				if (i > 0 && i + 1 < m_operation.size() && m_operation[i + 1] != ')')
				{
					--i;
				}
				break;
			}
		}
	}
	m_result = m_numbers[0];
}