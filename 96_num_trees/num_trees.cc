#include "../ListNode.hpp"
/**
 * (做之前的想法) 感觉这题有陷阱：递归可能不是个好方法
 * 写了一种暴力法（95题）：不预计算就 TLE，说明我的想法正确，这道题根本不需要递归
 * 计数问题貌似通常都可以不需要递归? 之前碰到一个这样的题目
 * 优化得不错
 * runtime: 100.00%
 * memory:  40.22%
 */
class Solution {
public:
    int numTrees(int n) const {
        std::vector<int> numbers = {1, 1, 2, 5, 14};    // 0, 1, 2, 3
        if (n <= 4) return numbers[n];
        numbers.reserve(n);
        for (int i = 5; i <= n; i++) {
            int result = 0, half_i = i >> 1;
            for (int j = 0; j < half_i; j++) 
                result += (numbers[j] * numbers[i - j - 1]) << 1;
            if (i & 1) {
                int center_v = numbers[half_i];
                result += center_v * center_v;
            }
            if (i < n)
                numbers.push_back(result);
            else
                return result;
        }
        return 0;
    }

    int numTrees_brute_force(int n) const {
        return gen_bst_recursive_brute_force(1, n);
    }

    // 这种暴力法的运行时间垫底... (1.95%)，并且我这里还与计算了 -1至4 的情况，如果不计算估计 TLE
    // 果然，我不预先计算就 TLE 了. 栈太深了，递归函数会 inline 吗？
    int gen_bst_recursive_brute_force(int start, int end) const {
        int diff = end - start;
        switch (diff)
        {
            case -1: return 1;
            case 0: return 1;
            // case 1: return 2;
            // case 2: return 5;
            // case 3: return 14;
            // case 4: return 42;
            default:
                break;
        }
        int case_sum = 0; 
        for (int root = start; root <= end; root++) {        // set current as root
            auto left_cases  = gen_bst_recursive_brute_force(start, root - 1);
            auto right_cases = gen_bst_recursive_brute_force(root + 1, end);
            case_sum += left_cases * right_cases;
        }
        return case_sum;
    }
};

int main(int argc, char** argv) {    
    Solution sol;
    int value = argc > 1 ? atoi(argv[1]) : 3;
    std::cout << sol.numTrees(value) << std::endl;
    return 0;
}