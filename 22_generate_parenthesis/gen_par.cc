#include <iostream>
#include <vector>
#include <stack>
/**
 * Solved within 1300s (too long)
 * 0ms: 100% (run-time)
 * 11.6MB: 44.7% (memory) 
*/

class Solution {
public:
    std::vector<std::string> generateParenthesis(uint8_t n) {
        if (n == 0) return {"",};
        else if (n == 1) return {"()",};

        std::vector<char> pars;
        pars.emplace_back('(');
        std::vector<std::string> results;
        uint8_t left_cnt = n - 1, right_cnt = n;
        
        if (left_cnt > 0) {
            pars.emplace_back('(');
            recursive_gen_par(pars, results, left_cnt - 1, right_cnt);
            pars.pop_back();
        }
        if (right_cnt > 0 && left_cnt < right_cnt) {
            pars.emplace_back(')');
            recursive_gen_par(pars, results, left_cnt, right_cnt - 1);
            pars.pop_back();
        }
        return results;
    }

    void recursive_gen_par(std::vector<char>& pars, std::vector<std::string>& results, uint8_t left_cnt, uint8_t right_cnt) const {
        if (right_cnt == 0) {
            results.emplace_back(pars.begin(), pars.end());
            return;
        }
        if (left_cnt > 0) {
            pars.emplace_back('(');
            recursive_gen_par(pars, results, left_cnt - 1, right_cnt);
            pars.pop_back();
        }
        if (right_cnt > 0 && left_cnt < right_cnt) {
            pars.emplace_back(')');
            recursive_gen_par(pars, results, left_cnt, right_cnt - 1);
            pars.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto results = sol.generateParenthesis(4);
    for (const auto& str: results) {
        std::cout << str << std::endl;
    } 
}