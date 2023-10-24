#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);							// stack = {5}
	mstack.push(17); 						// stack = {5, 17}
	
	std::cout << mstack.top() << std::endl; // 17

	mstack.pop();							// stack = {5}

	std::cout << mstack.size() << std::endl; // 1

	mstack.push(3);							// stack = {5, 3}
	mstack.push(5);							// stack = {5, 3, 5}
	mstack.push(737);						// stack = {5, 3, 5, 737}
	mstack.push(0);							// stack = {5, 3, 5, 737, 0}

	// print with iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "mutantStack: { ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "}" << std::endl;

	// print reverse with iterator
	MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack.rend();

	std::cout << "mutantStack: { ";
	while (r_it != r_ite)
	{
		std::cout << *r_it << " ";
		++r_it;
	}
	std::cout << "}" << std::endl;

	// std::stack
	std::stack<int> s(mstack);
	std::cout << "stack: { ";
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "}" << std::endl;

	return 0;
}
