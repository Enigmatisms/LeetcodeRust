/**
 * 这道题算是比较有意思的难题，开始我觉得看起来很简单，但实际并不是这么一回事（写了一个小时，写的第一个版本是有问题的，涉及到正反两个方向进行括号匹配）
 * 注意如下一些事项：
 * - 如果没有栈空检查逻辑是不行的。()(() 这样的例子由于后面几个“(”并没有匹配失败，会被算在成功匹配中
 * - 如果最后一长串出现了这样的问题（结果栈不为空），说明可能有过量的"("没有被当做失败匹配
 * - 我一开始的算法中：总假设"("可以完成匹配，也即有足够的")"完成匹配，故重叠的"("并不计入失败（多余的")"才计入失败），那么需要一种方法可以排除多余"("的影响
 * - 就是判断栈是否为空，不为空说明有多余"("，很可能有错误答案覆盖正确答案（所以需要old_max_num来保存一下之前那个正确的答案）
 * - old_max_num的更新：
 *      - 一开始，我只在")"过量时更新（过量说明前面都已经完美匹配完成了，产生了一个最大值了）
 *      - 但这个例子的出现"(())("没考虑到：刚好不过量，没有更新old_max_num又开始了栈非空判定的逻辑，直接错了
 *      - 故栈空或者过量时进行更新
 * TODO: 本题需要使用C++再写一遍，因为Rust的时间测不准，虽然time: 100%/memory: 85%，个人觉得说明不了什么
 */

struct Solution;

impl Solution {
    #[inline]
    fn get_max_interval(stack: Vec<usize>) -> usize {
        let mut max_interval = 0;
        for i in 1..stack.len() {
            max_interval = max_interval.max(stack[i] - stack[i - 1]);
        }
        max_interval - 1
    }

    pub fn longest_valid_parentheses(s: String) -> i32 {
        if s.len() <= 1 {
            return 0;
        }
        let mut stack: Vec<usize> = Vec::new();
        let mut old_max_num = 0;
        let mut max_num = 0;
        let mut front = 65536;
        for (i, x) in s.bytes().enumerate() {
            if x == 40 {
                if stack.is_empty() {
                    old_max_num = max_num;
                }
                stack.push(i);
            } else {
                if let Some(left_id) = stack.pop() {
                    if left_id < front {
                        front = left_id;
                    }
                    let new_step = i - front + 1;
                    if new_step > max_num {
                        max_num = new_step;
                    }
                } else {
                    front = 65536;
                    old_max_num = max_num;
                }
            }
        }
        if stack.is_empty() == false {
            stack.push(s.len());
            max_num = Solution::get_max_interval(stack);
            max_num = max_num.max(old_max_num);
        }
        max_num as i32
    }
}

fn main() {
    // ()(((((()()(((())())))))))())))())())()()(()))(()))()))((()))))(())(()()))((((())()()())(((()((()(())((()())
    let a = String::from("(())(");
    println!("{}", Solution::longest_valid_parentheses(a));
}

