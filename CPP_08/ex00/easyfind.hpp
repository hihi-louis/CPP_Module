#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int value);

// template <typename T, typename U>
// typename T::iterator easyfind(T &haystack, U needle) {
//     typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
//     if (it != haystack.end()) {
//         return (it);
//     } else {
//         throw std::runtime_error("Not found");
//     }
// }

#include "easyfind.tpp"