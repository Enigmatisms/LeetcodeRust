#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 没什么难的，基础算法
 * runtime: 100% 
 * memory:  9.83%
 */
class Solution {
public:
    double myPow(double x, int n) const {
        int64_t N = n;
        if (n == 0 || x == 1)
            return 1;
        else if (n < 0) {
            x = 1. / x;
            N = -N;
        }

        double result = 1, pow_v = x;
        for (int i = 0, flag = 1; i < 32; i++, flag <<= 1) {
            if (flag & N) {
                result *= pow_v;
            }
            pow_v *= pow_v;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<double> xs = {2., 3., 4., -2., 0., 1., 0.5};
    std::vector<int> ns    = {10, 4, 3, 5, 20, -200, -3};
    for (size_t i = 0; i < ns.size(); i++) {
        std::cout << sol.myPow(xs[i], ns[i]) << std::endl;
    }
    return 0;
}