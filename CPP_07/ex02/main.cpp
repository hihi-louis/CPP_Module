#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
#define SIZE 42
int main(int, char**)
{
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
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	{
		Array<int> class_array(SIZE);
		int *normal_array = new int[SIZE];

		srand(time(0));	
		for (int i = 0; i < SIZE; i++)
			class_array[i] = normal_array[i] = rand() % 42;
		
		Array<int> class_arr_ca = class_array; //copy assignment
		Array<int> class_arr_cp(class_arr_ca); //copy constructor
		
		for (int i = 0; i < SIZE; i++)
			(normal_array[i] == class_array[i] ? std::cout << class_array[i] : std::cout << "Values are not equal!") << std::endl;

		try {std::cout << class_array[-42];}
		catch(const std::exception& e) {std::cerr << e.what() << std::endl;}
		
		try {std::cout << class_array[42];}
		catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

		for (int i = 0; i < SIZE; i++)
			class_array[i] = rand();
		
		delete [] normal_array;
	}
    return 0;
}