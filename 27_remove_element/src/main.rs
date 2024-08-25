/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Rust 提交中击败了97.74%的用户
通过测试用例：113 / 113
*/

pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut ptr:usize = nums.len();
    if ptr == 0 {
        return 0;
    }
    ptr -= 1;
    let mut i: usize = 0;
    while i <= ptr {
        if nums[i] == val {
            while nums[ptr] == val && ptr > i {
                ptr -= 1;
            }
            if ptr == i {
                return ptr as i32;
            }
            nums.swap(i, ptr);
            ptr -= 1;
        }
        i += 1;
    }
    (ptr + 1) as i32
}

fn main() {
    // let mut a = vec![1, 2, 1, 3, 1, 1, 5];
    let mut a = vec![];
    println!("{}", remove_element(&mut a, 1));
}
