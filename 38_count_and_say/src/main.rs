/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Rust 提交中击败了85.00%的用户
通过测试用例：30 / 30
*/
struct Solution;

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n > 2 {
            let last_str = Solution::count_and_say(n - 1);
            let mut last_ch = last_str.as_bytes()[0];
            let mut cnt = 1;
            let mut result = String::from("");
            for x in last_str.bytes().into_iter().skip(1) {
                if x == last_ch {
                    cnt += 1;
                } else {
                    result.push_str(&format!("{}{}", cnt, last_ch - 48));
                    last_ch = x;
                    cnt = 1;
                }
            }
            result.push_str(&format!("{}{}", cnt, last_ch - 48));
            result
        } else if n == 2 {
            String::from("11")
        } else {
            String::from("1")
        }
    }
}

fn main() {
    println!("{}", Solution::count_and_say(6));
}
