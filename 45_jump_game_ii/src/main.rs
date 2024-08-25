struct Solution;

impl Solution {
    pub fn jump2(nums: Vec<i32>) -> i32 {
        // TODO: 不考虑1的情况
        let max_len = nums.len() - 1;
        if max_len == 0 {
            return 0;
        }
        let mut min_steps: Vec<i16> = vec![0; nums.len()];
        for (i, max_step) in nums.into_iter().rev().enumerate().skip(1) {
            if max_step == 0 {
                min_steps[max_len - i] = 10002;
                continue;
            }
            let mut min_step = 10002;
            let base = max_len - i;
            for j in 1..=max_step {
                let id = base + j as usize;
                if id > max_len {
                    break;
                }
                min_step = min_step.min(min_steps[id]);
            }
            min_steps[base] = min_step + 1;
        }
        min_steps[0] as i32
    }

    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut max_id = 0;
        let mut steps = 0;
        let max_len = nums.len() - 1;
        if max_len == 0 {
            return 0;
        }
        loop {
            let cur_step = nums[max_id];
            if max_id + cur_step as usize >= max_len {
                return steps + 1;
            }
            let old_id = max_id;
            let mut max_steps = 0;
            for step in 1..=cur_step {
                let next_step = nums[old_id + step as usize] + step;
                if next_step > max_steps {
                    max_steps = next_step;
                    max_id = old_id + step as usize;
                }
            }
            steps += 1;
        }
    }
}

fn main() {
    // println!("Hello, world!");
    let vec: Vec<i32> = vec![5,2,0,1,4];
    println!("{}", Solution::jump(vec));
}
