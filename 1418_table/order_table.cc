#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * runtime: 98.21%
 * memory:  89.29%
 */
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        std::unordered_set<int> table_idxs;
        std::unordered_map<std::string, std::vector<int>> order_table;
        for (const std::vector<string>& order: orders) {
            int table_id = atoi(order[1].c_str());
            order_table[order[2]].push_back(table_id);
            table_idxs.emplace(table_id);
        }
        std::vector<std::vector<std::string>> results(table_idxs.size() + 1,
            std::vector<std::string>(order_table.size() + 1, "0")
        );
        std::unordered_map<int, int> table_map;
        std::unordered_map<std::string, int> order_map;
        {
            std::vector<std::string> menu = {"Table"};
            for (auto it = order_table.cbegin(); it != order_table.cend(); it++)
                menu.push_back(it->first);
            std::sort(menu.begin() + 1, menu.end());
            for (size_t i = 1; i < menu.size(); i++)
                order_map[menu[i]] = i;
            results[0].assign(menu.begin(), menu.end());
        }
        {
            std::vector<int> sorted_idx(table_idxs.begin(), table_idxs.end());
            std::sort(sorted_idx.begin(), sorted_idx.end());
            for (size_t i = 0; i < sorted_idx.size(); i++) {
                int table_num = sorted_idx[i];
                table_map[table_num] = i + 1;
                results[i + 1][0] = std::to_string(table_num);
            }
        }
        for (auto [name, col_id]: order_map) {
            std::unordered_map<int, int> cnt;
            for (int table_id: order_table[name]) {
                cnt[table_id] += 1;
            }
            for (auto [table_id, num]: cnt) {
                int row_id = table_map[table_id];
                results[row_id][col_id] = std::to_string(num);
            }
        }
        return results;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}