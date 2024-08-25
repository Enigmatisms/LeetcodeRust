#include <iostream>
#include <vector>
#include <algorithm>

void solve(int row, int col) {
    std::vector<std::string> pos;
    // 八个方向暴力写就行了
    for (int cur_row = row, cur_col = col; --cur_row >= 0 && --cur_col >= 0; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    for (int cur_row = row, cur_col = col; ++cur_row < 8 && --cur_col >= 0; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    for (int cur_row = row, cur_col = col; --cur_row >= 0 && ++cur_col < 8; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    for (int cur_row = row, cur_col = col; ++cur_row < 8 && ++cur_col < 8; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    // 横竖
    for (int cur_row = row; --cur_row >= 0; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(col + '1');
    }
    for (int cur_row = row; ++cur_row < 8; ) {
        pos.emplace_back();
        pos.back().push_back(cur_row + 'a');
        pos.back().push_back(col + '1');
    }
    for (int cur_col = col; --cur_col >= 0; ) {
        pos.emplace_back();
        pos.back().push_back(row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    for (int cur_col = col; ++cur_col < 8; ) {
        pos.emplace_back();
        pos.back().push_back(row + 'a');
        pos.back().push_back(cur_col + '1');
    }
    std::cout << pos.size() << std::endl;
    std::cout << pos[0];
    for (size_t i = 1; i < pos.size(); i++)
        std::cout << ' ' << pos[i];
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::string pos;
    std::cin >> pos;
    int row = pos[0] - 'a', col = pos[1] - '1';
    solve(row, col);
    return 0;
}