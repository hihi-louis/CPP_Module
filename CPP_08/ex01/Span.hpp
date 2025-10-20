#pragma once

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <exception>

class Span{
	public:
		Span(unsigned int value);
		Span (const Span &other) = default;
		Span& operator=(const Span &other) = default;
		~Span() = default;

		void				addNumber(int value);
		void				addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
	private:
		size_t		_maxSize;
		std::vector<int>	_numList;
};