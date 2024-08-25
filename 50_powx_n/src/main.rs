/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Rust 提交中击败了81.25%的用户
通过测试用例：305 / 305
*/

struct Solution;
use std::i32::MIN;
impl Solution {
    pub fn my_pow(mut x: f64, n: i32) -> f64 {
        let mut nu: u32 = n as u32;
        if n == 0 {
            return 1.;
        } else if n == 1 || x == 0. {
            return x;
        } else if n < 0 {
            x = 1. / x;
            nu = if n == MIN {2_147_483_648} else {-n as u32};
        }
        let mut ind: u32 = 1;
        let mut lb = x;
        let mut ls = 0;
        let mut res = 1.;
        while ind > 0 && ind <= nu {
            if ind & nu > 0 {
                for _ in 0..ls {
                    lb = lb * lb;
                }
                ls = 1;
                res *= lb;
            } else {
                ls += 1;
            }
            ind <<= 1;
        }
        res
    }
}

fn main() {
    println!("{}", Solution::my_pow(1.000000000001, -2147483648));
}
