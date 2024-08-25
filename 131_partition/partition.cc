#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: first solution (5.12%, so lame)
 * memory:  first solution (4.98%, so lame)
 */
class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) const noexcept {
        if (end - start <= 1) {
            return true; 
        }
        auto s_ptr = s.data() + start, e_ptr = s.data() + end - 1;
        for(;s_ptr < e_ptr; s_ptr++, e_ptr--) {
            if (*s_ptr != *e_ptr) {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) const {
        int length = s.length();
        auto res = recursive_solve(s, 0, length);
        for (auto& vec: res) 
            std::reverse(vec.begin(), vec.end());
        return res;
    }

    std::vector<std::vector<std::string>> recursive_solve(const string& s, int start, int end) const {
        if (end - start == 1) return {{s.substr(start)}};
        std::vector<std::vector<std::string>> results;
        if (isPalindrome(s, start, end))
            results.push_back({s.substr(start)});
        for (int i = start + 1; i < end; i++) {
            if (i - start > 1 && !isPalindrome(s, start, i))
                continue;
            auto res = recursive_solve(s, i, end);
            if (!res.empty()) {
                for (auto vec: std::move(res)) {
                    results.emplace_back(std::move(vec));
                    results.back().push_back(s.substr(start, i - start));
                }
            }
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    sol.partition("aab");
    return 0;
}