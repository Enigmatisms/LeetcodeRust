/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Rust 提交中击败了84.31%的用户
通过测试用例：265 / 265
*/

pub fn next_permutation(nums: &mut Vec<i32>) {
    let mut max_ptr = nums.len() - 1;
    let num_len = nums.len();
    if max_ptr == 0 {
        return;
    }
    let mut this_val = *nums.last().unwrap();
    while max_ptr > 0 {
        let prev_val = nums[max_ptr - 1];
        if this_val <= prev_val {
            this_val = prev_val;
            max_ptr -= 1;
        } else {
            this_val = prev_val;
            break;
        }
    }
    if max_ptr == 0 {
        nums.reverse();
    } else {
        let mut min_pos = 0;
        let mut min_val = 1001;
        for i in max_ptr..num_len {
            let cur_num = nums[i];
            if cur_num > this_val && cur_num < min_val{
                min_val = cur_num;
                min_pos = i;
            }
        }
        nums.swap(max_ptr - 1, min_pos);
        let slice = &mut nums[max_ptr..];
        slice.sort();
    }
}

fn main() {
    let mut a = vec![5, 10, 9, 8, 7, 6, 2, 2, 3, 2, 1];
    next_permutation(&mut a);
    println!("Permutation: {:?}", &a);
}
