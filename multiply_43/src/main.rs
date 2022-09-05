struct Solution;

impl Solution {
    pub fn multiply(num1: String, num2: String){

    }

    pub fn time(num: &String, digit: u8, mult: usize) -> String {
        let mut carry = 0;
        let mut result: Vec<u8> = vec![0; mult];
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
}

fn main() {
    
}
