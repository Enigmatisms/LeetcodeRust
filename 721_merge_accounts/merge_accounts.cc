#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

/**
 * 感觉好像没什么难的。用 unordered_map 和 unordered_set
 * 算是暴力过的吧
 * runtime: 6.21% (估计多一点就不行了)
 * memory:  58.76%
 */
class Solution {
public:
    using Set = std::set<std::string>;

    class AccountSet {
    public:
        Set data;
        bool merged = false;
    public:
        AccountSet() = default;

        AccountSet(vector<std::string>::const_iterator beg, vector<std::string>::const_iterator end) {
            for (; beg != end; beg++) {
                data.emplace(*beg);
            }
        }

        AccountSet& operator +=(AccountSet& other) {
            for (const std::string& s: other.data)
                data.emplace(s);
            other.merged = true;
            return *this;
        }

        AccountSet& operator +=(const std::vector<std::string>& other) {
            for (auto cit = other.cbegin() + 1; cit != other.cend(); cit++)
                data.emplace(*cit);
            return *this;
        }

        AccountSet operator+(AccountSet& a) {
            AccountSet new_data;
            for (const std::string& s: a.data)
                new_data.data.emplace(s);
            a.merged = true;
            this->merged = true;
            return new_data;
        }

        bool contains(std::string val) const noexcept {
            return data.find(val) != data.end();
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<std::string, std::vector<AccountSet>> map;
        for (const auto& account: accounts) {
            std::string name = account[0];
            auto it = map.find(name);
            if (it != map.end()) { // there exists users with the same account name
                std::vector<short> to_merge;
                for (short k = 0; k < it->second.size(); k++) {
                    auto& acc_set = it->second[k];
                    if (acc_set.merged) continue;
                    for (size_t i = 1; i < account.size(); i++) {
                        std::string email = account[i];
                        if (acc_set.contains(email)) {
                            to_merge.push_back(k);
                            break;
                        }
                    }
                }
                // all the accounts to merged are found, merge:
                if (to_merge.empty()) {
                    it->second.emplace_back(account.begin() + 1, account.end());
                    continue;
                }
                auto& first   = it->second[to_merge[0]];
                first.merged  = false;
                for (size_t i = 1; i < to_merge.size(); i++)
                    first    += it->second[to_merge[i]];
                first        += account;                               // only add the [1:]
            } else {                // there is no account with the same name
                // create a new pool
                map[name] = {AccountSet(account.begin() + 1, account.end())};
            }
        }
        // in the end, the map only contains each username with their sorted accounts
        vector<vector<string>> result;
        result.reserve(map.size() * 2);
        for (const auto& [name, merged_accs]: map) {
            for (const auto& merged_acc: merged_accs) {
                if (merged_acc.merged) continue;
                std::vector<std::string> acc;
                acc.reserve(merged_acc.data.size() + 1);
                acc.push_back(name);
                for (const auto& email: merged_acc.data)
                    acc.push_back(email);
                result.push_back(acc);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}