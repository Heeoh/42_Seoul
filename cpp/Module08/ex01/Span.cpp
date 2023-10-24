#include "Span.hpp"
#include <iostream>
#include <limits>
// #include <stdexcept>

Span::Span(): size(0), count(0) {
	
	this->nums = new int[this->size];
};

Span::Span(unsigned int n): size(n), count(0) {
	this->nums = new int[this->size];
}

Span::Span(const Span & obj) {
	this->nums = NULL;
	*this = obj;
}

Span& Span::operator=(const Span & obj) {
	if (this == &obj)
		return *this;
	
	if (this->nums)
		delete[] this->nums;

	this->size = obj.size;
	this->count = obj.count;
	this->nums = new int[this->size];
	for (unsigned int i=0; i<this->count; i++)
		this->nums[i] = obj.nums[i];
	
	return *this;
}

Span::~Span() {
	if (this->nums)
		delete[] this->nums;
	this->nums = NULL;
	this->size = 0;
	this->count = 0;
}

void Span::addNumber(int num) {
	if (this->count >= this->size)
		throw std::bad_alloc();
	this->nums[this->count] = num;
	this->count++;
}

unsigned int Span::shortestSpan() {
	std::sort(this->nums, this->nums + this->count);

	int minDiff = std::numeric_limits<int>::max();
	for (unsigned i = 1; i < this->count; i++) {
		minDiff = std::min(minDiff, this->nums[i] - this->nums[i-1]);
	}
	return minDiff;
}

unsigned int Span::longestSpan() {
	std::sort(this->nums, this->nums + this->count);
	return this->nums[this->count - 1] - this->nums[0];
}
