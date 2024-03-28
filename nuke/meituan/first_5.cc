#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    int num_len = 0;
    std::cin >> num_len;
    if (num_len == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::cout << num_len << ' ' << 1;
    int start = 2, end = num_len - 1;
    while (start < end) {
        std::cout << ' ' << end--;
        std::cout << ' ' << start++;
    }
    if (start == end) {
        std::cout << ' ' << start;
    }
    std::cout << std::endl;
    return 0;
}