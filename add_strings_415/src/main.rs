struct Solution;

impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let mut result: Vec<u8> = Vec::new();
        let (long_str, short_str) = match num1.len() > num2.len() {
            true => {(num1, num2)},
            false => {(num2, num1)}
        };
        let mut carry: u8 = 0;
        let short_len = short_str.len();
        let long_len = long_str.len() - 1;
        let long_bytes = long_str.as_bytes();
        for (i, num) in short_str.bytes().into_iter().rev().enumerate() {
            let sum = long_bytes[long_len - i] + num - 96 + carry;
            if sum >= 10 {
                carry = 1;
                result.push(sum + 38);
            } else {
                carry = 0;
                result.push(sum + 48);
            }
        }
        for num in long_str.bytes().into_iter().take(long_len + 1 - short_len).rev() {
            let sum = num + carry;
            if carry == 1 {
                if sum == 58 {
                    result.push(48);
                    continue;
                } else {
                    carry = 0;
                }
            }
            result.push(sum);
        }
        if carry == 1 {
            result.push(49);
        }
        result.reverse();
        String::from_utf8(result).unwrap()
    }
}

fn main() {
    let num1 = String::from("456");
    let num2 = String::from("77");
    let result = Solution::add_strings(num1, num2);
    println!("{}", result);
}
