#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::sort(Container& c){
	if (c.size() <= 1)
		return ;
	
	int straggler = -1;
	bool hasStraggler = c.size() % 2 != 0;
	if (hasStraggler){
		straggler = c.back();
		c.pop_back();
	}

	Container S, P;
	for (auto it = c.begin(); it != c.end(); std::advance(it, 2))
	{
		auto first = it;
		auto second = std::next(it);
		if (*first < *second) {
			S.push_back();
			P.push_back();
		}
		else {
			S.push_back();
			P.push_back();
		}

	}

	PmergeMe::sort(S);

	
}