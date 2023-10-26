#include "RPN.hpp"
#include <cctype> // isdigit()

std::stack<int> RPN::stk;

RPN::RPN() {}

RPN::RPN(const RPN & obj) {
	*this = obj;
}

RPN & RPN::operator=(const RPN & obj) {
	if (this == &obj)
		return *this;

	this->clearStack();
	this->stk = obj.stk;

	return *this;
}

RPN::~RPN() {}

int RPN::calculate(std::string input) {
	clearStack();

	size_t inputLen = input.length();
	for (unsigned int i=0; i<inputLen; i++) {
		if (input[i] == ' ')
			continue;

		if (std::isdigit(input[i])) {
			stk.push(input[i] - '0');
			continue;
		}

		if (!isValidOperator(input[i]))
			throw RPN::InvalidValueException();
			
		if (stk.size() < 2)
			throw RPN::OperandCountMismatchException();			
		int num2 = stk.top(); stk.pop();
		int num1 = stk.top(); stk.pop();

		switch (input[i]) {
			case '+':
				stk.push(num1 + num2); break;				
			case '-':
				stk.push(num1 - num2); break;
			case '*':
				stk.push(num1 * num2); break;
			case '/':
				stk.push(num1 / num2); break;
			default:
				throw RPN::OperandCountMismatchException();
		}
	}

	if (stk.size() != 1)
		throw RPN::OperandCountMismatchException();
	
	return stk.top();
}

void RPN::clearStack() {
	while ( !stk.empty() )
		stk.pop();
}

bool RPN::isValidOperator(char op) {
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

