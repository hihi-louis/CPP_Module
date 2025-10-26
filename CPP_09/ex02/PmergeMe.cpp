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

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < c.size(); i+=2)
	{
		if (c[i] > c[i + 1])
			pair.push_back(std::make_pair(c[i + 1], c[i]));
		else
			pair.push_back(std::make_pair(c[i], c[i + 1]));
	}

	Container main_chain;

	for (const auto& p : pairs )
	{
		main_chain.push_back(p.second());
	}

	PmergeMe::sort(main_chain);
	std::vector<std::pair<int, int>> sortedPairs;
	for (const auto& sorted_val : main_chain) {
		for (const auto& original_pair : pairs) {
			if (original_pair == sorted_val)
				sortedPairs.push_back(original_pair);
			break;
		}
	}
	
	Container S, P;
	for (const auto& p : sortedPairs) {
		S.push_back(p.second());
		P.push_back(p.first());
	}

	if (!P.empty()){
		S.insert(S.begin(), P[0]);
	}
	
}