struct Solution;

impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let mut sum: Option<String> = None;
        for (i, x) in num2.bytes().into_iter().rev().enumerate() {
            let time_digit = Solution::times(&num1, x - 48);
            if let Some(inner_sum) = sum {
                sum = Some(Solution::move_add_strings(time_digit, inner_sum, i));
            } else {
                sum = Some(time_digit);
            }
        }
        let res = sum.unwrap();
        for x in res.as_bytes().iter() {
            if *x > 48 {
                return res;
            }
        }
        String::from("0")
    }

    pub fn times(num: &String, digit: u8) -> String {
        let mut carry = 0;
        let mut result: Vec<u8> = Vec::new();
        for x in num.as_bytes().iter().rev() {
            let res = (x - 48) * digit + carry;
            carry = res / 10;
            result.push(res - carry * 10 + 48);    
        }
        if carry > 0 {
            result.push(carry + 48);
        }
        result.reverse();
        String::from_utf8(result).unwrap()
    }

    pub fn move_add_strings(higher: String, lower: String, mv: usize) -> String {
        let mut result: Vec<u8> = Vec::new();
        let (remain_len, high_len) = (higher.len() + mv - lower.len(), higher.len() - 1);
        let high_bytes = higher.as_bytes();
        for x in lower.bytes().into_iter().rev().take(mv) {
            result.push(x);
        }
        let mut carry: u8 = 0;
        for (i, num) in lower.bytes().into_iter().rev().skip(mv).enumerate() {
            let sum = high_bytes[high_len - i] + num - 96 + carry;
            if sum >= 10 {
                carry = 1;
                result.push(sum + 38);
            } else {
                carry = 0;
                result.push(sum + 48);
            }
        }
        for i in 1..=remain_len {
            let sum = high_bytes[remain_len - i] + carry;
            if sum == 58 {
                result.push(48);
            } else {
                carry = 0;
                result.push(sum);
            }
        }
        if carry == 1 {
            result.push(49);
        }
        result.reverse();
        String::from_utf8(result).unwrap()
    }
}

fn main() {
    // for i in 1..=1 {
    //     println!("{}", i);
    // }
    let a = String::from("7967");
    let b = String::from("7067");
    println!("{}", Solution::multiply(a, b));
}
