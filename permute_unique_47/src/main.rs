/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.1 MB, 在所有 Rust 提交中击败了55.17%的用户
通过测试用例：33 / 33
*/

struct Solution;

impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut lut: Vec<(i32, usize)> = Vec::new();
        {
            let mut tmp_lut: [usize; 21] = [0; 21]; 
            for n in nums {
                let id: usize = (n + 10) as usize;
                tmp_lut[id] += 1;
            }
            for i in 0..=20 {
                let val = tmp_lut[i];
                if val > 0 {
                    lut.push((i as i32 - 10, val));
                }
            }
        }
        Solution::recursive(lut, 422).0
    }

    // 递归时不能等于上次使用的数字
    pub fn recursive(mut nums: Vec<(i32, usize)>, last_num: i32) -> (Vec<Vec<i32>>, Vec<(i32, usize)>) {
        let mut results: Vec<Vec<i32>> = Vec::new();
        let num_len = nums.len();
        for i in 0..num_len {
            let pr = nums[i];
            if pr.0 == last_num || pr.1 == 0 {
                continue;
            }
            let mut only_one = true;
            for j in 0..num_len {
                if i == j {
                    continue;
                }
                if nums[j].1 > 0 {
                    only_one = false;
                }
            }
            // 逻辑：如果所有其他数都没有了只剩一个了，那么需要全部使用
            let start = if only_one {pr.1} else {1};
            for max_len in start..=pr.1 {
                nums[i].1 -= start;
                let packed = Solution::recursive(nums, pr.0);
                if packed.0.is_empty() == false {
                    for mut item in packed.0 {
                        item.extend(vec![pr.0; max_len]);
                        results.push(item);
                    }
                } else {
                    results.push(vec![pr.0; max_len]);
                }
                nums = packed.1;
            }
            nums[i].1 += pr.1;
        }
        (results, nums)
    }
}

fn main() {
    let a = vec![1, 1, 2, 3, 4];
    let result = Solution::permute_unique(a);
    println!("len: {}, {:?}", result.len(), result);
}