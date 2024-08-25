#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 这道题的思想是快速排序
 * runtime:
 * memory:
 */
class Solution {
public:
    // 最简单的写法
    int findKth(vector<int>& a, int n, int K) {
        // write code here
        std::nth_element(a.begin(), a.begin() + n - K, a.end());
        return a[n - K];
    }


    void quick_sort(std::vector<int>& a) {
        recursive_sort(a, 0, a.size());
    }

    // 快速排序一定要注意：如果有序（比如选择一个递增数组的首位进行快排），partition 之后，得到的 partition 结果
    // 位置可能与之前一样，故此时要加一。
    void recursive_sort(std::vector<int>& a, int sp, int ep) {
        if (ep <= sp + 2) {
            if (ep == sp + 2) {
                if (a[sp] > a[sp + 1])
                    std::swap(a[sp], a[sp + 1]);
            }
            return;
        }
        int val = a[sp];
        auto mit = std::partition(a.begin() + sp, a.begin() + ep, [val](int num) {
            return num < val;
        });
        int mp = mit - a.begin();
        mp += mp == sp;
        recursive_sort(a, sp, mp);
        recursive_sort(a, mp, ep);
    }

    std::vector<int> merge_sort(const std::vector<int>& vec) {
        return merge_sort_recursive(vec, 0, vec.size());
    }

    std::vector<int> merge_sort_recursive(const std::vector<int>& vec, int sp, int ep) {
        if (ep <= sp + 2) {
            if (ep == sp + 2) {
                if (vec[sp] > vec[sp + 1])
                    return {vec[sp + 1], vec[sp]};
                return {vec[sp], vec[sp + 1]};
            }
            return {vec[sp]};
        }
        int mp = (sp + ep) >> 1;
        auto v1 = merge_sort_recursive(vec, sp, mp);
        auto v2 = merge_sort_recursive(vec, mp, ep);
        std::vector<int> result;
        result.reserve(v1.size() + v2.size());
        size_t ptr1 = 0, ptr2 = 0;
        while (ptr1 < v1.size() && ptr2 < v2.size()) {
            int num1 = v1[ptr1], num2 = v2[ptr2];
            if (num1 <= num2) {
                result.emplace_back(num1);
                ++ ptr1;
            } else {
                result.emplace_back(num2);
                ++ ptr2;
            }
        }
        for (; ptr1 < v1.size(); ++ptr1)
            result.emplace_back(v1[ptr1]);
        for (; ptr2 < v2.size(); ++ptr2)
            result.emplace_back(v2[ptr2]);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> to_sort = {6, 2, 8, 7, 1, 9, 5, 3, 0, 2, 4, 10, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    to_sort = sol.merge_sort(to_sort);
    for (int v: to_sort) {
        printf("%d, ", v);
    }
    printf("\n");
    return 0;
}