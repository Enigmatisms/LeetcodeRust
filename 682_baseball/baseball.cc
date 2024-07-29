#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 极度简单，毕竟是简单题
 * runtime: 100.00%
 * memory:  17.22%
 */
class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> operands;
        operands.reserve(operations.size() >> 1);
        for (std::string v: operations) {
            if (v == "C") {
                operands.pop_back();
            } else if (v == "D") {
                operands.emplace_back(operands.back() * 2);
            } else if (v == "+") {
                operands.emplace_back(*(operands.end() - 1) + *(operands.end() - 2));
            } else {
                operands.emplace_back(atoi(v.c_str()));
            }
        }        
        return std::accumulate(operands.begin(), operands.end(), 0);
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}