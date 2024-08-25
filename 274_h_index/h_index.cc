#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  6.32%
 */
class Solution {
public:
    int hIndex(vector<int>& citations) const {
        std::sort(citations.begin(), citations.end());
        int old_citation = -1, h_index = 0;
        for (int i = 0; i < citations.size(); i++) {
            int cite = citations[i];
            if (cite == old_citation) continue;
            old_citation = cite;
            int num_paper = citations.size() - i;
            if (num_paper < cite)
                h_index = std::max(h_index, num_paper);
            else
                h_index = std::max(h_index, cite);
        }
        return h_index;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}