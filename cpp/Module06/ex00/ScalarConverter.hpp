#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
private: 
	ScalarConverter();

public:	
	ScalarConverter(const ScalarConverter & obj);
	ScalarConverter& operator=(const ScalarConverter & obj); 
	~ScalarConverter();

	static void convert(std::string input);

private:
	static void fromChar(char input);
	static void toChar(double val);
	static void toInt(double val);
	static void toFloat(double val);
	static void toDouble(double val);
};

#endif