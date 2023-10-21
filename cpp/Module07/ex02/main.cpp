#include "Array.hpp"
#include <iostream>

int main() {
	int nums[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	std::cout << "\033[0;35m" << "[ test constructor, [], size ]" << "\033[0m" << std::endl; 
	// constructing
	Array<int> array(10);
	for (int i=0; i<10; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	// size
	int arrSize = array.size();
	std::cout << "size: " << arrSize << std::endl;

	// []
	for (int i=0; i<arrSize; i++)
		array[i] = nums[i];
	for (int i=0; i<arrSize; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;


	std::cout << "\033[0;35m" << "[ test copy ]" << "\033[0m" << std::endl; 
	// copy constructing
	Array<int> copied(array);
	for (int i=0; i<arrSize; i++)
		std::cout << copied[i] << " ";
	std::cout << std::endl;	

	// set array 
	for (int i=0; i<arrSize; i++)
		array[i] *= 2;

	// check deep copy
	for (int i=0; i<arrSize; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;	
	for (int i=0; i<arrSize; i++)
		std::cout << copied[i] << " ";
	std::cout << std::endl;	
}