#include "MutantStack.hpp"

int main()
{
	{	
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "-----" << std::endl;
		MutantStack<std::string> mstack;
		mstack.push("Louis");
		mstack.push("So cute");
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push("aha");
		mstack.push("mew mew");
		mstack.push("omgggg");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "-----" << std::endl;
		MutantStack<int> mstack;
	    mstack.push(5);
    	mstack.push(3);
    	mstack.push(17);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		if (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
	}
	return 0;
}