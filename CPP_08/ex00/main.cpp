#include "easyfind.hpp"

int main()
{
{	std::vector<int> intVec = {1, 6, 5, 22, 333, 4654};
	std::vector<int>::iterator iter;
	int value = 3333;

	for (int i : intVec)
		std::cout << i << " ";
	std::cout << std::endl;

	try{
		iter = easyfind(intVec, value);
		std::cout << "Found: " << value << " at index: " << std::distance(intVec.begin(), iter) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}
{
	std::vector<char> charVec = {'a', '&', '*', 'c', 'd', 'e', 'f'};
	std::vector<char>::iterator iter;
	char value = '&';
	for (char i : charVec)
		std::cout << i << " ";
	std::cout << std::endl;
	try {
		iter = easyfind(charVec, static_cast<int>(value));
		std::cout << "Found: " << value << " at index: " << std::distance(charVec.begin(), iter) << std::endl;
	}catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}

// {
// 	std::vector<std::string> stringVec = {"hello", "omggg", "louis", "cute"};
// 	std::vector<std::string>::iterator iter;
// 	std::string value = "omggg";
// 	for (std::string i : stringVec)
// 		std::cout << i << " ";
// 	std::cout << std::endl;
// 	try {
// 		iter = easyfind(stringVec, value);
// 		std::cout << "Found: " << value << " at index: " << std::distance(stringVec.begin(), iter) << std::endl;
// 	}catch(std::runtime_error &e){
// 		std::cout << e.what() << std::endl;
// 	}
// }
	return 0;
}