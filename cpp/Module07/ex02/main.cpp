// 
#include <iostream>
#include "Array.hpp" // ...?

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "\033[0;33m" << "didn't save the same value!!" << "\033[0m" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[0;33m" << e.what() << "\033[0m" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[0;33m" << e.what() << "\033[0m" << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
//*/

/*/
#include "Array.hpp"
#include <iostream>

int main() {
	int nums[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	std::cout << "\033[0;35m" << "[ test constructor, [], size ]" << "\033[0m" << std::endl; 
	// constructing
	Array<int> array(10);

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

//*/