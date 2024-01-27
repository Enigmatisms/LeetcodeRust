#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * 哈希表：特别暴力，但是 work
 * runtime: 68.58%
 * memory:  5.42%
 * 这种情况确实可以进行位运算以减小内存开销（否则太长了），但由于.. 写起来很简单，这里就略过了。主要是要能想到。
*/

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(const std::string& s) const noexcept {
        if (s.length() <= 10) return {};
        std::unordered_map<std::string, bool> rep_map;
        std::vector<std::string> results;
        const int max_pos = s.length() - 10;
        for (int i = 0; i <= max_pos; i++) {
            std::string cur_s = s.substr(i, 10);
            auto it = rep_map.find(cur_s);
            if (it != rep_map.end()) {
                if (it->second == false) {
                    results.push_back(cur_s);
                    it->second = true;
                }
            } else {
                rep_map[cur_s] = false;
            }
        }
        return results;
    }
};

int main() {
  Solution sol;
  std::string test = "AAAAAAAAAAA";
  sol.findRepeatedDnaSequences(test);
  return 0; 
}