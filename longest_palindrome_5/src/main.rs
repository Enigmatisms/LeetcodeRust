/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.2 MB, 在所有 Rust 提交中击败了48.55%的用户
通过测试用例：180 / 180
解题思路：（1）判定何时开始？（与前一字符或跨一字符相等）（2）双指针“扩散”（3）根据长度判定跳过某些不必要的计算
难点：（1）"aaaa"与"aaa" corner case处理（连续相等）
*/
pub fn longest_palindrome(s: String) -> String{
    let mut final_sptr: usize = 0;
    let mut final_eptr: usize = 0;
    let mut max_len: usize = 0;
    let s_len = s.len();
    let max_id = s_len - 1;
    let char_data = s.as_bytes();
    if max_id == 0 {
        return s;
    }
    let mut i: usize = 1;
    while i <= max_id {
        let c = char_data[i];
        if i > s_len - (max_len >> 1) {
            break;
        }
        let mut sptr: usize = 0;
        let mut eptr: usize = i;
        if c == char_data[i - 1] {           // equals to last (even)
            sptr = i - 1;
            while eptr < max_id && c == char_data[eptr + 1] {
                eptr += 1;
            }
            i = eptr + 1;
        } else if i >= 2 && c == char_data[i - 2] { // equals to n-2 (odd)
            sptr = i - 2;
            i += 1;
        } else {
            i += 1;
            continue;
        }
        while sptr > 0 && eptr < max_id && char_data[sptr - 1] == char_data[eptr + 1] {
            sptr -= 1;
            eptr += 1;
        }
        let new_len = eptr - sptr + 1;
        if new_len > max_len {
            max_len = new_len;
            final_eptr = eptr;
            final_sptr = sptr;
        }
    }
    String::from(&s[final_sptr..=final_eptr])
}


fn main() {
    let test_set = ["abcdefghijk", "abababababababababbbbbabbabbbbbababababa", "badrrdabbadrrda", "ab", "a", "abaabaaba"];
    for s in test_set {
        println!("Start processing...");
        let result = longest_palindrome(String::from(s));
        println!("Palindrome of {} is {}", s, result);
    }
}
