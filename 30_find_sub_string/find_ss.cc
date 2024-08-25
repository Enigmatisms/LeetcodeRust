#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        // for all the substrings in words, we first find the matching indices for all of them
        // build a hash table with key (every possible index) / value (vector of every possible word)
        // for each starting index, try to synthesis the sentence (at the same time keeping count of the usage of words)
        // note that: word can have duplicates, so one key might map to multiple words (thus we need counter)
        // word can also be the substring of other words, so one value (word) can have multiple keys
        // z-algorithm (TODO compare with KMP)
    }

    void find_all_index(const std::string& haystack, const std::string& needle, std::vector<short>& all_idxs) const {
        //
    }
};