/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.3 MB, 在所有 Rust 提交中击败了52.08%的用户
通过测试用例：9 / 9
*/

struct Solution;

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut stack: Vec<i32> = Vec::new();
        let mut results: Vec<Vec<String>> = Vec::new();
        Solution::recursive(&mut stack, 0, n, &mut results);
        results
    }

    fn recursive(stack: &mut Vec<i32>, now_n: i32, max_n: i32, results: &mut Vec<Vec<String>>) {
        if now_n >= max_n {
            let mut result: Vec<String> = Vec::new();
            for y in stack.iter() {
                let mut tmp = String::from(".".repeat(max_n as usize));
                let col = *y as usize;
                tmp.replace_range(col..col+1, "Q");
                result.push(tmp);
            }
            results.push(result);
            return;
        }
        for row in 0..max_n {
            let mut next_flag = true;
            for (i, qy) in stack.iter().enumerate() {
                if row == *qy {
                    next_flag = false;
                    break;
                }
                let diff = now_n - (i as i32);
                let low_y = qy - diff;
                let up_y = qy + diff;
                if row == low_y || row == up_y {
                    next_flag = false;
                    break;
                }
            }
            if next_flag == false {
                continue;
            }
            stack.push(row);
            Solution::recursive(stack, now_n + 1, max_n, results);
            stack.pop();
        }
    }
}

fn main() {
    println!("Hello, world!");
    Solution::solve_n_queens(8);
}
