#include "PmergeMe.hpp"

// template <typename cota>
// void printCota(const cota& c) {
//     for (size_t i = 0; i < c.size(); i++) {
// 			std::cout << c[i];
// 		if (i < c.size() - 1)
// 			std::cout << " ";
//     }
//     std::cout << std::endl;
// }

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Please input the int numbers" << std::endl;
		std::cerr << "Usage: ./PmergeMe 3 5 9 7 4" << std::endl;
        return 1;
    }

    try {
        std::vector<int> initial_sequence;
        for (int i = 1; i < argc; ++i) {
            char* end;
            long num = std::strtol(argv[i], &end, 10);
            if (*end != '\0' || num < 0 || num > std::numeric_limits<int>::max()) {
                throw std::invalid_argument("Invalid Input");
            }
            initial_sequence.push_back(static_cast<int>(num));
        }

		std::vector<int> vectorToSort = initial_sequence;
		std::deque<int> deqToSort(initial_sequence.begin(), initial_sequence.end());

        std::cout << "Before: ";
		PmergeMe::printVector(initial_sequence);

		auto startList = std::chrono::high_resolution_clock::now();
		PmergeMe::sort(vectorToSort);
		auto endList = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> timeList = endList - startList;

		auto startDeq = std::chrono::high_resolution_clock::now();
		PmergeMe::sort(deqToSort);
		auto endDeq = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> timeDeq = endDeq - startDeq;

		std::cout << "After: ";
		PmergeMe::printVector(vectorToSort);

		std::cout << CYAN << "Time to process a range of " << initial_sequence.size() <<  " elements with std::vector: " << timeList.count() << " us" << RESET << std::endl;
		std::cout << BLUE <<"Time to process a range of " << initial_sequence.size() <<  " elements with std::deque: " << timeDeq.count() << " us" << RESET << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}