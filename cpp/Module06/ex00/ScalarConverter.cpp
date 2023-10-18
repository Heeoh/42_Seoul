#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : input(0) {}

ScalarConverter::ScalarConverter(std::string _input) : input(_input) {}

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


void ScalarConverter::execute(std::string _input) {
	checkInput();
	convert();
	printOutput();
}

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

