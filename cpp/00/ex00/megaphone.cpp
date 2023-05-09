#include <iostream>

char	*toupper(char *str) {
	for (char *p = str; *p; p++) {
		if ('a' <= *p && *p <= 'z') *p -= 'a' - 'A';
	}
	return (str);
}

int main(int ac, char *av[]) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i=1; i<ac; i++)
			std::cout << toupper(av[i]);
		std::cout << std::endl;
	}
}