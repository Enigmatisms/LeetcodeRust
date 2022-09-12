struct Solution;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        if s.len() <= 1 {
            return 0;
        }
        let m1 = Solution::judge(s.bytes(), 40);
        let mut m2 = Solution::judge(s.bytes().rev(), 41);
        if m1.0 == 0 && m1.1 == 0 {
            return 0;
        }
        m2.0 = s.len() - m2.0 - 1; 
        m2.1 = s.len() - m2.1 - 1; 
        println!("{:?}, {:?}", m1, (m2.1, m2.0));
        (m1.1.min(m2.0) - m1.0.max(m2.1) + 1) as i32
    }

    #[inline]
    fn get_max_interval(stack: Vec<usize>) -> usize {
        let mut max_interval = 0;
        for i in 1..stack.len() {
            max_interval = max_interval.max(stack[i] - stack[i - 1]);
        }
        max_interval
    }

    #[inline]
    fn judge(s: impl Iterator<Item = u8>, left: u8) -> (usize, usize) {
        let mut stack: Vec<usize> = Vec::new();
        let mut old_max_num = 0;
        let mut max_num = 0;
        let (mut s_ptr, mut e_ptr) = (0, 0);
        let mut front = 65536;
        for (i, x) in s.enumerate() {
            if x == left {
                stack.push(i);
            } else {
                if let Some(left_id) = stack.pop() {
                    if left_id < front {
                        front = left_id;
                    }
                    let new_step = i - front + 1;
                    if new_step > max_num {
                        max_num = new_step;
                        s_ptr = front;
                        e_ptr = i;
                    }
                } else {
                    front = 65536;
                }
            }
        }
        (s_ptr, e_ptr)
    }
}

fn main() {
    let mut a = String::from("()(((((()()(((())())))))))())))())())()()(()))(()))()))((()))))(())(()()))((((())()()())(((()((()(())((()())");
    println!("{}", Solution::longest_valid_parentheses(a));
}

