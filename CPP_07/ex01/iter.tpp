#include "iter.hpp"

template <typename T, typename F>
void iter(T* arr, std::size_t len, F func)
{
	if (!arr)
		return;
	for(std::size_t i = 0; i < len; i++)
		func(arr[i]);
	
}

template <typename T, typename F>
void iter(T const* arr, std::size_t len, F func)
{
	if (!arr)
		return;
	for(std::size_t i = 0; i < len; i++)
		func(arr[i]);
	
}