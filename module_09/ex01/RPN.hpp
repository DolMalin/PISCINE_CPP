#pragma once

# include <stack>
# include <string>
# include <iostream>
# include <cstdlib>

class RPN
{
	private:
		std::string		_expression;
		std::stack<int> _stack;
		RPN();

	public:
		RPN(const std::string &str);
		~RPN();
		RPN(const RPN &src);
		RPN & operator = (const RPN &rhs);

		bool	isOperand(const char c);
		bool	isOperator(const char c);
		int		toInt(const char c);

		void processExpression();

		class ErrorException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};