#ifndef CONTACT_HPP
# define CONTACT_HPP

// # include <string>

typedef enum e_contact_field {
	FIRST_NAME = 0,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
}	t_contact_field;

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact(std::string fn="", std::string ln="", std::string nn="", 
			std::string pn="", std::string ds="") 
		: firstName(fn), lastName(ln), nickname(nn), 
		phoneNumber(pn), darkestSecret(ds) {};

	void setContact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	void printContact();
};

#endif