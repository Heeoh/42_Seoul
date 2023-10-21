#include "iter.hpp"
#include <iostream>
#include <string>

void toLower(char &ch) {
    if ('A' <= ch && ch <= 'Z')
        ch = ch + ('a' - 'A');
    return ;
}

void find42(std::string str) {
    if (str.find("42") != std::string::npos)
        std::cout << str << std::endl;
}

void doubleValue(int &value) {
    value *= 2;
}

template<typename T>
void print(T &value) {
    std::cout << value << " ";
}

template<typename T, typename F>
void iter(T* array, int length, F func) {
    for (int idx = 0; idx < length; idx++)
        func(array[idx]);
}

int main() {
	std::cout << "\033[0;35m" << "[ iter int array ]" << "\033[0m" << std::endl;
    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ::iter(intArr, 10, doubleValue);
    ::iter(intArr, 10, print<int>);
    std::cout << std::endl;

	std::cout << "\033[0;35m" << "[ iter char array ]" << "\033[0m" << std::endl;
    std::string str = "heLlO 42SeouL!";
    char* charArr = &str[0]; // string to char array
    ::iter(charArr, str.length(), toLower);
    ::iter(charArr, str.length(), print<char>);
    std::cout << std::endl;

	std::cout << "\033[0;35m" << "[ iter string array ]" << "\033[0m" << std::endl;
    std::string strs[10] = {"hellooooooooo",
                           "42",
                           "seoul",
                           "4",
                           "2",
                           "found 42",
                           "ooooohhhhhhhohoh",
                           "kkkkkk42kkkk",
                           "wowowowowowowow",
                           "class template 4242"};

    ::iter(strs, 10, find42);
}