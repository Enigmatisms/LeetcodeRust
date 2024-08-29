#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 总感觉有点像字典树，我的感觉是建立一个前缀树
 * 这种方法可以但是 TLE，你的方法本质来说还是暴力
 * runtime: 
 * memory:  
 */

class Trie {
    std::unordered_map<char, Trie*> data;
public:
    int search(const std::vector<int>& s, int start) {
        const Trie* ptr = this;
        int length = 0, size = s.size();
        for (int i = start; i < size; i++) {
            char c = s[i];
            auto it = ptr->data.find(c);
            if (it == data.end()) return length;
            length ++;
            ptr = it->second;
        }
        return length;
    }

    ~Trie() {
        for (auto [k, v]: data) {
            delete v;
        }
    }

    void insert(const std::vector<int>& s, int index = 0) {
        char c = s[index ++];
        auto [it, inserted] = data.emplace(c, new Trie());
        if (index < s.size())
            it->second->insert(s, index);
    }
};
class TLESolution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        Trie search_tree;
        int n1_size = nums1.size(), n2_size = nums2.size(), max_len = 0;
        for (int i = 0; i < n1_size; i++) {
            search_tree.insert(nums1, i);
        }
        // 如果用注释这段的逻辑，38 过不了
        // 想得还是不够周全
        // int ptr = 0;
        // while (ptr < n2_size) {
        //     int len = search_tree.search(nums2, ptr);
        //     max_len = std::max(len, max_len);
        //     ptr = ptr + std::max(len, 1);
        // }
        for (int ptr = 0; ptr < n2_size; ptr++) {
            int len = search_tree.search(nums2, ptr);
            max_len = std::max(len, max_len);
        }
        return max_len;
    }
};


// 还是需要动态规划啊
/**
 * (1) DP 数组含义：DP数组含义 DP[i][j] 表示 nums1[i:] 与 nums2[j:] 的最长公共前缀长度
 * (2) DP 递推公式
 * 如果已知 DP[i+1][j+1] 想求 DP[i][j+1], DP[i+1][j], DP[i][j]
 * 我们分析一下这三种情况分别应该为什么
 * DP[i][j+1] 表示 nums1[i+1:] 向前探查到 nums[i:]
 * 如果 nums1[i] != nums2[j+1]，则立刻为 0
 * 否则，为 1 + DP[i+1][j+2] (如果 j + 2 在范围内的话)
 * 其余都是这样的
 * (3) 初始条件：如果两个末尾相等，就是 1，否则就是 0
 * (4) 不可压缩
 * (5) 本题要加一个终末条件，一开始没想清楚：在递推过程中，由于最后不是输出 dp[0][0]
 * 而是在过程中就不断记录最大，所以之后的题目也要注意这一点，reduce 是什么时候做
 * (6) 注意范围
 * 
 * runtime: 97.69%
 * memory:  83.17%
 */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1_size = nums1.size(), n2_size = nums2.size();
        std::vector<std::vector<short>> dp(n1_size + 1, std::vector<short>(n2_size + 1, 0));
        int max_len = 0;
        for (int i = n1_size - 1; i >= 0; i--) {
            int nums1_i = nums1[i];
            auto& row = dp[i];
            for (int j = n2_size - 1; j >= 0; j--) {
                if (nums2[j] != nums1_i) continue;      // 立刻为 0
                // 这里，如果 i + 1 >= n1_size，也是允许的（i + 1 与 j + 1 有一个在范围内时，结果一定为 1，如果要求两个都在范围内就会出错）
                int v = 1 + dp[i + 1][j + 1];
                row[j] = v;
                max_len = std::max(v, max_len);
            }
        }
        return max_len;
    }
};


int main(int argc, char** argv) {
    Solution sol;

    return 0;
}