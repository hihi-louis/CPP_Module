#!/bin/bash

# --- Cấu hình ---
EXECUTABLE="./RPN"
# Cờ kiểm tra độ chính xác của số thực (sử dụng bc)
# 1 = bật (nghiêm ngặt hơn), 0 = tắt (so sánh chuỗi đơn giản)
STRICT_FLOAT_CHECK=1

# --- Màu sắc cho đầu ra ---
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

# --- Biến đếm ---
passed=0
failed=0
total=0

# --- Kiểm tra xem file thực thi có tồn tại không ---
if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}Lỗi: File thực thi '$EXECUTABLE' không tồn tại. Hãy chạy 'make' trước.${RESET}"
    exit 1
fi
if [ ! -x "$EXECUTABLE" ]; then
    echo -e "${RED}Lỗi: File thực thi '$EXECUTABLE' không thể chạy. Hãy kiểm tra quyền (chmod).${RESET}"
    exit 1
fi

# --- Hàm để chạy một bài kiểm tra ---
# $1: Biểu thức RPN (đặt trong dấu ngoặc kép)
# $2: Kết quả mong đợi (hoặc "ERROR" nếu mong đợi lỗi)
# $3: Mô tả bài kiểm tra
run_test() {
    ((total++))
    expression="$1"
    expected="$2"
    description="$3"

    echo -en "${YELLOW}Kiểm tra:${RESET} $description "

    # Chạy chương trình và bắt cả stdout và stderr
    actual_output=$($EXECUTABLE "$expression" 2>&1)
    exit_code=$?

    # Trường hợp mong đợi một lỗi
    if [ "$expected" == "ERROR" ]; then
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}PASS${RESET}"
            ((passed++))
        else
            echo -e "${RED}FAIL${RESET}"
            echo "   - Mong đợi: Thoát với mã lỗi khác 0"
            echo "   - Kết quả: Thoát với mã lỗi 0 (thành công)"
            echo "   - Đầu ra: $actual_output"
            ((failed++))
        fi
    # Trường hợp mong đợi một kết quả hợp lệ
    else
        if [ $exit_code -eq 0 ]; then
            # So sánh nghiêm ngặt bằng bc
            if [ $STRICT_FLOAT_CHECK -eq 1 ]; then
                comparison=$(echo "($actual_output) == ($expected)" | bc)
                if [ "$comparison" -eq 1 ]; then
                     echo -e "${GREEN}PASS${RESET}"
                     ((passed++))
                else
                    echo -e "${RED}FAIL${RESET}"
                    echo "   - Mong đợi: $expected"
                    echo "   - Kết quả:  $actual_output"
                    ((failed++))
                fi
            # So sánh chuỗi đơn giản
            else
                if [ "$actual_output" == "$expected" ]; then
                    echo -e "${GREEN}PASS${RESET}"
                    ((passed++))
                else
                    echo -e "${RED}FAIL${RESET}"
                    echo "   - Mong đợi: $expected"
                    echo "   - Kết quả:  $actual_output"
                    ((failed++))
                fi
            fi
        else
            echo -e "${RED}FAIL${RESET}"
            echo "   - Mong đợi: $expected"
            echo "   - Kết quả:  Chương trình thoát với mã lỗi $exit_code"
            echo "   - Đầu ra:  $actual_output"
            ((failed++))
        fi
    fi
}

# --- Bắt đầu kiểm tra ---
echo "--- Bắt đầu kiểm tra các biểu thức hợp lệ ---"
run_test "8 9 +" "17" "Phép cộng đơn giản"
run_test "8 9 - 3 *" "-3" "Nhiều toán tử"
run_test "9 5 /" "1.8" "Phép chia số thực"
run_test "10 4 3 + 2 * -" "-4" "Biểu thức ví dụ từ subject"
run_test "5 1 2 + 4 * + 3 -" "14" "Biểu thức phức tạp"
run_test "   8   2   /   " "4" "Xử lý khoảng trắng thừa"
run_test "2.5 3.5 +" "6" "Cộng số thực"
run_test "10 2 3 * /" "1.66666666666666666666" "Phép chia lặp lại (kiểm tra độ chính xác)"


echo ""
echo "--- Bắt đầu kiểm tra xử lý lỗi ---"
run_test "1 0 /" "ERROR" "Chia cho 0"
run_test "1 +" "ERROR" "Không đủ toán hạng (pop trên stack rỗng)"
run_test "1 2 3 +" "ERROR" "Quá nhiều toán hạng (stack cuối cùng > 1)"
run_test "5 a *" "ERROR" "Token không hợp lệ (chữ cái)"
run_test "1 2 ++" "ERROR" "Token không hợp lệ (toán tử kép)"
run_test "" "ERROR" "Input rỗng"
run_test "  " "ERROR" "Input chỉ có khoảng trắng"
run_test "+" "ERROR" "Chỉ có toán tử"
run_test "1 2 3" "ERROR" "Chỉ có số"
run_test "8|9" "ERROR" "Không có khoảng trắng phân tách"

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
