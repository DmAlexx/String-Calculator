#include "Calculator.hpp"
#include <cmath>
#include <functional>

void Calculator::clearTempArray(char(&m_input)[20])
{
	for (int i = 0; i < 20; ++i)
	{
		m_input[i] = ' ';
	}
}

void Calculator::fillStacksFirstElement(int i, double& temp, std::string input)
{
	m_stackOperation.push(input[i]);
	m_stackNumbers.push(temp);
	temp = 0;
	clearTempArray(m_input);
}

void Calculator::getExpressionValue()
{
	m_rightExpressionValue = m_stackNumbers.top();
	m_stackNumbers.pop();
	m_leftExpressionValue = m_stackNumbers.top();
	m_stackNumbers.pop();
	m_stackOperation.pop();
}

void Calculator::fillStacks(int i, double temp, std::string input)
{
	m_stackNumbers.push(temp);
	getExpressionValue();
	m_stackOperation.push(input[i]);
	temp = 0;
	clearTempArray(m_input);
}

double Calculator::calc(const std::string& input)
{
	double temp = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		switch (input[i])
		{
		case '+':
		case '-':
			if (m_stackOperation.empty())
			{
				fillStacksFirstElement(i, temp, input);
				break;
			}
			if (m_stackOperation.top() == '-')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue - m_rightExpressionValue);
				break;
			}
			if (m_stackOperation.top() == '+')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue + m_rightExpressionValue);
				break;
			}
			if (m_stackOperation.top() == '/')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue / m_rightExpressionValue);
				break;
			}
			if (m_stackOperation.top() == '*')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue * m_rightExpressionValue);
				break;
			}
			break;
		case '/':
		case '*':
			if (m_stackOperation.empty() || m_stackOperation.top() == '-' || m_stackOperation.top() == '+')
			{
				fillStacksFirstElement(i, temp, input);
				break;
			}
			if (m_stackOperation.top() == '/')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue / m_rightExpressionValue);
				break;
			}
			if (m_stackOperation.top() == '*')
			{
				fillStacks(i, temp, input);
				m_stackNumbers.push(m_leftExpressionValue * m_rightExpressionValue);
				break;
			}
			break;
		default:
			m_input[i] = input[i];
			temp = atof(m_input);
		}
	}

	temp = atof(m_input);
	m_stackNumbers.push(temp);

	while (!m_stackOperation.empty())
	{
		switch (m_stackOperation.top())
		{
		case '+':
			getExpressionValue();
			m_stackNumbers.push(m_leftExpressionValue + m_rightExpressionValue);
			break;
		case '-':
			getExpressionValue();
			if (!m_stackOperation.empty() && m_stackOperation.top() == '-')
			{
				m_stackNumbers.push(m_leftExpressionValue + m_rightExpressionValue);
			}
			else
			{
				m_stackNumbers.push(m_leftExpressionValue - m_rightExpressionValue);
			}
			break;
		case '/':
			getExpressionValue();
			m_stackNumbers.push(m_leftExpressionValue / m_rightExpressionValue);
			break;
		case '*':
			getExpressionValue();
			m_stackNumbers.push(m_leftExpressionValue * m_rightExpressionValue);
			break;
		}
	}
	return m_stackNumbers.top();
}