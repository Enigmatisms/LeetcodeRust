#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

/**
 * 
 * runtime: 39.01%
 * memory:  65.96%
 */
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        std::partial_sum(travel.begin(), travel.end(), travel.begin());
        std::pair<int, int> m_cnt(0, 0), p_cnt(0, 0), g_cnt(0, 0);
        for (int i = 0; i < garbage.size(); i++) {
            const auto& s = garbage[i];
            for (char v: s) {
                if (v == 'M') {
                    m_cnt.first  = i;
                    m_cnt.second ++;
                } else if (v == 'P') {
                    p_cnt.first  = i;
                    p_cnt.second ++;
                } else {
                    g_cnt.first  = i;
                    g_cnt.second ++;
                }
            }
        }
        int result = m_cnt.second + (m_cnt.first > 0 ? travel[m_cnt.first - 1] : 0);
        result += p_cnt.second + (p_cnt.first > 0 ? travel[p_cnt.first - 1] : 0); 
        result += g_cnt.second + (g_cnt.first > 0 ? travel[g_cnt.first - 1] : 0); 
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}