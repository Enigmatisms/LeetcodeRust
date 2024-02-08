#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Dijkstra 算法升级版：记录所有最短路径
 * runtime: 99.37%
 * memory:  72.02%
 */
class Solution {
public:
    bool is_only_one_diff(const std::string& str1, const std::string& str2) const {
        auto mismatchPair = std::mismatch(str1.begin(), str1.end(), str2.begin());
        if (mismatchPair.first == str1.end())
            return false;
        return std::mismatch(mismatchPair.first + 1, str1.end(), mismatchPair.second + 1).first == str1.end();
    }

    short check_end_word(string endWord, const vector<string>& wordList) const {
        for (short i = 0; i < wordList.size(); i++) {
            if (strcmp(wordList[i].c_str(), endWord.c_str()) == 0) return i;
        }
        return -1;
    }

    unordered_set<short> beg_word_diff_words(const vector<string>& wordList, string beginWord) const {
        unordered_set<short> results;
        for (short i = 0; i < wordList.size(); i++) {
            if (is_only_one_diff(beginWord, wordList[i]))
                results.emplace(i);
        }
        return results;
    }

    void trace_path(
        const vector<vector<short>>& next_verts, vector<vector<string>>& results, 
        const vector<string>& wordList, vector<string>& result, short current, short depth
    ) const {
        if (next_verts[current].empty()) {
            results.push_back(result);
            return;
        }
        result[depth] = wordList[current];
        for (short next_idx: next_verts[current])
            trace_path(next_verts, results, wordList, result, next_idx, depth + 1);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        short end_index = check_end_word(endWord, wordList);
        if (end_index < 0) {
            return {};
        }
        std::unordered_set<short> beg_diff_words = beg_word_diff_words(wordList, beginWord);
        if (beg_diff_words.empty()) {
            return {};
        }
        if (beg_diff_words.count(end_index)) return {{beginWord, endWord}};
        std::vector<bool> checked(wordList.size(), false);
        std::vector<short> costs(wordList.size(), 1000), current = {end_index};
        std::vector<std::vector<short>> next_verts(wordList.size());
        std::vector<std::vector<string>> results;
        costs[end_index] = 0;
        while (!current.empty()) {
            short min_cost = 1000;
            std::vector<short> new_current;
            for (short cindex: current) {
                short cur_cost = costs[cindex] + 1;
                const std::string& cur_s = wordList[cindex];
                checked[cindex] = true;
                for (short i = 0; i < wordList.size(); i++) {
                    if (checked[i]) continue;
                    if (is_only_one_diff(wordList[i], cur_s)) {
                        if (cur_cost < costs[i]) {          // discard the old
                            costs[i] = cur_cost;
                            next_verts[i] = {cindex};
                            new_current.push_back(i);
                        } else if (cur_cost == costs[i]) {                            // same cost, add
                            next_verts[i].push_back(cindex);
                        }
                        if (beg_diff_words.count(i))
                            min_cost = std::min(min_cost, cur_cost);
                    }
                }
            }
            if (min_cost < 1000) {
                for (short index: beg_diff_words) {
                    // printf("Cost: %d, min_cost: %d, index: %d, %d\n", costs[index], min_cost, index, end_index);
                    if (costs[index] != min_cost) continue;
                    std::vector<std::string> result(min_cost + 2);
                    result.front() = beginWord;
                    result.back()  = endWord;
                    trace_path(next_verts, results, wordList, result, index, 1);
                }
                return results;
            }
            current = std::move(new_current);
        }
        return {};
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::string beg_word = "hit";
    std::string end_word = "cog";
    std::vector<std::string> word_list = {"hot","dot","dog","lot","log","cog"};
    auto res = sol.findLadders(beg_word, end_word, word_list);
    for (const std::vector<std::string>& list: res) {
        for (std::string s: list)
            std::cout << s << " -> ";
        std::cout << std::endl;
    }
    return 0;
}