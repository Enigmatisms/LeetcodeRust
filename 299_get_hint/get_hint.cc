#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这是中等题？这不是秒杀？
 * runtime: 100.00%
 * memory:  42.86%
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int slen = secret.size();
        int bull_value = 0, cow_value = 0;
        std::array<int, 10> secret_cnt, guess_cnt;
        for (int i = 0; i < slen; i++) {
            int vs = secret[i] - '0', vg = guess[i] - '0';
            if (vs == vg) {
                ++ bull_value;
            } else {
                ++ secret_cnt[vs];
                ++ guess_cnt[vg];
            }
        }
        for (int i = 0; i < 10; i++)
            cow_value += std::min(secret_cnt[i], guess_cnt[i]);
        return std::to_string(bull_value) + "A" + std::to_string(cow_value) + "B";
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}