#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * what the fuck? 这道题做出来需要一分钟吗？为什么是中等题？
 * runtime: 60.89%
 * memory:  92.82%
 */
class Solution {
public:
    string removeStars(string s) {
        // 就是栈？
        std::string result;
        result.reserve(s.size());
        for (char v: s) {
            if (v == '*' && !result.empty())
                result.pop_back();
            else
                result.push_back(v); 
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}