#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 假设存在这么一个好进制 k, 那么显然
 * n = k^0 + k^1 + k^2 + ... + k^m
 * 是否存在？任何一个数（n>=3）都存在，我再不济也可以选 n - 1 进制啊，变成 11 了
 * 所以不用担心是否存在，只要找最小就好
 * 
 * 我们能不能求出 k？ 我觉得是可以的但需要推导。比如我们首先已经可以知道 k 小于 n^{1/m}
 * 因为 k^m < n ---> k < n^{1/m}，舍掉了很多需要查找的位置
 * 那么是否可以确定 k 的下限？首先我们看 (k+1)^m 与 n 的关系，我的评价是，根据二项展开
 * (k+1)^m 显然大于 n，都不用多想，因为所有的系数都是正的, 所以 (k+1)^m > n ---> k+1 > n^{1/m}
 * k > n^{1/m} - 1 ---> k \in (n^{1/m} - 1, n^{1/m}) 这是什么啊？
 * 如果 n^{1/m} 是整数，就爆炸了，如果不是整数，那么就是这个的下取整
 * 那么 n^{1/m} 可能是整数吗，不可能啊，k < n^{1/m} < k+1 啊
 * 所以可以知道解答。但是 m 怎么求？n有但是 m 无。m的上限可以确定：由等比数列
 * [k^{1+m} - 1] <= 10^(18) * (k - 1)
 * 左边放缩: (k - 1)(k^m + 1) < [k^{1+m} - 1] <= 10^(18) * (k - 1)
 * 则得到 k^m < 10^(18) - 1或者说 k^m < n - 1 -> m < logk(n-1), 最大时，k=2, n = 10^18 求得为 59
 * 也即 m 最大可以取59位，最后总长度不超过60
 * 那么接下来就是搜索了。怎么搜索？给定 m 可以算 k 出来，k要大于等于 2
 * 
 * 这种题目... 可以的，我很喜欢
 * runtime: 100.00%
 * memory:  49.51%
 */
class Solution {
public:
    string smallestGoodBase(string n) {
        long long value = atoll(n.c_str());
        // 可以二分查找？
        int m_s = 2, m_e = 59;
        while (m_s < m_e) {
            int m_m = (m_s + m_e) >> 1;
            int m_res = std::pow(value, 1.f / float(m_m));
            if (m_res == 1) {
                m_e = m_m;
            } else {
                m_s = m_m + 1;
            }
        }
        for (int m = m_s; m >= 2; m--) {        // 位数最少也是2
            long long k = std::pow(value, 1.f / float(m));    // 当前进制数
            long long n = value;
            bool correct = true;
            while (n) {
                if (n % k != 1) {
                    correct = false;
                    break;
                }
                n /= k;
            }
            if (correct) return std::to_string(k);
        }
        return std::to_string(value - 1);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    auto res = sol.smallestGoodBase("4681");
    std::cout << res << std::endl;
    return 0;
}