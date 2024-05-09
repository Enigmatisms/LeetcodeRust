#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 小于0 的数输出会是降序的
 * 大于0 则是升序的
 * 则可以直接平方，平方之后合并两个有序数组
 * 复杂度是 O(n + m)，空间复杂度是 O(1)
 * 为什么是 O(1)? 不同的指向：两个指针一个指向非负部分起始，一个是负数部分末尾
 * 
 * 这里我就不写了，思路有了就行
 * runtime: 
 * memory:  
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}