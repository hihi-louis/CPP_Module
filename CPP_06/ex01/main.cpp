#include "Serializer.hpp"

int	main(void) {
	{
		Data d;
		d.id = 42;
		d.name = "Louis";
	
		uintptr_t raw = Serializer::serialize(&d);
	
		std::cout << "Raw value (uintptr_t): " << raw << std::endl;
	
		Data* ptr = Serializer::deserialize(raw);
	
		std::cout << "Deserialized pointer: " << ptr << std::endl;
	
		std::cout << "Original pointer:     " << &d << std::endl;
	
		std::cout << "Data.id:   " << ptr->id << std::endl;
	
		if (d.name == nullptr) {
			std::cout << "nope" << std::endl;
		} else {
			std::cout << "Data.name: " << ptr->name << std::endl;
		}
		// if (ptr->name.empty())
		// 	std::cout << "Data.name: (empty)" << std::endl;
		// else
		// 	std::cout << "Data.name: " << ptr->name << std::endl;
	}
	{
		Data *test = nullptr;
		try {
			test = new(Data)();
			uintptr_t raw = Serializer::serialize(test);
			std::cout << "Raw value (uintptr_t): " << raw << std::endl;
		
			Data* ptr = Serializer::deserialize(raw);
			std::cout << "Deserialized pointer: " << ptr << std::endl;
		
			std::cout << "Original pointer:     " << test << std::endl;
		
			std::cout << "Data.id:   " << ptr->id << std::endl;
			if (test->name == nullptr) {
				std::cout << "nope" << std::endl;
			} else {
				std::cout << "Data.name: " << ptr->name << std::endl;
			}
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete test;
	}

	return 0;
}
