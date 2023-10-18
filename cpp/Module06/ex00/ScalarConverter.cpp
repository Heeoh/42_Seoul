#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter() : input(0) {}

ScalarConverter::ScalarConverter(std::string _input) : input(_input) {
	this->execute();
}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) {
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter & obj) {
	if (this != &obj) {
		this->input = obj.getInput();
		this->type = obj.getType();
		this->char_value = obj.getChar();
		this->int_value = obj.getInt();
		this->float_value = obj.getFloat();
		this->double_value = obj.getDouble();
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::execute() {
	checkInput();
	convert();
	printOutput();
}

void ScalarConverter::checkInput() {
	this->char_value = this->input.at(0);
}

void ScalarConverter::printOutput() {
	std::stringstream ss;
	ss.setf(std::ios::fixed);
	ss.precision(1);

	std::cout << "char: " << this->char_value << std::endl;
	std::cout << "int: " << this->int_value << std::endl;

	ss << this->float_value;
	std::cout << "float: " << ss.str() << "f" << std::endl;
	ss.str("");

	ss << this->double_value;
	std::cout << "double: " <<  ss.str()  << std::endl;
	ss.str("");
}

// --------------------------- converter ----------------------------- //

void ScalarConverter::convert() {
	switch (this->type) {
		case CHAR:
			this->fromChar(); break;
		// case INT:
		// 	this->fromInt(); break;
		// case FLOAT:
		// 	this->fromFloat(); break;
		// case DOUBLE:
		// 	this->fromDouble();
		default:
			return;
			// exception
	}
}

void ScalarConverter::fromChar() {
	this->int_value = static_cast<int>(this->char_value);
	this->float_value = static_cast<float>(this->char_value);
	this->double_value = static_cast<double>(this->char_value);
}

// void ScalarConverter::fromInt() {

// }

// void ScalarConverter::fromFloat() {

// }

// void ScalarConverter::fromDouble() {

// }

// ----------------------------- getter ------------------------------ //

std::string ScalarConverter::getInput() const {
	return this->input;
}

t_input_type ScalarConverter::getType() const {
	return this->type;
}

char ScalarConverter::getChar() const {
	return this->char_value;
}

int	ScalarConverter::getInt() const {
	return this->int_value;
}

float ScalarConverter::getFloat() const {
	return this->float_value;
}

double ScalarConverter::getDouble() const {
	return this->double_value;
}

