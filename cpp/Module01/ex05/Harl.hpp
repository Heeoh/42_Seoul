#ifndef HARL_H
# define HARL_H

# include <iostream>

enum ComplainLevel {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR
};

const static std::string complainLevelStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

class Harl {
private:
	void (Harl::*funcPtr[4])();
	
public:
	Harl();

	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif