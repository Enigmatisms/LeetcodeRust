#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 41.12%
 * memory:  6.60%
 */
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        vector<string> transpose_words;
        for (int col = 0;;col++) {
            bool cut_off = false, pushed = false;
            std::string transposed;
            for (int row = 0; row < words.size(); row++) {
                if (col >= words[row].length()) {
                    cut_off = true;
                    continue;
                }
                if (cut_off) return false;
                transposed.push_back(words[row][col]);
                pushed = true;
            }
            if (!pushed) break;
            transpose_words.push_back(transposed);
        }
        if (transpose_words.size() != words.size()) return false;
        for (size_t i = 0; i < words.size(); i++) {
            if (transpose_words[i] != words[i]) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}