#pragma once
#include "Array.hpp"

template <class T> 
Array<T>::Array():
	_array(nullptr), _size(0) {};

template <class T> 
Array<T>::Array(unsigned int n):
	_array(new T[n]()), _size(n) {};

template <class T> 
Array<T>::Array(const Array<T> &other):
	_array(new T[other._size]()), _size(other._size) {
		for (unsigned int i = 0; i < _size; i++)
			 _array[i] = other._array[i];
	};

template <class T> 
Array<T>::~Array() {
		delete[] _array;
};

template <class T> 
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
			delete[] _array;
			this->_size = other._size;
			this->_array = (this->_size ? new T[other._size]() : nullptr);
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
	}
	return *this;
};

template <class T> 
T &Array<T>::operator[](const unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return this->_array[index];
};

template <class T> 
unsigned int Array<T>::size() {
	return this->_size;
};
