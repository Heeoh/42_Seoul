#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
	static std::stack<int> stk;

	RPN();
	RPN(const RPN & obj);
	RPN & operator=(const RPN & obj);
	~RPN();

public:
	// exceptions
	class InvalidValueException : public std::runtime_error {
	public:
		InvalidValueException() : std::runtime_error("Invalid value.") {}
	};

	class OperandCountMismatchException : public std::runtime_error {
	public:
		OperandCountMismatchException() : std::runtime_error("Operand count mismatch for the operation.") {}
	};

	// public member function
	static int calculate(std::string input);

private:
	// utils
	static void	clearStack();
	static bool	isValidOperator(char op);

};

#endif