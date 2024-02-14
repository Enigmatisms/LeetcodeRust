#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 85.73%
 * memory:  29.89%
 */
class Solution {
public:
    static char isOperator(const std::string& s) {
        if (s.length() > 1 || s.front() > '/') return 0;
        return s.front();
    }

    int evalRPN(vector<string>& tokens) {
        std::vector<int> operands;
        int result = 0;
        for (const std::string& token: tokens) {
            char op_type = Solution::isOperator(token);
            if (op_type) {
                int operand_1 = operands.back();
                operands.pop_back();
                int operand_2 = operands.back();
                operands.pop_back();
                int temp = 0;
                switch (op_type) {
                case '+': {temp = operand_2 + operand_1; break;}
                case '-': {temp = operand_2 - operand_1; break;}
                case '*': {temp = operand_2 * operand_1; break;}
                case '/': {temp = operand_2 / operand_1; break;}
                }
                operands.push_back(temp);
            } else {
                operands.push_back(atoi(token.c_str()));
            }
        }
        return operands.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}