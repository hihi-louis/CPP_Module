#!/bin/bash

# --- Cấu hình ---
EXECUTABLE="./PmergeMe"

# --- Màu sắc cho đầu ra ---
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"

# --- Biến đếm ---
passed=0
failed=0
total=0

# --- Kiểm tra sự tồn tại của file thực thi ---
if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}Lỗi: File thực thi '$EXECUTABLE' không tồn tại. Hãy chạy 'make' trước.${RESET}"
    exit 1
fi

# --- Hàm để chạy một bài kiểm tra ---
# $1: Mô tả bài kiểm tra
# $2: "PASS" hoặc "ERROR" (kết quả mong đợi)
# $3...: Các đối số cho chương trình
run_test() {
    ((total++))
    local description="$1"
    local expected_outcome="$2"
    shift 2
    local args="$@"

    echo -en "${YELLOW}Kiểm tra:${RESET} $description "

    # Chạy chương trình và bắt stdout, stderr, và mã thoát
    output=$( "$EXECUTABLE" $args 2> >(stderr_output=$(cat); cat >&2) )
    exit_code=$?

    # Trường hợp mong đợi lỗi
    if [ "$expected_outcome" == "ERROR" ]; then
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}PASS${RESET}"
            ((passed++))
        else
            echo -e "${RED}FAIL${RESET}"
            echo "   - Mong đợi: Thoát với mã lỗi khác 0"
            echo "   - Kết quả:  Thoát với mã lỗi 0"
            ((failed++))
        fi
        return
    fi

    # Trường hợp mong đợi thành công
    if [ $exit_code -ne 0 ]; then
        echo -e "${RED}FAIL${RESET}"
        echo "   - Mong đợi: Thoát với mã lỗi 0"
        echo "   - Kết quả:  Thoát với mã lỗi $exit_code"
        echo "   - Stderr:   $stderr_output"
        ((failed++))
        return
    fi

    # *** SỬA LỖI: Lấy TOÀN BỘ dòng kết quả, không cắt bớt ***
    # Trích xuất dòng "After:", xóa tiền tố và các khoảng trắng thừa ở cuối
    actual_sorted_line=$(echo "$output" | grep "After:" | sed 's/After:[[:space:]]*//' | sed 's/ *$//')

    # Tạo kết quả đúng bằng lệnh sort, xóa khoảng trắng thừa ở cuối
    expected_sorted_line=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ *$//')
    
    # So sánh chuỗi kết quả đầy đủ
    if [ "$actual_sorted_line" == "$expected_sorted_line" ]; then
        echo -e "${GREEN}PASS${RESET}"
        ((passed++))
    else
        echo -e "${RED}FAIL${RESET}"
        echo "   - Mong đợi: $expected_sorted_line"
        echo "   - Kết quả:  $actual_sorted_line"
        ((failed++))
    fi
}

# --- Bắt đầu kiểm tra ---
echo -e "${BLUE}--- Kiểm tra các trường hợp cơ bản & đặc biệt ---${RESET}"
run_test "Dãy số nhỏ, chưa sắp xếp" "PASS" 3 5 9 7 4
run_test "Dãy số đã sắp xếp" "PASS" 1 2 3 4 5 6 7 8
run_test "Dãy số sắp xếp ngược (trường hợp xấu)" "PASS" 10 9 8 7 6 5 4 3 2 1
run_test "Số lẻ các phần tử (test straggler)" "PASS" 6 5 3 1 8 7 2
run_test "Chỉ có một phần tử" "PASS" 42
run_test "Chỉ có hai phần tử (chưa sắp xếp)" "PASS" 2 1
run_tst "Chỉ có hai phần tử (đã sắp xếp)" "PASS" 1 2
run_test "Dãy số có số trùng lặp" "PASS" 5 8 2 5 9 2 8 5 7 7
run_test "Tất cả các phần tử giống nhau" "PASS" 7 7 7 7 7
run_test "Dãy số dài hơn 5" "PASS" 9 8 7 6 5 4 3 2 1

echo -e "\n${BLUE}--- Kiểm tra xử lý lỗi input ---${RESET}"
run_test "Không có đối số" "ERROR"
run_test "Có số âm" "ERROR" 5 8 -2 9
run_test "Có ký tự không phải số" "ERROR" 5 8 a 9
run_test "Số trùng lặp với ký tự" "ERROR" 5 8 8a 9
run_test "Số thập phân" "ERROR" 5 8 3.14 9
run_test "Số lớn hơn INT_MAX (2147483647)" "ERROR" 5 9 2147483648

echo -e "\n${BLUE}--- Kiểm tra với số lượng lớn (3000 số ngẫu nhiên) ---${RESET}"
# Tạo một chuỗi 3000 số ngẫu nhiên từ 0 đến 99999
large_input=$(shuf -i 0-99999 -n 3000 | tr '\n' ' ')
run_test "3000 số ngẫu nhiên" "PASS" $large_input

# --- Tổng kết ---
echo ""
echo "--- Tổng kết ---"
echo "Tổng số bài kiểm tra: $total"
echo -e "Thành công: ${GREEN}$passed${RESET}"
echo -e "Thất bại:  ${RED}$failed${RESET}"
echo ""

if [ $failed -eq 0 ]; then
    echo -e "${GREEN}Tất cả các bài kiểm tra đã thành công! ✨${RESET}"
    exit 0
else
    echo -e "${RED}Có lỗi xảy ra. Hãy kiểm tra lại code của bạn.${RESET}"
    exit 1
fi