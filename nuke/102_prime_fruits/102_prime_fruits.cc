#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

/**
 * runtime:
 * memory:
 */
class Solution {
public:
    vector<int> primeFruits(vector<int>& trees) {
        // write code here
        std::set<int> primes;
        for (int fruit: trees) {
            if (!is_prime(fruit)) continue;
            primes.emplace(fruit);
        }
        return std::vector<int>(primes.begin(), primes.end());
    }

    bool is_prime(int v) const {
        int sqrt_val = sqrtf(v);
        bool is_odd = v & 1;
        if (is_odd) {
            if (v == 1) return false;
            for (int i = 3; i <= sqrt_val; i += 2) {
                if (v % i == 0) return false;
            }
        } else {
            for (int i = 2; i <= sqrt_val; i ++) {
                if (v % i == 0) return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}