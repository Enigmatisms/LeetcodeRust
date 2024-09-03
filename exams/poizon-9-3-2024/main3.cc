#include <iostream>
#include <vector>
#include <deque>
#include <array>

// 炸 弹 人！笑死

struct PathState {      // 哥们怎么像在写光追
    int r, c;
    int bombs;          // 剩余的炸弹数量
    int cost;           // 到达这个点还剩余的步数

    PathState(int row, int col, int bbs, int c): 
        r(row), c(col), bombs(bbs), cost(c) {}
};

using Bools = std::vector<std::array<bool, 4>>;
const std::vector<std::pair<int, int>> DIRS = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

// 真就 path tracing 呗
int min_step_bfs_path_tracing(const std::vector<std::string>& map, int sr, int sc, int rows, int cols) {
    std::vector<Bools> visits(rows, Bools(cols, {false, false, false, false}));
    std::deque<PathState> states;
    states.emplace_back(sr, sc, 3, 0);
    visits[sr][sc] = {true, true, true, true};           // 出发点没有必要回去了
    int num_step = 114514;
    while (!states.empty()) {
        PathState state = states.front();
        states.pop_front();
        if (map[state.r][state.c] == '*') {
            num_step = std::min(num_step, state.cost);
            continue;
        }
        // printf("[%d, %d, bombs: %d cost: %d]\n", state.r, state.c, state.bombs, state.cost);
        for (auto [r_dir, c_dir]: DIRS) {
            int r = state.r + r_dir,
                c = state.c + c_dir;
            if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
            char map_pos = map[r][c];
            if ((map_pos == '.' || map_pos == '*') && visits[r][c][state.bombs] == false) {       // 直接走
                visits[r][c][state.bombs] = true;
                states.emplace_back(r, c, state.bombs, state.cost + 1);
            } else if (map_pos == 'W' && state.bombs > 0 && visits[r][c][state.bombs - 1] == false){
                visits[r][c][state.bombs - 1] = true;
                states.emplace_back(r, c, state.bombs - 1, state.cost + 2);      // 炸弹移动算2步
            }
        }
    }
    return num_step < 114514 ? num_step : -1;
}


int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    std::cin.ignore();
    std::vector<std::string> map(rows);
    int sr, sc;
    for (int i = 0; i < rows; i++) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == 'B') {
                sr = i;
                sc = j;
            }
        }
        map[i] = line;
    }
    std::cout << min_step_bfs_path_tracing(map, sr, sc, rows, cols) << std::endl;
    return 0;
}
// 64 位输出请用 printf("%lld")