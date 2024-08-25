#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 双指针法很好想，就是要搞清楚首指针什么时候可以移动
 * 双指针法就是要判定两端指针如何移动。注意，对于子数组问题，
 * 如果移动首指针仍然可以满足条件，才能移动，否则只能移动尾指针
 * 
 * 细节老是写错
 * runtime: 88.83%
 * memory:  33.51%
 */
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;
        long long result_cnt = 0;
        int sptr = 0, eptr = 1, num_digit = nums.size();
        std::unordered_map<int, int> cnts;
        cnts[nums[sptr]] += 1;
        cnts[nums[eptr]] += 1;
        bool new_sptr = true;
        long long cnt = 0;
        for (auto [_, c]: cnts) {
            if (c <= 1) continue;
            cnt += c * (c - 1) >> 1;
        }
        while (eptr < num_digit) {
            if (cnt >= k) {
                if (new_sptr)
                    result_cnt += num_digit - eptr;
                new_sptr = false;
                int s_num = nums[sptr], &s_num_cnt = cnts[s_num];
                if (s_num_cnt <= 1) {
                    new_sptr = true;
                    -- s_num_cnt;
                    ++ sptr;
                } else {                // 判断移动 sptr 是否会对结果产生影响
                    int new_cnt = cnt - s_num_cnt + 1;      // 如果删去这一个，新的 cnt 是此值
                    if (new_cnt >= k) {
                        new_sptr = true;
                        -- s_num_cnt;
                        ++ sptr;
                        cnt = new_cnt;
                    } else {
                        if (++ eptr < num_digit) {
                            int e_num = nums[eptr]; 
                            auto it = cnts.find(e_num);
                            if (it != cnts.end())
                                cnt += it->second;
                            cnts[e_num] += 1;
                        }
                    }
                }
            } else {
                if (++ eptr < num_digit) {
                    int e_num = nums[eptr]; 
                    auto it = cnts.find(e_num);
                    if (it != cnts.end())
                        cnt += it->second;
                    cnts[e_num] += 1;
                }
            }
        }
        return result_cnt;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}