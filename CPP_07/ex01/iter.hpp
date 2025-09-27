#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* arr, std::size_t len, F func);

template <typename T, typename F>
void iter(T const* arr, std::size_t len, F func);

#include "iter.tpp"