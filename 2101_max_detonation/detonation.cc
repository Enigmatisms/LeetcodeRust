#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 写了个思路：时间不够了，要做点别的
 * 
 * 感觉像是一个求多个连同分量中的最大连通分量
 * 实际是一个图论问题,DFS,并记录在一个数组中
 * 既然是 DFS，那么就会记录之前访问过的节点
 * 那 DFS 去枚举就好了，虽然估计会有很多重复计算
 * 
 * 注意，本题为有向图。比如第一个例子，引爆右边可以使得左边也炸，但引爆左边右边不炸
 * runtime: 
 * memory:  
 */
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // 这里不给出实现了
    }
};
int main(int argc, char** argv) {
    Solution sol;

    return 0;
}