#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * 这么小规模的问题，穷举完全可以
 * 
 * 注意，此问题等价于：把所有多出来的石头，移动到空缺位置，的最优策略
 * 那么我们找出多出的石头的位置，与空缺位置，两两配对并算曼哈顿距离就行
 * 
 * 所以实际上是个排列问题
 * 第一遍过了，巨慢无比，手搓的需要考虑挺多，如果不去重？
 * runtime: 8.74%
 * memory:  5.34%
 * 
 * 不去重：
 * runtime: 9.22%
 * memory:  16.51%
 * 
 * C++ 标准库，不去重 好tm快
 * runtime: 96.60%
 * memory:  33.50%
 */

// 这是去重版本
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        std::vector<std::pair<int, int>> stones, vacancy;
        std::string index, arrange;
        stones.reserve(8);
        vacancy.reserve(8);
        index.reserve(8);
        arrange.reserve(8);
        int v = 0;
        #pragma unroll
        for (int i = 0; i < 3; i++) {
            #pragma unroll
            for (int j = 0; j < 3; j++) {
                v = grid[i][j];
                if (v == 0) vacancy.emplace_back(i, j);
                else if (v > 1) {
                    char idx = stones.size() + '0';
                    for (int k = 1; k < v; k++) index.push_back(idx);
                    stones.emplace_back(i, j);
                }
            }
        }
        // 开始排列，我们是求解 index 的全排列（同时去重）--- 可去可不去
        std::vector<bool> access(index.size(), false);
        std::unordered_set<std::string> exists;
        exists.reserve(8);
        return dfs_min(index, stones, vacancy, exists, access, arrange);
    }

    int dfs_min(
        const std::string& index, 
        const std::vector<std::pair<int, int>>& stones,
        const std::vector<std::pair<int, int>>& vacancy,
        std::unordered_set<std::string>& exists, 
        std::vector<bool>& accessed, 
        std::string& arrange
    ) {
        if (arrange.length() == index.length()) {
            // 去重
            if (exists.count(arrange)) return 100;
            int res = 0;
            for (size_t i = 0; i < arrange.length(); i++) {
                auto &st = stones[arrange[i] - '0'], &vc = vacancy[i];
                res += std::abs(st.first - vc.first) + std::abs(st.second - vc.second);
            }
            exists.emplace(arrange);
            return res;
        }

        int min_val = 100;
        for (size_t i = 0; i < index.length(); i++) {
            if (accessed[i]) continue;
            accessed[i] = true;
            arrange.push_back(index[i]);
            min_val = std::min(min_val,
                dfs_min(index, stones, vacancy, exists, accessed, arrange)
            );
            arrange.pop_back();
            accessed[i] = false;
        }
        return min_val;
    }
};

// 不去重
class Solution2 {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        std::vector<std::pair<int, int>> stones, vacancy;
        std::string index, arrange;
        stones.reserve(8);
        vacancy.reserve(8);
        index.reserve(8);
        arrange.reserve(8);
        int v = 0;
        #pragma unroll
        for (int i = 0; i < 3; i++) {
            #pragma unroll
            for (int j = 0; j < 3; j++) {
                v = grid[i][j];
                if (v == 0) vacancy.emplace_back(i, j);
                else if (v > 1) {
                    char idx = stones.size() + '0';
                    for (int k = 1; k < v; k++) index.push_back(idx);
                    stones.emplace_back(i, j);
                }
            }
        }
        // 开始排列，我们是求解 index 的全排列（同时去重）--- 可去可不去
        std::vector<bool> access(index.size(), false);
        return dfs_min(index, stones, vacancy, access, arrange);
    }

    int dfs_min(
        const std::string& index, 
        const std::vector<std::pair<int, int>>& stones,
        const std::vector<std::pair<int, int>>& vacancy,
        std::vector<bool>& accessed, 
        std::string& arrange
    ) {
        if (arrange.length() == index.length()) {
            // 去重
            int res = 0;
            for (size_t i = 0; i < arrange.length(); i++) {
                auto &st = stones[arrange[i] - '0'], &vc = vacancy[i];
                res += std::abs(st.first - vc.first) + std::abs(st.second - vc.second);
            }
            return res;
        }

        int min_val = 100;
        for (size_t i = 0; i < index.length(); i++) {
            if (accessed[i]) continue;
            accessed[i] = true;
            arrange.push_back(index[i]);
            min_val = std::min(min_val,
                dfs_min(index, stones, vacancy, accessed, arrange)
            );
            arrange.pop_back();
            accessed[i] = false;
        }
        return min_val;
    }
};

// std::next_permutation
class Solution3 {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        std::vector<std::pair<int, int>> stones, vacancy;
        stones.reserve(8);
        vacancy.reserve(8);
        #pragma unroll
        for (int i = 0; i < 3; i++) {
            #pragma unroll
            for (int j = 0; j < 3; j++) {
                int v = grid[i][j];
                if (v == 0) vacancy.emplace_back(i, j);
                else if (v > 1) {
                    for (int k = 1; k < v; k++) stones.emplace_back(i, j);;
                }
            }
        }
        int minv = 100;
        do {
            int local_min = 0;
            for (size_t i = 0; i < vacancy.size(); i++) {
                auto &st = stones[i], &vc = vacancy[i];
                local_min += std::abs(st.first - vc.first) + std::abs(st.second - vc.second);
            }
            minv = std::min(minv, local_min);
        } while (std::next_permutation(stones.begin(), stones.end()));
        return minv;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}