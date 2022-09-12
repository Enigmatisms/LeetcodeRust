struct Solution;

impl Solution {
    pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let len = nums.len();
        Solution::permute_recursive(&mut nums[..], len)
    }

    fn permute_recursive(nums: &mut [i32], len: usize) -> Vec<Vec<i32>> {
        if len > 2 {
            let mut results: Vec<Vec<i32>> = Vec::new();
            for i in 0..len {
                nums.swap(0, i);
                let mut result = Solution::permute_recursive(&mut nums[1..], len - 1);
                let now_val = nums[0];
                for vec in result.iter_mut() {
                    vec.push(now_val);
                }
                results.extend(result);
                nums.swap(0, i);
            }
            results
        } else if len == 2 {
            return vec![nums.to_vec(), vec![nums[1], nums[0]]];
        } else {
            return vec![nums.to_vec()];
        }
    }
}


fn main() {
    let a = vec![5, 4, 6, 2];
    let result = Solution::permute(a);
    println!("length: {}, {:?}", result.len(), result);
}
