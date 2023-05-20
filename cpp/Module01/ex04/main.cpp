#include <iostream>
#include <string>
#include <fstream>

int print_err_n_return (std::string err_msg)
{
	std::cout << err_msg << std::endl;
	return (1);
}

int main(int ac, char *av[])
{
	if (ac != 4)
		return print_err_n_return("Error: wrong arguments");

	std::string filename = av[1], s1 = av[2], s2 = av[3];

	std::ifstream org_file(filename);
	std::ofstream replace_file(filename + ".replace");
	
	if (!org_file.is_open())
		return print_err_n_return("Error: invlalid filename");
	if (!replace_file.is_open())
		return print_err_n_return("Error: replace file is not open");

	std::string buf = "";
	while (std::getline(org_file, buf)) {
		std::size_t substr_sp = 0;
		std::size_t pos_of_s1 = buf.find(s1, substr_sp);
		while (pos_of_s1 != std::string::npos) {
			replace_file << buf.substr(substr_sp, pos_of_s1 - substr_sp) << s2;
			substr_sp = pos_of_s1 + s1.length();
			pos_of_s1 = buf.find(s1, substr_sp);
		}
		replace_file << buf.substr(substr_sp) << std::endl;
	}

	org_file.close();
	replace_file.close();
}