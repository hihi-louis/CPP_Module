#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <iterator>
#include <utility>

class PmergeMe{
	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		template <typename Container>
		static void sort(Container& c);
};