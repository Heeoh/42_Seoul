#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
private:
	std::string name;

public:
	Cure();
	Cure(const Cure& obj);
	Cure& operator= (const Cure& obj);
	~Cure();

	Cure(std::string const & type, std::string _name);

	Cure* 	clone() const;
	void	use(ICharacter& target);

	// std::string getName();
	// void		setName();
};

#endif