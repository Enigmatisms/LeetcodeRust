#include <iostream>
#include <vector>
#include <algorithm>

bool is_denom_p(int k, int p) {
    while ((p & 1) == 0)  // 2 
        p >>= 1;
    while ((p % 5) == 0)  // 5
        p /= 5;
    if (p == 1) return false;
    long long result = 1;
    int val = 10;
    while (k) {
        if (k & 1) result = (result * val) % p;
        k >>= 1;
        val *= val;
        val %= p;
    }
    return result == 1;
}


int main(int argc, char** argv) {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int k = 0, p = 0;
        std::cin >> k >> p;
        std::cin.get();
        std::cout << (is_denom_p(k, p) ?  "Yes" : "No") << std::endl;
    }
    return 0;
}