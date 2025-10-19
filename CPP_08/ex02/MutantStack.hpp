#pragma once

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>{
	public:
		MutantStack() = default;
		~MutantStack() = default;
		MutantStack& operator=(const MutantStack& other) = default;
		MutantStack(const MutantStack& other) = default;

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;


		//auto = typename Container::iterator
		auto begin() {return this->c.begin();}
		auto end() {return this->c.end();}
		auto rbegin() {return this->c.rbegin();}
		auto rend() {return this->c.rend();}
		
		auto begin() const {return this->c.cbegin();}
		auto end() const {return this->c.cend();}
		auto rbegin() const {return this->c.crbegin();}
		auto rend() const {return this->c.crend();}
};