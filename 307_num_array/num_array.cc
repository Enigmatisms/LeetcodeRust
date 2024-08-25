#include <vector>
#include <map>
#include <iostream>

/**
 * 你妈的被骗了，这道题是线段树。没碰到过，也不搞这个。我只能想到一个用表的方法
 * 这我不去学不太好写。
 * 
 */

class NumArray {
public:
    NumArray(std::vector<int>& nums): local(nums), prefix_sum(nums.size(), 0) {
        int sum = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i - 1] = sum;
            sum += nums[i];
        }
        prefix_sum.back() = sum;
    }

    void update(int index, int val) {
        int old_val = val;
        std::swap(old_val, local[index]);
        auto it = changes.find(index);
        if (it != changes.end()) {
            int res = it->second + (val - old_val);
            if (res == 0)
                changes.erase(it);
            else
                it->second = res;
        } else {
            int delta = val - old_val;
            if (delta) changes.emplace(index, delta);
        }
    }
    
    int sumRange(int left, int right) const {
        int initial_result = prefix_sum[right];
        if (left > 0) initial_result -= prefix_sum[left - 1];
        for (const auto& it: changes) {
            if (it.first < left) continue;
            else if (it.first > right) break;
            initial_result += it.second;
        }
        return initial_result;
    }
private:
    std::vector<int>& local;
    std::vector<int> prefix_sum;
    std::map<int, short> changes;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 * ["NumArray", "sumRange", "update", "sumRange"]
    [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 */

int main() {
    std::vector<int> input{1, 3, 5};
    NumArray arr(input);
    int res = arr.sumRange(0, 2);
    printf("%d\n", res);
    arr.update(1, 2);
    res = arr.sumRange(0, 2);
    printf("%d\n", res);
    return 0;
}