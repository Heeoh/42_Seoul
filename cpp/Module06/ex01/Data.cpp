#include "Data.hpp"

Data::Data() : value(0) {}

Data::Data(int val) : value(val) {}

Data::Data(const Data & obj) {
	*this = obj;
}

Data& Data::operator=(const Data & obj) {
	if (this != &obj)
		this->value = obj.getData();
	return *this;
}

Data::~Data() {}

int Data::getData() const {
	return this->value;
}

void Data::setData(int val) {
	this->value = val;
}