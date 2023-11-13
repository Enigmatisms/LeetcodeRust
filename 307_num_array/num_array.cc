#include <vector>
#include <map>

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
 */