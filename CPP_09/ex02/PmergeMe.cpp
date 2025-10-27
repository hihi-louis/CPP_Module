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
			pairs.push_back(std::make_pair(c[i + 1], c[i]));
		else
			pairs.push_back(std::make_pair(c[i], c[i + 1]));
	}

	Container main_chain;

	for (const auto& p : pairs )
	{
		main_chain.push_back(p.second);
	}

	PmergeMe::sort(main_chain);
	std::vector<std::pair<int, int>> sortedPairs;
	/*
		ex: main_chain[] = [2,5,8,9];
		pairs[] = [{0, 5}, {1 ,2}, {6 ,8}, {7, 9}];
		1st loop's run: 5 == 5 => sortedPairs = [{1, 2}, {0, 5}, ...];
		2nd loop's run: ...
	*/
	for (const auto& sorted_val : main_chain) {
		for (const auto& original_pair : pairs) {
			if (original_pair.second == sorted_val) {
				sortedPairs.push_back(original_pair);
				break;
			}
		}
	}
	
	Container S, P;
	for (const auto& p : sortedPairs) {
		S.push_back(p.second);
		P.push_back(p.first);
	}

	if (!P.empty()){
		S.insert(S.begin(), P[0]);
	}

	// std::cout << S << std::endl;
	//J(n) = J(n-1) + 2*J(n-2)

}