#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  24.25%
 */
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> vars;
        std::unordered_map<std::string, bool> accessed;
        // adjacent map is created
        for (size_t i = 0; i < equations.size(); i++) {
            const auto& s = equations[i];
            double value = values[i], inv_value = 1. / value;
            std::string v1 = s.front(), v2 = s.back();
            vars[v1].emplace_back(v2, value);
            vars[v2].emplace_back(v1, inv_value);
            accessed[v1] = false;
            accessed[v2] = false;
        }
        std::vector<double> results;
        results.reserve(queries.size());
        for (const auto& query: queries) {
            const auto& s1 = query[0], &s2 = query[1];
            if (!vars.count(s1) || !vars.count(s2)) {
                results.push_back(-1.0);
                continue;
            }
            if (s1 == s2) {
                results.push_back(1.0);
                continue;
            }
            double result = path_contribution(vars, accessed, s1, s2);
            results.push_back(result);
            // clear DFS access table
            for (auto it = accessed.begin(); it != accessed.end(); it++)
                it->second = false;
        }
        return results;
    }

    // find path using DFS or BFS
    double path_contribution(
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& vars,
        std::unordered_map<std::string, bool>& accessed,
        const std::string& nume, const std::string& denomi
    ) {
        std::vector<std::pair<std::string, double>> stack;
        stack.emplace_back(nume, 1);
        while (!stack.empty()) {
            auto [cur_nume, ratio] = stack.back();
            stack.pop_back();
            accessed[cur_nume] = true;
            for (auto [cur_denom, div_num]: vars[cur_nume]) {
                if (accessed[cur_denom]) continue;
                if (cur_denom != denomi) {
                    stack.emplace_back(cur_denom, ratio * div_num);
                } else {
                    return ratio * div_num;
                }
            }
        }
        return -1.0;        // unreachable
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}