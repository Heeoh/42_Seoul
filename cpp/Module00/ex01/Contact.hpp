#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact() : firstName(""), lastName(""), nickname(""), 
		phoneNumber(""), darkestSecret("") {};

	void 		setContact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	void		printContact();
};

#endif