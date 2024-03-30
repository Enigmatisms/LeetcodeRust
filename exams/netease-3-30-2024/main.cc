#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <array>

int main(int argc, char** argv) {
    int num_emp = 0;
    std::cin >> num_emp;
    std::vector<int> employees(num_emp);
    for (int i = 0; i < num_emp; i++)
        std::cin >> employees[i];
    std::array<int, 4> num_blocks = {0, 0, 0, 0};
    for (int year: employees) {
        int two_year = year - 2, one_year = year - 1;
        num_blocks[0] += (two_year != 1) && (one_year != 1);
        if (year >= 3) {
            num_blocks[1] += (two_year != 3) && (one_year != 3);
        }
        if (year >= 6) {
            num_blocks[2] += (two_year != 6) && (one_year != 6);
        }
        if (year >= 10) {
            num_blocks[3] += (two_year != 10) && (one_year != 10);
        }
    }
    std::cout << num_blocks[0] << ' ' << num_blocks[1] << ' ' << num_blocks[2] << ' ' << num_blocks[3] << std::endl;

    return 0;
}