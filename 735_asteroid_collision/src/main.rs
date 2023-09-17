/*
执行用时：0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗：2.1 MB, 在所有 Rust 提交中击败了100.00%的用户
通过测试用例：275 / 275
*/

struct Solution;

impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut leftwards: Vec<i32> = Vec::new();
        let mut results: Vec<i32> = Vec::new();
        for ast in asteroids.into_iter() {
            if ast < 0 {
                let abs_ast = -ast;
                let mut survived = true;
                while leftwards.is_empty() == false {
                    let collision = *leftwards.last().unwrap();
                    if abs_ast > collision {
                        leftwards.pop();
                    } else if abs_ast < collision {
                        survived = false;
                        break;
                    } else {
                        leftwards.pop();
                        survived = false;
                        break;
                    }
                }
                if survived == true {
                    results.push(ast);
                }
            } else {
                leftwards.push(ast);
            }
        }
        results.extend(leftwards.iter());
        return results;
    }
}

fn main() {
    let asteroids = vec![10,2,-5, 4, 6, 2, -8, 2, -3, 4, -3, -5];
    println!("{:?}", Solution::asteroid_collision(asteroids));
}
