#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data* rawData;
	uintptr_t p;

	rawData = new Data(10);
	p = Serializer::serialize(rawData);

	Data *deserializedData = Serializer::deserialize(p);

	std::cout << rawData << std::endl;
	std::cout << deserializedData << std::endl;
	std::cout << std::endl;

	std::cout << &rawData << std::endl;
	std::cout << &deserializedData << std::endl;
};

