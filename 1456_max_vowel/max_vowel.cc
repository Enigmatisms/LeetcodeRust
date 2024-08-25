#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

/**
 * 看起来很简单的一体，但注意输入的范围是 1e5，所以要快
 * 这是什么简单题？根本够不着中等吧
 * runtime: 89.93%
 * memory:  18.90%
 * 
 * 笑死，改成 static int, const string& s 变成：
 * 99.13%
 * 99.83%
 */
class Solution {
public:
    static constexpr bool is_vowel(char v) noexcept {
        return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
    }
    static int maxVowels(const string& s, int k) {
        int num_vowel = 0, max_vowel = 0;
        for (int i = 0; i < k; i++) {
            num_vowel += is_vowel(s[i]);
        }
        max_vowel = num_vowel;
        for (size_t i = k; i < s.length(); i++) {
            num_vowel -= is_vowel(s[i - k]);
            num_vowel += is_vowel(s[i]);
            max_vowel = std::max(max_vowel, num_vowel);
        }
        return max_vowel;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}