/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.1 MB, 在所有 Rust 提交中击败了39.74%的用户
通过测试用例：171 / 171
*/

struct Solution;

impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        Solution::recursive(&candidates[..], target) 
    }

    #[inline]
    fn recursive(candidates: &[i32], target: i32) -> Vec<Vec<i32>> {
        if target > 0 {
            let mut results: Vec<Vec<i32>> = Vec::new();
            for (i, number) in candidates.iter().enumerate() {
                let mut result = Solution::recursive(&candidates[0..=i], target - number);
                if result.is_empty() == false {
                    for res in result.iter_mut() {
                        res.push(*number);
                    }
                    results.extend(result.into_iter());
                }
            }
            return results;
        } else if target < 0 {
            return Vec::new();
        }
        vec![Vec::new()]
    }
}

fn main() {
    println!("{:?}", Solution::combination_sum(vec![2,3,5], 8));
}
