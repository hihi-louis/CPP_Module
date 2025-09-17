#include "Serializer.hpp"

int	main(void) {
	Data d;
	d.id = 1211;
	d.name = "Louis";

	uintptr_t raw = Serializer::serialize(&d);

	std::cout << "Raw value (uintptr_t): " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Deserialized pointer: " << ptr << std::endl;

	std::cout << "Original pointer:     " << &d << std::endl;

	std::cout << "Data.id:   " << ptr->id << std::endl;
    std::cout << "Data.name: " << ptr->name << std::endl;

	return 0;
}
