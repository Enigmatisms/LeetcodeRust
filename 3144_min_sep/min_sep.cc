#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题一眼看上去就是用哈希表，但注意，本题需要分割连续的字符串
 * 结果应该是用动态规划吧（大概的思想）
 * 长度为 n，则最多可以分为 n。此后逐步下调
 * 用动态规划可以这样做：但是要存很多哈希表
 * 我的想法目前是 O(n^2) 的计算量
 * 
 * DP[i] 表示到下标为 i (长度为 i + 1) 的串，内最少的平衡串个数
 * 
 * DP[i] 递推公式为
 * 
 * DP[i + 1] = min(DP[j] + 1 | s[j + 1, i + 1] 是平衡串)  (注意是闭区间)
 * 找到所有满足要求的 j，求最小即可
 * 
 * DP[0] = 1;
 * 结果很拉，状态压缩之后才避免 TLE 的
 * 为什么结果拉呢？其实我的思路都是对了，但是有一点没想到：
 * 怎么通过单个哈希表快速判断所有字符出现次数相同？
 * 当<char, short> 哈希表中，记录的字符出现最大次数乘以哈希表长度时，说明哈希表表示的字串是平衡的
 * 
 * runtime: 5.11%
 * memory:  5.11%
 */
class Solution {
public:
    inline void set_bit(uint32_t& num, uint32_t index) const noexcept {
        num |= 1 << index;
    }

    inline void clear_bit(uint32_t& num, uint32_t index) const noexcept {
        num ^= 1 << index;
    }

    int minimumSubstringsInPartition(string s) {
        int length = s.length();
        std::array<short, 26> char_cnts = {0};
        std::unordered_map<short, uint32_t> cnt_chars;
        std::vector<int> dp(length, 0);
        dp[0] = 1;
        uint32_t c_index = s.front() - 'a';
        char_cnts[c_index] = 1;
        set_bit(cnt_chars[1], c_index);
        for (int i = 1; i < length; i++) {
            char c = s[i];
            c_index = c - 'a';
            int c_cnt = char_cnts[c_index] ++;
            if (c_cnt > 0) {
                clear_bit(cnt_chars[c_cnt], c_index);
                if (cnt_chars[c_cnt] == 0)
                    cnt_chars.erase(c_cnt);
            }
            set_bit(cnt_chars[c_cnt + 1], c_index);
            if (cnt_chars.size() == 1) {            // 已经找到了
                dp[i] = 1;
                continue;
            }
            int min_sep_num = 1 + dp[i - 1];
            std::array<short, 26> local_c_cnts = char_cnts;
            std::unordered_map<short, uint32_t> local_cnts_c = cnt_chars;
            for (int j = 0; j + 1 < i; j++) {
                char cj = s[j];
                c_index = cj - 'a';
                int j_cnt = local_c_cnts[c_index] --;
                clear_bit(local_cnts_c[j_cnt], c_index);
                if (local_cnts_c[j_cnt] == 0)
                    local_cnts_c.erase(j_cnt);
                if (j_cnt > 1)
                    set_bit(local_cnts_c[j_cnt - 1], c_index);
                if (local_cnts_c.size() == 1) {
                    // 从 j + 1 到 i 是一个平衡字符串
                    // 这里逻辑有点问题
                    min_sep_num = std::min(dp[j] + 1, min_sep_num);
                }
            }
            dp[i] = min_sep_num;
        }
        return dp.back();
    }

    // 这是 TLE 版本，我用了 hash + 另一个反向映射表
    // 但反向映射表太慢了
    int minimumSubstringsInPartition_two_table(string s) {
        int length = s.length();
        std::array<short, 26> char_cnts = {0};
        std::unordered_map<short, std::unordered_set<char>> cnt_chars;
        std::vector<int> dp(length, 0);
        dp[0] = 1;
        char_cnts[s.front() - 'a'] = 1;
        cnt_chars[1].emplace(s.front());
        for (int i = 1; i < length; i++) {
            char c = s[i];
            int c_cnt = char_cnts[c - 'a'] ++;
            if (c_cnt > 0) {
                cnt_chars[c_cnt].erase(c);
                if (cnt_chars[c_cnt].empty())
                    cnt_chars.erase(c_cnt);
            }
            cnt_chars[c_cnt + 1].emplace(c);
            if (cnt_chars.size() == 1) {            // 已经找到了
                dp[i] = 1;
                continue;
            }
            int min_sep_num = 1 + dp[i - 1];
            std::array<short, 26> local_c_cnts = char_cnts;
            std::unordered_map<short, std::unordered_set<char>> local_cnts_c = cnt_chars;
            for (int j = 0; j + 1 < i; j++) {
                char cj = s[j];
                int j_cnt = local_c_cnts[cj - 'a'] --;
                local_cnts_c[j_cnt].erase(cj);
                if (local_cnts_c[j_cnt].empty())
                    local_cnts_c.erase(j_cnt);
                if (j_cnt > 1)
                    local_cnts_c[j_cnt - 1].emplace(cj);
                if (local_cnts_c.size() == 1) {
                    // 从 j + 1 到 i 是一个平衡字符串
                    // 这里逻辑有点问题
                    min_sep_num = std::min(dp[j] + 1, min_sep_num);
                }
            }
            dp[i] = min_sep_num;
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}