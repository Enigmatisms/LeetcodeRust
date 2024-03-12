#include <random>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "../ListNode.hpp"

using namespace std;

std::vector<std::vector<int>> generateRandomMatrix(int row, int col) {
    // 创建一个随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    // 定义整数分布范围
    std::uniform_int_distribution<> dis(1, 100); // 可以根据需要调整范围

    // 生成随机矩阵
    std::vector<std::vector<int>> matrix(row, std::vector<int>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = dis(gen); // 生成随机整数
        }
    }
    return matrix;
}

/**
 * runtime: 99.16%
 * memory:  27.96%
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        std::vector<std::vector<int>> result(col, std::vector<int>(row, 0));
        for (size_t i = 0; i < row; i++) {
            const auto& origin_row = matrix[i];
            for (size_t j = 0; j < col; j++) {
                result[j][i] = origin_row[j];
            }
        }
        return result;
    }

    // 分块转置(只针对大小为 16 的倍数的矩阵，用于 benchmarking)
    vector<vector<int>> transpose_patch(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        size_t rpatch = row >> 4, cpatch = col >> 4;
        std::vector<std::vector<int>> result(col, std::vector<int>(row, 0));
        for (size_t r = 0; r < rpatch; r++) {
            size_t rbase = r << 4;
            for (size_t c = 0; c < cpatch; c++) {
                size_t cbase = c << 4;
                for (size_t i = 0; i < 16; i++) {
                    const auto& row = matrix[rbase + i];
                    for (size_t j = 0; j < 16; j++) {
                        result[cbase + j][rbase + i] = row[cbase + j];
                    }
                }
            }
        }
        return result;
    }   
};

int main(int argc, char** argv) {
    Solution sol;
    TicToc timer;
    int size = 4000, test_size = 100;
    if (argc >= 3) {
        test_size = atoi(argv[2]);
    }
    if (argc >= 2) {
        size = atoi(argv[1]);
    }
    double total_origin = 0, total_patch = 0;
    for (int i = 0; i < test_size; i++) {
        auto matrix1 = generateRandomMatrix(size, size);
        auto matrix2 = matrix1;
        timer.tic();
        auto result1 = sol.transpose(matrix1);
        total_origin += timer.toc(); 

        timer.tic();
        auto result2 = sol.transpose(matrix2);
        total_patch += timer.toc(); 
        printf("%04d/%04d\n", i + 1, test_size);
    }
    printf("Benchmark: %.5lf ms and %.5lf ms\n", total_origin / test_size, total_patch / test_size);
    return 0;
}