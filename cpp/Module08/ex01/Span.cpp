#include "Span.hpp"
#include <iostream>
#include <limits> // int limit
#include <algorithm> // sort

Span::Span() {};

Span::Span(unsigned int n) {
	this->nums.reserve(n);
	std::cout << "An array has been created. ";
	std::cout << "(capacity: " << this->getSize();
	std::cout << ", count of elements: " << this->count() << ")" << std::endl;
}

Span::Span(const Span & obj) {
	*this = obj;
}

Span& Span::operator=(const Span & obj) {
	if (this == &obj)
		return *this;

	this->nums = obj.nums;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (this->count() >= this->getSize())
		throw std::length_error("The storage is already full.");
	this->nums.push_back(num);
}

void Span::addRange(int from, int to) {
	for (int i = from; i <= to; i++) {
		this->addNumber(i);
	}
}

unsigned int Span::shortestSpan() {
	if (this->count() <= 1)
		throw CannotFindSpanException();
	
	std::sort(this->nums.begin(), this->nums.end());

	int minDiff = std::numeric_limits<int>::max();
	std::vector<int>::const_iterator it = this->nums.begin() + 1;
	for ( ; it != this->nums.end(); it++) {
		minDiff = std::min(minDiff, *it - *(it - 1));
	}
	return minDiff;
}

unsigned int Span::longestSpan() {
	if (this->count() <= 1)
		throw CannotFindSpanException();

	std::sort(this->nums.begin(), this->nums.end());
	return this->nums.back() - this->nums.front();
}

std::vector<int>::iterator  Span::begin() {
	return nums.begin();
}

std::vector<int>::iterator Span::end() {
	return nums.end();
}

unsigned int Span::getSize() {
	return this->nums.capacity();
}

unsigned int Span::count() {
	return this->nums.size();
}
