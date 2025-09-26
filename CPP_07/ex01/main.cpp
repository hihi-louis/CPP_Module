#include "iter.hpp"

/*Print all the data types*/
struct Print {
	template <typename T>
	void operator()(T const& x) const {
		std::cout << x << "\n";
	}
};

void inc(int &x) { x++; }

void upC(char &c) {
	if (c >= 'a' && c <= 'z')
		c = static_cast<char>(c - 'a' + 'A');
}

/*Multiple with 2 (usable for number and string)*/
template <typename T>
void twice(T &x) {x += x;}





