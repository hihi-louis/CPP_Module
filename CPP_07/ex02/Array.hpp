#pragma once
#include <iostream>
#include <stdexcept>
// #include <sstream>
// #include <iomanip>
// #include <string>
// #include <limits>

template <class T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array<T> &operator=(const Array<T> &other);
		~Array();

		T &operator[](const unsigned int index);
		unsigned int size();
	private:
		T* _array;
		unsigned int _size;
};

#include "Array.tpp"