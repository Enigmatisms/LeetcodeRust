// 此题解题思路很妙：使用常数级别额外内存，不代表不能原地操作。这里有两个推论：
// 只要数组中有小于等于0的数字，那么必然从1-n数字中缺失了某个正整数（n为数组大小），这个推论很直观
// 利用数组内部值的大小：作为索引修改数组内部符号 --> 全部置为负，最后查找第一个没有被置为负数的值（对应索引 + 1就是缺失的数字）
/*
执行用时：8 ms, 在所有 Rust 提交中击败了97.06%的用户
内存消耗：7 MB, 在所有 Rust 提交中击败了91.18%的用户
通过测试用例：173 / 173
*/
struct Solution;

impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let mut one_in = false;
        for x in nums.iter_mut() {
            if *x <= 0 {
                *x = 1;
            } else if *x == 1 {
                one_in = true;
            }
        }
        if one_in == false {
            return 1;
        }
        let length = nums.len();
        println!("{:?}", nums);
        for i in 0..length {
            let val = nums[i].abs() as usize;
            if val > length {
                continue;
            } else {
                nums[val - 1] = -(nums[val - 1].abs());
            }
        }
        println!("{:?}", nums);
        for (i, x) in nums.iter().enumerate() {
            if *x > 0 {
                return (i + 1) as i32;
            }
        }
        return (length + 1) as i32;
    }
}

fn main() {
    println!("{}", Solution::first_missing_positive(vec![7, 1, -2, -3, -4, 3, 4]));
}
