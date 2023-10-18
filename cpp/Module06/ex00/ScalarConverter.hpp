#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

typedef enum InputType {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE
} t_input_type;

class ScalarConverter {
private: 
	std::string 	input;
	t_input_type	type;
	char			char_value;
	int				int_value;
	float			float_value;
	double			double_value;

	ScalarConverter();

public:	
	ScalarConverter(std::string _input);
	ScalarConverter(const ScalarConverter & obj);
	ScalarConverter& operator=(const ScalarConverter & obj); 
	~ScalarConverter();

	void execute();

	std::string getInput() const;
	t_input_type getType() const;
	char getChar() const;
	int	getInt() const;
	float getFloat() const;
	double getDouble() const;

private:
	void checkInput();

	void convert();
	void fromChar();
	// void fromInt();
	// void fromFloat();
	// void fromDouble();

	void printOutput();

};

#endif