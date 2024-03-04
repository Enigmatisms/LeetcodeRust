#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * runtime: 33.99%
 * memory:  
 */
class Solution {
public:
    int minSteps(string s, string t) {
        std::unordered_map<char, int> tcnt;
        for (char c: t) 
            tcnt[c] += 1;
        for (char c: s) {
            auto it = tcnt.find(c);
            if (it != tcnt.end() && it->second > 0)
                it->second --;
        }
        int result = 0;
        for (auto [_, cnt]: tcnt)
            result += cnt;
        return result;
    }

    // 两次哈希计数
    int minSteps2(string s, string t) {
        std::unordered_map<char, int> scnt, tcnt;
        for (char c: s) 
            scnt[c] += 1;
        for (char c: t) 
            tcnt[c] += 1;
        for (auto [c, cnt]: scnt) {
            auto it = tcnt.find(c);
            if (it != tcnt.end()) {
                if (cnt >= it->second)
                    it->second = 0;
                else
                    it->second -= cnt;
            }
        }
        int result = 0;
        for (auto [_, cnt]: tcnt)
            result += cnt;
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}