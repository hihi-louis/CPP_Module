#include "PmergeMe.hpp"

void PmergeMe::printVector(std::vector<int> &c) {
    for (size_t i = 0; i < c.size(); i++) {
			std::cout << c[i];
		if (i < c.size() - 1)
			std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> &c) {
    for (size_t i = 0; i < c.size(); i++) {
			std::cout << c[i];
		if (i < c.size() - 1)
			std::cout << " ";
    }
    std::cout << std::endl;
}