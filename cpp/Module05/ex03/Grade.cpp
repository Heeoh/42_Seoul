#include "Grade.hpp"

int Grade::highestGrade = 1;
int Grade::lowestGrade = 150;

Grade::Grade() : grade(Grade::lowestGrade) {}

Grade::Grade(const Grade& obj) {
    *this = obj;
}

Grade& Grade::operator= (const Grade& obj) {
    if (this != &obj) 
        this->grade = obj.getGrade();
    return *this;
}

Grade::~Grade() {}

Grade::Grade(int grade) {
	this->grade = grade;
}

Grade& Grade::operator++(void) {
	this->grade++;
	return (*this);
}

Grade& Grade::operator--(void) {
	this->grade--;
	return (*this);
}

Grade Grade::operator++(int) {
	const Grade temp(*this);
	this->grade++;
	return (temp);
}

Grade Grade::operator--(int) {
	const Grade temp(*this);
	this->grade--;
	return (temp);
}

int Grade::getGrade() const {
    return this->grade;
}

bool Grade::isTooHigh() const {
    return this->grade < this->highestGrade;
}

bool Grade::isTooLow() const {
    return this->grade > this->lowestGrade;
}
