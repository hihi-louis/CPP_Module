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


class Test{
	private:
		std::string _name;
	public:
		Test(std::string name = "NoName") : _name(name) {}
		~Test() {}
		Test(const Test &other) = delete;
		void operator=(const Test &other) = delete;

		std::string getName() const {return this->_name;}
		void message() const {std::cout << this->_name << " say: Hi there, welcome to my world\n";};
};
std::ostream& operator<<(std::ostream& os, Test const &t){
	return os << "I am " << t.getName() << "\n";
}

void getMsg(Test &t) {t.message();}

int main() {
    {
        std::cout << "== int test ==\n";
        int a[5] = {1,2,3,4,5};
        iter(a, std::size(a), inc);    
        iter(a, std::size(a), Print());
    }

    {
        std::cout << "== char test ==\n";
        char s[] = "hello";
        iter(s, std::size(s), upC);  
        iter(s, std::size(s), Print()); 
        std::cout << "as string: " << s << "\n";
    }

    {
        std::cout << "== string test ==\n";
        std::string arr[3] = {"ab", "cd", "ef"};
        iter(arr, std::size(arr), twice<std::string>); // "ab" -> "abab"
        iter(arr, std::size(arr), Print());
    }

	{
		std::cout << "== float test ==\n";
		float f[3] = {123.123f, 456.456f, 789.789f};
		iter(f, std::size(f), twice<float>);
		iter(f, std::size(f), Print());
	}

	{
		std::cout << "== double test ==\n";
		double d[2] = {4.2, 7.7};
		iter(d, std::size(d), Print());
	}

	{
		std::cout << "== Test class ==\n";
		Test arr[3] = { Test("Louis"), Test("Alice"), Test("Cardi B")};

		iter(arr, std::size(arr), Print());

		iter(arr, std::size(arr), getMsg);
	}

	{
		std::cout << "== const array test ==\n";
		const int k[4] = {10,20,30,40};
		iter(k, std::size(k), Print());
	}

	{
		std::cout << "== lambda test ==\n";
		int nums[3] = {3, 6, 9};
		iter(nums, std::size(nums), [](int &x){ x *= 10; });
		iter(nums, std::size(nums), [](int const &x){ std::cout << x << "\n"; });
	}

	{
		std::cout << "== single element test ==\n";
		int one[1] = {42};
		iter(one, std::size(one), Print());

		std::cout << "== empty test ==\n";
		int empty[1];
		iter(empty, std::size(empty) * 0 , Print());
	}

	return 0;
}