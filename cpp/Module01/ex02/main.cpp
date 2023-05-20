#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the string variable:\t" << &str << std::endl;
	std::cout << "memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "value of the string variable: \t" << str << std::endl;
	std::cout << "value pointed to by stringPTR: \t" << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: \t" << stringREF << std::endl;
	std::cout << std::endl;

	// std::cout << "------------------------ update ------------------------" << std::endl << std::endl;
	// std::string str1 = "str1";
	// std::string str2 = "str2";
	// stringPTR = &str1;
	// stringREF = str2;

	// std::cout << "memory address of the string variable:\t" << &str << std::endl;
	// std::cout << "memory address held by stringPTR:\t" << stringPTR << std::endl;
	// std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;
	// std::cout << std::endl;

	// std::cout << "value of the string variable: \t" << str << std::endl;
	// std::cout << "value pointed to by stringPTR: \t" << *stringPTR << std::endl;
	// std::cout << "value pointed to by stringREF: \t" << stringREF << std::endl;
}