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
	for (int i = 0; i < 20; ++i)
	{
		m_input[i] = ' ';
	}
}

void Calculator::eraseValueAndSign(int i)
{
	m_numbers.erase(m_numbers.begin() + i);
	m_operation.erase(m_operation.begin() + i);
}

void Calculator::calculate()
{
	int i = 0;
	while (!m_operation.empty())
	{
		switch (m_operation[i])
		{
		case'-':
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '*' || i + 1 < m_operation.size() && m_operation[i + 1] == '/')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == ')')
			{
				m_numbers[i + 1] = m_numbers[i] - m_numbers[i + 1];
				eraseValueAndSign(i);
				break;
			}
			else
			{
				m_numbers[i + 1] = m_numbers[i] - m_numbers[i + 1];
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
			}
			break;

		case'+':
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '*' || i + 1 < m_operation.size() && m_operation[i + 1] == '/')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == ')')
			{
				m_numbers[i + 1] = m_numbers[i] + m_numbers[i + 1];
				eraseValueAndSign(i);
				break;
			}
			else
			{
				m_numbers[i + 1] = m_numbers[i] + m_numbers[i + 1];
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
			}
			break;

		case'*':
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == ')')
			{
				m_numbers[i + 1] = m_numbers[i] * m_numbers[i + 1];
				eraseValueAndSign(i);
				break;
			}
			else
			{
				m_numbers[i + 1] = m_numbers[i] * m_numbers[i + 1];
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
			}
			break;

		case'/':
			if (i + 1 < m_operation.size() && m_operation[i + 1] == '(')
			{
				++i;
				break;
			}
			if (i + 1 < m_operation.size() && m_operation[i + 1] == ')')
			{
				m_numbers[i + 1] = m_numbers[i] / m_numbers[i + 1];
				eraseValueAndSign(i);
				break;
			}
			else
			{
				m_numbers[i + 1] = m_numbers[i] / m_numbers[i + 1];
				eraseValueAndSign(i);
				if (i > 0)
				{
					--i;
				}
			}
			break;
		
		case '(':
			m_operation.erase(m_operation.begin() + i);
			break;
		case ')':
			m_operation.erase(m_operation.begin() + i);
			--i;
		}
	}
	m_result = m_numbers[0];
}