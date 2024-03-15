#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <typeinfo>

using namespace std;

/**
 * 这道题比 768 还难好吧... 想了很久
 * 解这道题的关键是：有序性，对于同一个分母的元素，选数组第一个值作为分母时一定最小
 * 那么每一次我们确定当前最小的值是 arr[i] / arr[j] 时，我们只需要将 arr[i + 1] / arr[j] 并入考虑即可
 * 也即建立一个优先队列。优先队列的思想是：我保存的值中，任意分母 arr[j]，排在前面的都一定是更小的
 * 删除一个 arr[j] 作为分母（出队）的值，会立刻加入一个新的，比原来的更大的但以同样值作为分母的值
 * runtime: 74.11%
 * memory:  45.54%
 */

struct OrderFunctor {
    bool operator() (const std::pair<int, int>& v1, const std::pair<int, int>& v2) const {
        return v1.first * v2.second > v1.second * v2.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto pred_func = OrderFunctor();
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, OrderFunctor> pque(pred_func);
        std::unordered_map<int, int> mapping;
        int arr_size = arr.size(), first = arr.front();
        mapping[first] = 0;
        for (int i = 1; i < arr_size; i++) {
            int val = arr[i];
            pque.emplace(first,val);
            mapping[val] = i;
        }
        for (int i = 0; i < k; i++) {
            // const auto& ref = pque.top();
            auto [nom, denom] = pque.top();
            std::cout << std::is_same_v<int, decltype(nom)> << std::endl;
            if (i == k - 1)
                return {nom, denom};
            pque.pop();
            int nom_idx = mapping[nom], denom_idx = mapping[denom];
            if (nom_idx + 1 < denom_idx)
                pque.emplace(arr[nom_idx + 1], denom);
        }
        return {0, 0};
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}