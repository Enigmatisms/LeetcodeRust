#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * upper_bound 与 lower bound 不要用反了
 * runtime: 89.04%
 * memory:  13.70%
 */
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int word_size = static_cast<int>(words.size());
        std::vector<int> query_freq(queries.size()), word_freq(word_size);
        for (size_t i = 0; i < queries.size(); i++) {
            query_freq[i] = get_freq(queries[i]);
            printf("%d, ", query_freq[i]);
        }
        printf("\n");
        for (int i = 0; i < word_size; i++) {
            word_freq[i] = get_freq(words[i]);
            printf("%d, ", word_freq[i]);
        }
        printf("\n");
        std::sort(word_freq.begin(), word_freq.end());
        std::vector<int> results;
        for (int q: query_freq) {
            int val = std::upper_bound(word_freq.begin(), word_freq.end(), q) - word_freq.begin();

            printf("%d, ", val);
            results.push_back(word_size - val);
        }
        printf("\n");
        return results;
    }
private:
    int get_freq(const std::string& s) const {
        std::vector<int> cnt(26, 0);
        for (char c: s)
            cnt[static_cast<int>(c - 'a')] ++;
        for (int num: cnt)
            if (num) return num;
        return 0;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::string> query = {"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"};
    std::vector<std::string> words = {"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
    sol.numSmallerByFrequency(query, words);
    return 0;
}