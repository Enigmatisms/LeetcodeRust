#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

/**
 * 要使用常量额外空间 所以要有一个写入指针，注意如果存在压缩则一定比原来短
 * 
 * 一定要注意对于在 for 循环内部操作循环变量时，循环变量是否要自动自增（for 循环本身），本题一开始错就是因为
 * 内部操作了 i，外部开始还 i++，导致少算一个
 * runtime: 100.00%
 * memory:  7.17%
 */
class Solution {
public:
    static void overwrite_str(vector<char>& chars, int& wptr, char cur, int cnt) noexcept {
        chars[wptr ++] = cur;
        std::string cnt_s = std::to_string(cnt);
        for (size_t i = 0; i < cnt_s.size(); i++)
            chars[wptr + i] = cnt_s[i];
        wptr += cnt_s.length();
    }

    static int compress(vector<char>& chars) noexcept {
        int wptr = 0, size = chars.size();
        chars.push_back(' ');
        for (int i = 0; i < size;) {
            char v = chars[i];
            int sptr = i;                         // go to the next pos
            for (; i <= size; i++) {
                if (chars[i] != v) break; 
            }
            int cnt = i - sptr;
            if (cnt > 1) {              // 存在大于 1 个的相同字符
                overwrite_str(chars, wptr, v, cnt);
            } else {
                chars[wptr] = v;
                wptr ++;
            }
        }
        // 截断到 end() = wptr
        chars.resize(wptr);
        return wptr;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<char> chars = {'a','a','b','b','c','c','c'};
    sol.compress(chars);
    std::cout << std::string(chars.begin(), chars.end()) << std::endl;
    return 0;
}