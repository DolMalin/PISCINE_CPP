#include "RPN.hpp"

RPN::RPN(const std::string &str)
{
	_expression = str;
}

RPN::~RPN() {}

RPN::RPN(const RPN & src)
{
	_expression = src._expression;
	_stack = src._stack;
}

RPN & RPN::operator = (const RPN & rhs)
{
	_expression = rhs._expression;
	_stack = rhs._stack;
	return *this;
}

bool RPN::isOperand(const char c)
{
	return c >= '0' && c <= '9';
}

bool RPN::isOperator(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::toInt(const char c)
{
	return static_cast<int>(c - '0');
}

void RPN::processExpression()
{
	int operand_1;
	int operand_2;

	if (_expression.empty())
		throw ErrorException();

	for (std::string::const_iterator it = _expression.begin(); it != _expression.end(); it++)
	{
		if (isOperand(*it))
			_stack.push(toInt(*it));
		else if (isOperator(*it))
		{
			if (_stack.size() < 2)
				throw ErrorException();

			operand_1 = _stack.top();
			_stack.pop();
			operand_2 = _stack.top();
			_stack.pop();

			switch(*it)
			{
				case '+':
					operand_1 = operand_1 + operand_2;
					break;
				case '-':
					operand_1 = operand_2 - operand_1;
					break;
				case '*':
					operand_1 = operand_1 * operand_2;
					break;
				case '/':
					if (operand_1 == 0)
						throw ErrorException();
					operand_1 =  operand_2 / operand_1;
					break;
			}

			_stack.push(operand_1);
		}
		else if (!isspace(*it))
			throw ErrorException();
	}
	if (_stack.size() != 1)
		throw ErrorException();
	std::cout << _stack.top() << std::endl;
}

const char *RPN::ErrorException::what() const throw()
{
	return "Error";
}