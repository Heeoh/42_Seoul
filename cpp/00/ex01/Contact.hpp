#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
public:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

private:
	Contact(int idx=0, std::string fn="", std::string ln="", std::string nn="") 
		: index(idx), first_name(fn), last_name(ln), nickname(nn) {};
};

#endif