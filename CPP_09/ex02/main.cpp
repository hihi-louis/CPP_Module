#include "PmergeMe.hpp"

// Hàm trợ giúp để in container cho dễ nhìn
template <typename Container>
void printContainer(const Container& c, const std::string& name) {
    std::cout << name << ":\t";
    for (const auto& val : c) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // --- DỮ LIỆU ĐẦU VÀO ĐỂ KIỂM TRA ---
    std::vector<int> c = {5, 2, 9, 0, 7, 4, 8, 1, 3};
    printContainer(c, "Ban dau");
    std::cout << "----------------------------------------" << std::endl;

    // --- SAO CHÉP LOGIC CỦA BẠN VÀO ĐÂY ĐỂ KIỂM TRA ---

    // BƯỚC 1: XỬ LÝ PHẦN TỬ LẺ (STRAGGLER)
    int straggler = -1;
    bool hasStraggler = c.size() % 2 != 0;
    if (hasStraggler) {
        straggler = c.back();
        c.pop_back();
    }
    std::cout << "Phan tu le (straggler): " << straggler << std::endl;
    printContainer(c, "Sau khi tach straggler");

    // BƯỚC 2: TẠO VECTOR CÁC CẶP [NHỎ, LỚN]
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < c.size(); i += 2) {
        if (c[i] > c[i + 1])
            pairs.push_back(std::make_pair(c[i + 1], c[i]));
        else
            pairs.push_back(std::make_pair(c[i], c[i + 1]));
    }
    std::cout << "Cac cap [nho, lon] ban dau:" << std::endl;
    for (const auto& p : pairs) std::cout << "{" << p.first << ", " << p.second << "} ";
    std::cout << "\n----------------------------------------" << std::endl;

    // BƯỚC 3: SẮP XẾP CÁC CẶP DỰA TRÊN PHẦN TỬ LỚN (ĐỆ QUY)
    std::vector<int> main_chain;
    for (const auto& p : pairs) {
        main_chain.push_back(p.second); // **SỬA LỖI**: p.second thay vì p.second()
    }
    printContainer(main_chain, "main_chain (chua sap xep)");
    
    PmergeMe::sort(main_chain); // Giả sử hàm sort hoạt động đúng cho bước này
    printContainer(main_chain, "main_chain (DA sap xep)");

    std::vector<std::pair<int, int>> sorted_pairs;
    for (const auto& sorted_val : main_chain) {
        for (const auto& original_pair : pairs) {
            if (original_pair.second == sorted_val) { // **SỬA LỖI**: .second
                sorted_pairs.push_back(original_pair);
                break;
            }
        }
    }
    std::cout << "Cac cap sau khi dong bo hoa:" << std::endl;
    for (const auto& p : sorted_pairs) std::cout << "{" << p.first << ", " << p.second << "} ";
    std::cout << "\n----------------------------------------" << std::endl;

    // BƯỚC 4: TÁCH THÀNH S (ĐÃ SẮP XẾP) VÀ P (ĐÃ ĐỒNG BỘ)
    std::vector<int> S, P;
    for (const auto& p : sorted_pairs) {
        S.push_back(p.second); // **SỬA LỖI**: .second
        P.push_back(p.first);  // **SỬA LỖI**: .first
    }
    printContainer(S, "Chuoi S (da sap xep)");
    printContainer(P, "Chuoi P (da dong bo)");

    // BƯỚC 5: CHÈN PHẦN TỬ ĐẶC BIỆT P[0]
    if (!P.empty()) {
        S.insert(S.begin(), P[0]);
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "TRANG THAI CUOI CUNG CAN KIEM TRA:" << std::endl;
    printContainer(S, "S cuoi cung");

    // --- KIỂM TRA KẾT QUẢ ---
    std::vector<int> expected_S = {2, 5, 7, 8, 9};
    if (S == expected_S) {
        std::cout << "\n\033[32m[PASS]\033[0m Chuoi S khop voi ket qua mong doi!\n";
    } else {
        std::cout << "\n\033[31m[FAIL]\033[0m Chuoi S KHONG khop!\n";
    }

    return 0;
}