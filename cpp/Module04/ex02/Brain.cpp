#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor is called" << std::endl;
	for (int i=0; i<100; i++)
		ideas[i] = "idea " + std::to_string(i);
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain copy constructor is called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj) {
	std::cout << "Brain operator= is called" << std::endl;
	if (this == &obj)
		return *this;

	// Brain* newBrain = new Brain();
	for (int i=0; i<100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor is called" << std::endl;
}

std::string Brain::getIdea(int idx) const {
	return ideas[idx];
}

void		Brain::setIdea(std::string str, int idx) {
	ideas[idx] = str;
}