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
	// for (auto it = c.begin(); it != c.end(); std::advance(it, 2))
	// {
	// 	auto first = it;
	// 	auto second = std::next(it);
	// 	if (*first > *second)
	// 		pairs.push_back(std::make_pair(*second, *first));
	// 	else
	// 		pairs.push_back(std::make_pair(*first, *second));
	// }
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
	std::vector<bool> used(pairs.size(), false);
	/*
		ex: main_chain[] = [2,5,8,9];
		pairs[] = [{0, 5}, {1 ,2}, {6 ,8}, {7, 9}];
		1st loop's run: 5 == 5 => sortedPairs = [{1, 2}, {0, 5}, ...];
		2nd loop's run: ...
	*/
	for (const auto& sorted_val : main_chain) {
		for (size_t i = 0; i < pairs.size(); i++) {
			if (!used[i] && pairs[i].second == sorted_val) {
				sortedPairs.push_back(pairs[i]);
				used[i] = true;
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

	//0, 1, 1, 3, 5, 11,… (sequence A001045 in the OEIS)
	//J(n) = J(n-1) + 2*J(n-2)
	std::vector<size_t> jacobsIndices;
	size_t currentJacob = 3;
	size_t lastJacob = 1;
	while (lastJacob < P.size())
	{
		if (currentJacob - 1 < P.size()) {
			jacobsIndices.push_back(currentJacob -1);
		}

		for (size_t i = currentJacob - 1; i > lastJacob; --i)
		{
			if (i - 1 < P.size())
				jacobsIndices.push_back(i - 1);
			// if (i == 0) break;
		}

		size_t temp = currentJacob;
		currentJacob = currentJacob + 2 * lastJacob;
		lastJacob = temp; 
	}

	for (size_t p_index : jacobsIndices)
	{
		int valToInsert = P[p_index];
		int partnerS = sortedPairs[p_index].second;
		auto endSearchIt = std::lower_bound(S.begin(), S.end(), partnerS);

		auto insertPos = std::lower_bound(S.begin(), endSearchIt, valToInsert);

		S.insert(insertPos, valToInsert);
	}

	if (hasStraggler)
	{
		auto insertPos = std::lower_bound(S.begin(), S.end(), straggler);
		S.insert(insertPos, straggler);
	}

	c = std::move(S);
}