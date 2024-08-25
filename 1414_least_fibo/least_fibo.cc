/**
 * 题目：
 * 给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
 * 输入：k = 7
 * 输出：2 
 * 解释：斐波那契数字为：1，1，2，3，5，8，13，……
 * 对于 k = 7 ，我们可以得到 2 + 5 = 7 。
 * 
*/
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

/**
 * 第一眼看上去没太多思路，个人的想法是：
 * 根据 k 首先找到第一个不超过 k 的 Fibo 数
 * 此后就可以递归了。总是取最大的可以帮助我们解决此问题（贪心）
 * 问题在于如何快速找到不超过对应值的最大数？
 * 最简单的：不断生成到对应值，float pow 二分查找（用解析表达式）
 * 
 * f(46) = 1134903170, 所以只需要从 46 开始
 * 打个表不过分吧
 * runtime: 100.00%
 * memory:  34.15%
 */
const std::array<int, 45> FIBO = {
    1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 
    377, 610, 987, 1597, 2584, 4181, 6765, 10946, 
    17711, 28657, 46368, 75025, 121393, 196418, 
    317811, 514229, 832040, 1346269, 2178309, 3524578, 
    5702887, 9227465, 14930352, 24157817, 39088169, 
    63245986, 102334155, 165580141, 267914296, 
    433494437, 701408733, 1134903170
};

class Solution {
public:
    int findMinFibonacciNumbers(int k) const noexcept  {
        return recursive_search(k, 40);
    }

    int recursive_search(int k, int end = 40) const noexcept {
        int index = std::upper_bound(FIBO.begin(), FIBO.begin() + end, k) - FIBO.begin();
        int ub = FIBO[index - 1];
        if (ub == k) return 1;
        return recursive_search(k - ub, index) + 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int test = 645157245;
    sol.findMinFibonacciNumbers(test);
    return 0;
}