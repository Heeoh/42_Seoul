#include "ScalarConverter.hpp"
#include <cstdlib> // strtod()
#include <iomanip> // setprecision(), showpos()
#include <limits> // numeric_limits<T>::digits10
#include <cmath> // isnana(), isinf()

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) {
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter & obj) {
	if (this != &obj)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input) {
	if (input.length() == 1 && !std::isdigit(input[0])) {
		fromChar(input[0]);
		return ;
	}

	double val = 0.0;
	char *endPtr = NULL;

	val = std::strtod(input.c_str(), &endPtr);

	if (endPtr == NULL)
		throw std::invalid_argument("Invalid Input");
	else if (*endPtr != '\0' && *endPtr != 'f' && *endPtr != 'F')
		throw std::invalid_argument("Invalid character found during conversion.");
	else if ((*endPtr == 'f' || *endPtr == 'F')
			&& endPtr - input.c_str() != (long)(input.length() - 1))
		throw std::invalid_argument("Invalid character found during conversion.");

	toChar(val);
	toInt(val);
	toFloat(val);
	toDouble(val);
}

void ScalarConverter::fromChar(char input) {
	std::cout << "char: " << "'" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

void ScalarConverter::toChar(double val) {
	std::cout << "char: ";
  	if (std::isnan(val) || std::isinf(val))
    	std::cout << "impossible" << std::endl;
	else if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(val)))
    	std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::toInt(double val) {
	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible" << std::endl;
	else if (val < -2147483648 || val > 2147483647)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;
}

void ScalarConverter::toFloat(double val) {
	std::cout << "float: ";
	float floatValue = static_cast<float>(val);

	if (std::isnan(val))
		std::cout << std::showpos << floatValue << "f" << std::endl;
	else if (std::isinf(val))
		std::cout << std::showpos << floatValue << "f" << std::endl;
	else if (floatValue == static_cast<int64_t>(static_cast<float>(val)))
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << floatValue << "f" << std::endl;
}

void ScalarConverter::toDouble(double val) {
	std::cout << "double: ";

	if (std::isnan(val) || std::isinf(val))
		std::cout << val << std::endl;
	else if (val == static_cast<int64_t>(val))
		std::cout << val << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << val << std::endl;
}
