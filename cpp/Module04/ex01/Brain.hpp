#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain();

	std::string	getIdea(int idx) const;
	void		setIdea(std::string str, int idx);
};

#endif