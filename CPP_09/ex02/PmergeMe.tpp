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
	for (auto it = c.begin(); it != c.end(); std::advance(it, 2))
	{
		auto first = it;
		auto second = std::next(it);
		if (*first > *second)
			pairs.push_back(std::make_pair(*second, *first));
		else
			pairs.push_back(std::make_pair(*first, *second));
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

// template <typename Container>
// void PmergeMe::sort(Container& c) {
//     // --- KHỐI CODE DEBUG: THEO DÕI CẤP ĐỘ ĐỆ QUY ---
//     static int depth = 0;
//     std::string indent(depth * 4, ' ');
//     std::cout << "\n" << indent << "--- BẮT ĐẦU SORT [Cấp " << depth << "] ---" << std::endl;
//     std::cout << indent << "Input size: " << c.size() << std::endl;
//     // --- KẾT THÚC KHỐI CODE DEBUG ---

//     if (c.size() <= 1) {
//         std::cout << indent << "--> Gặp trường hợp cơ bản, quay lại." << std::endl;
//         return;
//     }

//     // ========================================================================
//     // BƯỚC 1: XỬ LÝ PHẦN TỬ LẺ (STRAGGLER)
//     // ========================================================================
//     int straggler = -1;
//     bool hasStraggler = c.size() % 2 != 0;
//     if (hasStraggler) {
//         straggler = c.back();
//         c.pop_back();
//         std::cout << indent << "Đã tách phần tử lẻ (straggler): " << straggler << std::endl;
//     }

//     // ========================================================================
//     // BƯỚC 2: TẠO VECTOR CÁC CẶP [NHỎ, LỚN]
//     // ========================================================================
//     std::vector<std::pair<int, int>> pairs;
//     for (auto it = c.begin(); it != c.end(); std::advance(it, 2)) {
//         auto first = it;
//         auto second = std::next(it);
//         if (*first > *second)
//             pairs.push_back(std::make_pair(*second, *first));
//         else
//             pairs.push_back(std::make_pair(*first, *second));
//     }
//     std::cout << indent << "Các cặp [nhỏ, lớn] đã tạo: ";
//     for (const auto& p : pairs) std::cout << "{" << p.first << "," << p.second << "} ";
//     std::cout << std::endl;

//     // ========================================================================
//     // BƯỚC 3: SẮP XẾP CÁC CẶP DỰA TRÊN PHẦN TỬ LỚN (ĐỆ QUY)
//     // ========================================================================
//     Container main_chain;
//     for (const auto& p : pairs) {
//         main_chain.push_back(p.second);
//     }
//     std::cout << indent << "main_chain (trước khi đệ quy): ";
//     for(const auto& val : main_chain) std::cout << val << " ";
//     std::cout << std::endl;

//     depth++; // Tăng độ sâu trước khi gọi đệ quy
//     PmergeMe::sort(main_chain);
//     depth--; // Giảm độ sâu sau khi gọi đệ quy xong

//     std::cout << indent << "main_chain (SAU KHI đệ quy):   ";
//     for(const auto& val : main_chain) std::cout << val << " ";
//     std::cout << std::endl;

//     std::vector<std::pair<int, int>> sortedPairs;
//     std::vector<bool> used(pairs.size(), false);
//     for (const auto& sorted_val : main_chain) {
//         for (size_t i = 0; i < pairs.size(); i++) {
//             if (!used[i] && pairs[i].second == sorted_val) {
//                 sortedPairs.push_back(pairs[i]);
//                 used[i] = true;
//                 break;
//             }
//         }
//     }
//     std::cout << indent << "Các cặp sau khi đồng bộ hóa: ";
//     for (const auto& p : sortedPairs) std::cout << "{" << p.first << "," << p.second << "} ";
//     std::cout << std::endl;


//     // ========================================================================
//     // BƯỚC 4: TÁCH THÀNH CHUỖI S (ĐÃ SẮP XẾP) VÀ P (ĐÃ ĐỒNG BỘ)
//     // ========================================================================
//     Container S, P;

//     for (const auto& p : sortedPairs) {
//         S.push_back(p.second);
//         P.push_back(p.first);
//     }
// 	// *** THÊM KHỐI CODE KIỂM TRA NÀY VÀO ***
// 	std::cout << indent << "Chuỗi P cuối cùng trước khi chèn: ";
// 	for(const auto& val : P) std::cout << val << " ";
// 	std::cout << std::endl;
// 	// *** KẾT THÚC KHỐI KIỂM TRA ***

//     std::cout << indent << "Chuỗi S (đã tách ra): ";
//     for(const auto& val : S) std::cout << val << " ";
//     std::cout << std::endl;
//     std::cout << indent << "Chuỗi P (đã tách ra): ";
//     for(const auto& val : P) std::cout << val << " ";
//     std::cout << std::endl;


//     // ========================================================================
//     // BƯỚC 5: CHÈN THÔNG MINH CÁC PHẦN TỬ CỦA P VÀO S
//     // ========================================================================
//     if (!P.empty()) {
//         S.insert(S.begin(), P[0]);
//         std::cout << indent << "S sau khi chèn P[0]: ";
//         for(const auto& val : S) std::cout << val << " ";
//         std::cout << std::endl;
//     }

//     std::vector<size_t> jacobsIndices;
//     size_t currentJacob = 3, lastJacob = 1;
//     while (lastJacob < P.size()) {
//         if (currentJacob - 1 < P.size())
//             jacobsIndices.push_back(currentJacob - 1);
//         for (size_t i = currentJacob - 1; i > lastJacob; --i) {
//             if (i - 1 < P.size())
//                 jacobsIndices.push_back(i - 1);
//         }
//         size_t temp = currentJacob;
//         currentJacob = currentJacob + 2 * lastJacob;
//         lastJacob = temp;
//     }
//     std::cout << indent << "Thứ tự chèn Jacobsthal (chỉ số của P): ";
//     for(const auto& val : jacobsIndices) std::cout << val << " ";
//     std::cout << std::endl;


//     for (size_t p_index : jacobsIndices) {
//         int valToInsert = P[p_index];
//         std::cout << indent << "--> Chèn P[" << p_index << "] = " << valToInsert << std::endl;
        
//         int partnerS = sortedPairs[p_index].second;
//         auto endSearchIt = std::lower_bound(S.begin(), S.end(), partnerS);
        
//         std::cout << indent << "    Tìm kiếm trong S đến trước phần tử: " << partnerS << std::endl;

//         auto insertPos = std::lower_bound(S.begin(), endSearchIt, valToInsert);
//         S.insert(insertPos, valToInsert);

//         std::cout << indent << "    S sau khi chèn: ";
//         for(const auto& val : S) std::cout << val << " ";
//         std::cout << std::endl;
//     }

//     // ========================================================================
//     // BƯỚC 6 & 7: CHÈN STRAGGLER VÀ CẬP NHẬT
//     // ========================================================================
//     if (hasStraggler) {
//         std::cout << indent << "Chèn phần tử lẻ (straggler): " << straggler << std::endl;
//         auto insertPos = std::lower_bound(S.begin(), S.end(), straggler);
//         S.insert(insertPos, straggler);
//     }
    
//     c = std::move(S);

//     std::cout << indent << "--- KẾT THÚC SORT [Cấp " << depth << "] ---" << std::endl;
// }