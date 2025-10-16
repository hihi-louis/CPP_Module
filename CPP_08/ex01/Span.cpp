#include "Span.hpp"

Span::Span(unsigned int value): _maxSize(value) {
	_numList.reserve(value);
}

void Span::addNumber(int value)
{
	if (_numList.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numList.push_back(value);
}


void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	size_t range = std::distance(start, end);
	if (range + _numList.size() > _maxSize)
		throw std::runtime_error("Span is full");
	_numList.insert(_numList.end(), start, end);
}

unsigned int Span::shortestSpan() const
{
	if (_numList.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	
	std::vector<int> sortedList(_numList);
	std::sort(sortedList.begin(), sortedList.end());
	unsigned int minSpan = static_cast<unsigned int>(sortedList[1] - sortedList[0]);
	for (size_t i = 1; i < sortedList.size() - 1; i++)
	{
		unsigned int diff = static_cast<unsigned int>(std::abs(sortedList[i + 1] - sortedList[i]));
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numList.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	unsigned int maxSpan = /*static_cast<unsigned int>*/(*std::max_element(_numList.begin(), _numList.end()) - *std::min_element(_numList.begin(), _numList.end()));
	return maxSpan;
}