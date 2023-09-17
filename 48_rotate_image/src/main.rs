struct Solution;

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let half = matrix.len() >> 1;
        for start in 0..half {
            Solution::test_recurse(matrix, start, matrix.len() - (start << 1) - 1);
        }
    }

    // 只能说这个限制，有的时候真的非常不方便
    // 以下代码，忽略swap不能输入两个&mut 就是完全正确的
    #[inline]
    pub fn test_recurse(matrix: &mut Vec<Vec<i32>>, start: usize, length: usize) {
    //     let full_len = start + length;
    //     for i in 0..length {
    //         let idx = start + i;
    //         let rev_idx = full_len - i;
    //         std::mem::swap(&mut matrix[start][idx], &mut matrix[rev_idx][start]);
    //         std::mem::swap(&mut matrix[rev_idx][start], &mut matrix[full_len][rev_idx]);
    //         std::mem::swap(&mut matrix[full_len][rev_idx], &mut matrix[idx][full_len]);
    //     }
    }
}

fn main() {
    println!("Hello, world!");
}
