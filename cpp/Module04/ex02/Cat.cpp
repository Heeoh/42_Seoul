#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat defalut constructor is called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj) : AAnimal() {
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat assignment operator is called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
		this->brain = new Brain(*(obj.getBrain()));
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const {
	std::cout << "Cat says meaw!" << std::endl;
}

Brain*	Cat::getBrain() const {
	return this->brain;
}