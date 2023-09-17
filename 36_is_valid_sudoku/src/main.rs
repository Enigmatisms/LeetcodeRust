/*
执行用时：4 ms, 在所有 Rust 提交中击败了82.61%的用户
内存消耗：2 MB, 在所有 Rust 提交中击败了92.75%的用户
通过测试用例：507 / 507
*/

use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut col_sets = (0..9).map(|_| {HashSet::new()}).collect::<Vec<_>>();
        let mut field_sets = (0..3).map(|_| {HashSet::new()}).collect::<Vec<_>>();
        for (i, row) in board.into_iter().enumerate() {
            if i % 3 == 0 {
                for set in field_sets.iter_mut() {
                    set.clear();
                }
            }
            let mut row_set: HashSet<char> = HashSet::new();
            for (j, ch) in row.into_iter().enumerate() {
                if ch == '.' {
                    continue;
                } else {
                    if row_set.insert(ch) == false || col_sets[j].insert(ch) == false {
                        return false;
                    }
                    if field_sets[j / 3].insert(ch) == false {
                        return false;
                    }
                }
            }
        }
        true
    }
}

fn main() {
    // let arr: Vec<Vec<char>> = 
    // vec![
    //  vec!['8','3','.','.','7','.','.','.','.']
    // ,vec!['6','.','.','1','9','5','.','.','.']
    // ,vec!['.','9','8','.','.','.','.','6','.']
    // ,vec!['8','.','.','.','6','.','.','.','3']
    // ,vec!['4','.','.','8','.','3','.','.','1']
    // ,vec!['7','.','.','.','2','.','.','.','6']
    // ,vec!['.','6','.','.','.','.','2','8','.']
    // ,vec!['.','.','.','4','1','9','.','.','5']
    // ,vec!['.','.','.','.','8','.','.','7','9']
    // ];
    let arr: Vec<Vec<char>> = 
    vec![
     vec!['5','3','.','.','7','.','.','.','.']
    ,vec!['6','.','.','1','9','5','.','.','.']
    ,vec!['.','9','8','.','.','.','.','6','.']
    ,vec!['8','.','.','.','6','.','.','.','3']
    ,vec!['4','.','.','8','.','3','.','.','1']
    ,vec!['7','.','.','.','2','.','.','.','6']
    ,vec!['.','6','.','.','.','.','2','8','.']
    ,vec!['.','.','.','4','1','9','.','.','5']
    ,vec!['.','.','.','.','8','.','.','7','9']
    ];

    println!("{}", Solution::is_valid_sudoku(arr));
}