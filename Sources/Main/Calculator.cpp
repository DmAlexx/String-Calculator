#include "Calculator.hpp"
#include <cmath>

Calculator::Calculator(const Calculator& right)
{
	for (int i = 0; i < 20; ++i)
	{
		m_input[i] = right.m_input[i];
	}
}

Calculator& Calculator::operator=(const Calculator& right)
{
	for (int i = 0; i < 20; ++i)
	{
		m_input[i] = right.m_input[i];
	}
	return *this;
}

void Calculator::clear(char (&ch_temp)[20])
{
	for (int j = 0; j < 20; ++j)
	{
		ch_temp[j] = ' ';
	}
}

double Calculator::calc(const std::string& input)
{
	double temp = 0;
	double temp1 = 0;
	double x = 0;
	double y = 0;
	char ch_temp[20] = { 0 };
	memcpy(m_input, input.c_str(), sizeof(input));
		for (int i = 0; i < sizeof(m_input); ++i)
		{
			switch (m_input[i])
			{
			case '+':
				if (m_stackOperation.empty() == true)
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '-')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y - x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '+')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y + x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '/')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y / x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '*')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y * x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				break;
			case '-':
				if (m_stackOperation.empty() == true)
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '-')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y - x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '+')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y + x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '/')
				{
					
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					temp1 = y / x;
					m_stackNumbers.push(temp1);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '*')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(x * y);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				break;
			case '/':
				if (m_stackOperation.empty() == true)
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '-' || m_stackOperation.top() == '+')
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '/')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y / x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '*')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(x * y);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				break;
			case '*':
				if (m_stackOperation.empty() == true)
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '-' || m_stackOperation.top() == '+')
				{
					m_stackOperation.push(m_input[i]);
					m_stackNumbers.push(temp);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '/')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(y / x);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				if (m_stackOperation.top() == '*')
				{
					m_stackNumbers.push(temp);
					x = m_stackNumbers.top();
					m_stackNumbers.pop();
					y = m_stackNumbers.top();
					m_stackNumbers.pop();
					m_stackNumbers.push(x * y);
					m_stackOperation.pop();
					m_stackOperation.push(m_input[i]);
					temp = 0;
					clear(ch_temp);
					break;
				}
				break;

			default:
				ch_temp[i] = m_input[i];
				temp = atof(ch_temp);
			}
		}

		temp = atof(ch_temp);
		m_stackNumbers.push(temp);

		while (m_stackOperation.empty() != true)
		{
			switch (m_stackOperation.top())
			{
			case '+':
				x = m_stackNumbers.top();
				m_stackNumbers.pop();
				y = m_stackNumbers.top();
				m_stackNumbers.pop();
				m_stackNumbers.push(x + y);
				m_stackOperation.pop();
				break;
			case '-':
				x = m_stackNumbers.top();
				m_stackNumbers.pop();
				y = m_stackNumbers.top();
				m_stackNumbers.pop();
				m_stackNumbers.push(y - x);
				m_stackOperation.pop();
				break;
			case '/':
				x = m_stackNumbers.top();
				m_stackNumbers.pop();
				y = m_stackNumbers.top();
				m_stackNumbers.pop();
				m_stackNumbers.push(y / x);
				m_stackOperation.pop();
				break;
			case '*':
				x = m_stackNumbers.top();
				m_stackNumbers.pop();
				y = m_stackNumbers.top();
				m_stackNumbers.pop();
				m_stackNumbers.push(x * y);
				m_stackOperation.pop();
				break;
			}
		}

		m_rezult = m_stackNumbers.top();
		std::cout << m_rezult << std::endl;
		return m_rezult;
}