#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <iterator>
#include <utility>
#include <exception>
#include <limits>
#include <list>
#include <chrono>
#include "sys.hpp"

class PmergeMe{
	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		static void printVector(std::vector<int> &c);
		static void printDeque(std::deque<int> &c);

		template <typename Container>
		static void sort(Container& c);
};

#include "PmergeMe.tpp"