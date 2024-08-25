#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题思路大概是这样的：对于一个节点它的最小缺失基因，只会有两个情况
 * （1）这个节点的所有子节点（包括自己）存在为 1 的基因
 * （2）节点的子节点不包含为 1 的基因
 * 那么好办了，为情况（2）的所有节点答案显然是 1
 * 为情况1则只可能是为1节点以及其祖先节点。那么思路就是：
 * - 首先找到 1节点（遍历一遍 nums）。从此节点开始DFS
 * DFS 结果中找到缺失基因。此后当前节点指向 1节点的父节点，注意 DFS 以后的 unordered_set 也要转交给父节点
 * DFS 结束后，重新寻找缺失基因（注意可以从子节点的缺失基因开始枚举）
 * 一直不停，回溯到根。回溯完成以后，返回（注意一开始的 result 全部设为 1），开始时为了方便 DFS
 * 最好通过 unordered_map 建立一个子节点映射表
 * 
 * 我只能说很有趣的题目！
 * runtime: 52.99%
 * memory:  36.75%
 */
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int size = static_cast<int>(parents.size()), one_pos = -1;
        std::vector<int> results(size, 1);
        std::unordered_map<int, std::vector<int>> child_map;
        for (int i = 0; i < size; i++) {
            int par = parents[i], num = nums[i];
            if (num == 1) one_pos = i;
            if (par < 0) continue;
            child_map[par].push_back(i);
        }
        if (one_pos < 0) return results;
        // the position of one is available now
        std::unordered_set<int> genes;
        int cur_node = one_pos, missing_gene = 2;
        while (true) {
            dfs(genes, nums, child_map, cur_node);
            int current_gene_size = static_cast<int>(genes.size()), now_miss = 0;
            for (int i = missing_gene; i <= current_gene_size; i++) {
                if (genes.count(i)) continue;
                now_miss = i;
                break;
            }
            if (!now_miss)
                now_miss = current_gene_size + 1;
            results[cur_node] = now_miss;
            missing_gene      = now_miss;           // the missing gene of a parent will be no less than the child
            cur_node = parents[cur_node];
            if (cur_node < 0) break;
        }
        return results;
    }

    void dfs(
        std::unordered_set<int>& genes, vector<int>& nums, std::unordered_map<int, std::vector<int>>& child_map, int start
    ) {
        std::vector<int> stack = {start};
        while (stack.empty() == false) {
            int cur = stack.back();
            stack.pop_back();
            genes.emplace(nums[cur]);
            for (int child: child_map[cur]) {
                if (genes.count(nums[child])) continue;
                stack.push_back(child);
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}