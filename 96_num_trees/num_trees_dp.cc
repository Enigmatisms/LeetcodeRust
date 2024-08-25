#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 用动态规划确实很好写，可以很快找到规律。上一次做这个题是快五个月前
 * runtime: 32.56%
 * memory:  42.50%
 */
class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        std::vector<int> num_choices(n, 1);
        num_choices[0] = 1;
        num_choices[1] = 2;
        for (int i = 2; i < n; i++) {
            int sum_choice = 2 * num_choices[i - 1];
            for (int j = 1; j < i; j++) {
                int lc_choice = num_choices[j - 1],
                    rc_choice = num_choices[i - j - 1];
                sum_choice += lc_choice * rc_choice;
            }
            num_choices[i] = sum_choice;
        }
        return num_choices.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}