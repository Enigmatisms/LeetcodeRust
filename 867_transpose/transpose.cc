#include <random>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

/**
 * 不能这样实现矩阵。这样实现的矩阵... 内部的内存不是连续的，自然也无法很好应用访存优化
*/

class TicToc {
private:
    chrono::system_clock::time_point tp;
public:
    void tic() {
        tp = chrono::system_clock::now();
    }

    double toc() const {
        auto dur = chrono::system_clock::now() - tp;
        auto count = chrono::duration_cast<chrono::microseconds>(dur).count();
        return static_cast<double>(count) / 1e3;
    }
};

vector<vector<int>> generateRandomMatrix(int row, int col) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> result(col, vector<int>(row, 0));
        for (size_t i = 0; i < row; i++) {
            const auto& origin_row = matrix[i];
            for (size_t j = 0; j < col; j++) {
                result[j][i] = origin_row[j];
            }
        }
        return result;
    }

    vector<vector<int>> transpose_patch(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        size_t rpatch = row >> 4, cpatch = col >> 4;
        vector<vector<int>> result(col, vector<int>(row, 0));
        for (size_t r = 0; r < rpatch; r++) {
            size_t rbase = r << 4;
            for (size_t c = 0; c < cpatch; c++) {
                size_t cbase = c << 4;
                for (size_t i = 0; i < 16; i++) {
                    for (size_t j = 0; j < 16; j++) {
                        result[cbase + j][rbase + i] = matrix[rbase + i][cbase + j];
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