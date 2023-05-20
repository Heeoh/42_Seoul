#include "Harl.hpp"

Harl::Harl() {}

void Harl::complain( std::string level )
{
	int	level_type = 0;
	for ( ; level_type<4; level_type++) {
		if (complainLevelStr[level_type] == level) break;
	}

	switch (level_type) {
		case (DEBUG)	: debug();
		case (INFO) 	: info();
		case (WARNING)	: warning();
		case (ERROR)	: error(); break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}	
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon "
			  << "for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
			  << "I really do!" << std::endl
			  << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger!" << std::endl
			  << "If you did, I wouldn’t be asking for more!" << std::endl
			  << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl
			  << "I think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming for years whereas you started working here since last month." << std::endl
			  << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now." << std::endl
			  << std::endl;
}