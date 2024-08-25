#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 只能说这道题精妙啊...
 * 一开始没读清楚题（经常这样），以为 nextVal 是随意的，结果发现是不超过本次下标
 * 那么也就是说，到达一个新房间时，由于只访问了奇数次，我们必然需要去访问 nextVal 对应位置。
 * 这个位置不会超过 i。再回到 i 时才可能进下一个房间。
 * 而显然我们可以知道：如果当前第一次到达 i，i回溯到 j 之后，j + 1, j + 2, j + 3, ..., i - 1
 * 都需要进行同样的回溯，也即：访问次数从偶数变奇数（1次，从上个节点到达）再变偶数的过程。
 * 所以假设我们可以知道每个节点访问次数从奇数变偶数花费的天数就行
 * 假设这个是 DP
 * 则有 DP[i] = \sum_{j}^{i-1} DP[j] + 2, + 2 表示：1 回溯到 nextVal + 从 i-1 回到 i。j 是第一次回溯的房间
 * 
 * 这个还是太难算了，因为这是 O(n^2) 复杂度的，所以:
 * 前缀和优化: sum_{j}^{i - 1} = S[i] - S[j], DP[i] = S[i + 1] - S[i] 所以有状态转移为：
 * S[i + 1] - S[i] = S[i] - S[j] + 2
 * S[i] =  2 * S[i] - S[j] + 2
 * runtime: 79.10%
 * memory:  40.30%
 */
constexpr int MOD_VAL = 1e9 + 7;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        std::vector<long> prefix_s(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int j = nextVisit[i];
            prefix_s[i + 1] = (prefix_s[i] * 2 - prefix_s[j] + 2 + MOD_VAL) % MOD_VAL;;
        }
        return prefix_s.back();
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}