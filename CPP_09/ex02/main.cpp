#include "PmergeMe.hpp" // Bao gồm header của bạn
#include <limits>
#include <cstdlib>

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cerr << "Error: Argument(s) required." << std::endl;
// 		return 1;
// 	}
// 	try
// 	{
// 		PmergeMe pm(argv + 1);

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// }

template <typename Container>
void printContainer(const Container& c, const std::string& prefix) {
    std::cout << prefix;
    for (const auto& val : c) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Lỗi: Vui lòng cung cấp một chuỗi số nguyên dương." << std::endl;
        return 1;
    }

    try {
        // --- Chuẩn bị dữ liệu ---
        std::vector<int> initial_sequence;
        for (int i = 1; i < argc; ++i) {
            char* end;
            long num = std::strtol(argv[i], &end, 10);
            if (*end != '\0' || num < 0 || num > std::numeric_limits<int>::max()) {
                throw std::invalid_argument("Lỗi: Input không hợp lệ.");
            }
            initial_sequence.push_back(static_cast<int>(num));
        }

        printContainer(initial_sequence, "Trước khi sắp xếp:\t");

        // --- Tạo bản sao để kiểm tra ---
        std::vector<int> vec_to_sort = initial_sequence;
        std::vector<int> expected_result = initial_sequence;

        // --- Chạy thuật toán của bạn ---
        PmergeMe::sort(vec_to_sort);
        printContainer(vec_to_sort, "Sau khi sắp xếp:\t");

        // --- Lấy "đáp án" chuẩn bằng std::sort ---
        std::sort(expected_result.begin(), expected_result.end());

        // --- So sánh và đưa ra kết luận ---
        std::cout << "----------------------------------------" << std::endl;
        if (vec_to_sort == expected_result) {
            std::cout << "\033[32m[PASS] ✅ Chuỗi đã được sắp xếp chính xác!\033[0m" << std::endl;
        } else {
            std::cout << "\033[31m[FAIL] ❌ Chuỗi KHÔNG được sắp xếp chính xác!\033[0m" << std::endl;
            printContainer(expected_result, "Kết quả mong đợi:\t");
        }

    } catch (const std::exception& e) {
        std::cerr << "Đã xảy ra lỗi: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}