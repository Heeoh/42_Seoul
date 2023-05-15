#include <iostream>
#include "Contact.hpp"

void Contact::setContact() {
    std::cout << "First Name: ";
    std::cin >> firstName;
    
    std::cout << "Last Name: ";
    std::cin >> lastName;

    std::cout << "Nickname: ";
    std::cin >> nickname;

    std::cout << "Phone Number: ";
    std::cin >> phoneNumber;

    std::cout << "Darkest Secret: ";
    std::cin >> darkestSecret;
}

std::string Contact::getFirstName() {
    return firstName;
}

std::string Contact::getLastName() {
    return lastName;
}

std::string Contact::getNickname() {
    return nickname;
}

void printContact() {
    std::cout << "======== contact info ========" << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "PhoneNumber: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    std::cout << "==============================" << std::endl;
}