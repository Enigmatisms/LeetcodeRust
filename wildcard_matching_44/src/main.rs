/** 
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Rust 提交中击败了97.18%的用户
通过测试用例：1811 / 1811

这题花了2小时，而且还debug了好几次，主要是考虑非常欠周全：
- s空，p非空逻辑写错了
- 多个*连在一起时，内部出现？的逻辑有问题。开始时将？合并了，但实际上遇到？直接退回到正常处理即可
- p_next 以及 p_ptr计算，这个绕那么久感觉就是脑子不清醒
*/

struct Solution;

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let mut s_ptr: usize = 0;
        let mut p_ptr: usize = 0;
        let (sbytes, pbytes) = (s.as_bytes(), p.as_bytes());
        if p.len() == 0 {
            if s.len() != 0 {
                return false;
            }
            return true;
        } else {
            if s.len() == 0 {
                for x in p.bytes() {
                    if x != 42 {
                        return false;
                    }
                }
                return true;
            }
        }
        let (s_len, p_len) = (s.len() - 1, p.len() - 1);
        let mut stack: Vec<(usize, usize)> = Vec::new();
        while s_ptr <= s_len && p_ptr <= p_len {
            let now_p = pbytes[p_ptr];
            if sbytes[s_ptr] == now_p || now_p == 63 {
                s_ptr += 1;
                p_ptr += 1;
                if p_ptr > p_len && s_ptr <= s_len {
                    match stack.pop() {
                        Some(res) => {
                            s_ptr = res.0;
                            p_ptr = res.1;
                        },
                        None => {return false}
                    };
                }
            } else {
                if now_p == 42 {        // *
                    let old_ptr = p_ptr;
                    let mut p_next: u8 = 0;
                    while p_ptr + 1 <= p_len {
                        p_next = pbytes[p_ptr + 1];
                        if p_next >= 63 {
                            break;
                        }
                        p_ptr += 1;
                    }
                    if p_ptr == p_len {
                        return true;
                    }
                    while s_ptr <= s_len {
                        if sbytes[s_ptr] == p_next || p_next == 63 {
                            break;
                        }
                        s_ptr += 1;
                    }
                    if s_ptr > s_len {
                        return false;
                    }
                    stack.push((s_ptr + 1, old_ptr));
                    p_ptr += 1;
                } else {
                    match stack.pop() {
                        Some(res) => {
                            s_ptr = res.0;
                            p_ptr = res.1;
                        },
                        None => {return false}
                    }
                }
            }
        }
        while p_ptr <= p_len {
            if pbytes[p_ptr] != 42 {
                return false;
            }
            p_ptr += 1;
        }
        return (s_ptr > s_len) && (p_ptr > p_len);
    }
}
fn main() {
    let a = String::from("abbbb");
    let b = String::from("?*b**");
    println!("{}", Solution::is_match(a, b));
}