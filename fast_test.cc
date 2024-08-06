#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>


const std::array<int, 40> FIBO = {
    1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 
    377, 610, 987, 1597, 2584, 4181, 6765, 10946, 
    17711, 28657, 46368, 75025, 121393, 196418, 
    317811, 514229, 832040, 1346269, 2178309, 3524578, 
    5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155
};

int main(int argc, char** argv) {
    std::vector<int> tests = {0, 1, 2, 3, 4, 7, 9, 11, 12, 13, 20, 40, 60, 1000, 5000};
    for (int k: tests) {
        int index = std::upper_bound(FIBO.begin(), FIBO.end(), k) - FIBO.begin();
        printf("LB for %d is tests[%d] = %d\n", k, index, tests[index]);
    }

    return 0;
}