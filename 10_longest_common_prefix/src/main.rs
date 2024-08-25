/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.1 MB, 在所有 Rust 提交中击败了65.32%的用户
通过测试用例：124 / 124
*/
pub fn longest_common_prefix(strs: Vec<String>) -> String {
    let mut eptr:usize = 0;
    let first_str = strs.first().unwrap();
    loop {
        if eptr >= first_str.len() {
            return String::from(&first_str[0..eptr]);
        }
        let c: &str = &first_str[eptr..eptr+1];
        for s in strs.iter().skip(1) {
            if eptr >= s.len() || &s[eptr..eptr+1] != c {
                return String::from(&first_str[0..eptr]);
            }
        }
        eptr += 1;
    }
}

fn main() {
    let a = vec![String::from("abcdefg"), String::from("abcdef"), String::from("abcdefg"), String::from("dabc"), String::from("abcdef")];
    println!("Longest common prefix: {}", longest_common_prefix(a));
}
