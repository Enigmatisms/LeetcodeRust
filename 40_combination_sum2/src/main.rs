/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Rust 提交中击败了84.62%的用户
通过测试用例：176 / 176
 */

// 此题的主要实现思路是：由于数组内有重复元素，而输出不能有重复 ---> 将多个重复元素合成为一个处理！
// 其他思路：拿到题首先尝试分析复杂度，设分析的复杂度至少是A，若某一处理算法的复杂度B < A，则可以使用算法进行处理（如本题中进行的sort）
// 与背包问题类似，此题即：是否取 两个二值态。不要遗漏任何一个态

struct Solution;
impl Solution {
    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>>{
        candidates.sort();
        let mut cnt = 1;
        let mut last_val = candidates[0];
        let mut val_map: Vec<(i32, i32)> = Vec::new();
        for x in candidates.iter().skip(1) {
            if *x == last_val {
                cnt += 1;
            } else {
                val_map.push((last_val, cnt));
                cnt = 1;
                last_val = *x;
            }
        }
        val_map.push((last_val, cnt));
        Solution::recursive(& val_map[..], target)
    }

    fn recursive(candidates: &[(i32, i32)], target: i32) -> Vec<Vec<i32>> {
        if target == 0 {
            return vec![Vec::new()];
        }
        if candidates.len() < 1 {
            return Vec::new();
        }
        let (cur_val, cur_cnt) = candidates[0];
        if cur_val > target {
            return Vec::new();
        }
        let mut results: Vec<Vec<i32>> = Vec::new();
        for i in 0..=cur_cnt {
            let now_target = target - i * cur_val;
            if now_target < 0 {
                break;
            }
            let mut result = Solution::recursive(&candidates[1..], target - i * cur_val);
            if result.is_empty() == false {
                for res in result.iter_mut() {
                    res.extend(vec![cur_val; i as usize]);
                }
            }
            results.extend(result);
        }
        results
    }
}

fn main() {
    println!("{:?}", Solution::combination_sum2(vec![10,1,2,7,6,1,5], 8));
}
