#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char** argv) {
    int num_pulls = 0, num_man = 0;
    std::cin >> num_pulls >> num_man;
    std::vector<int> pulls(num_pulls);
    std::vector<std::priority_queue<uint8_t>> man(num_man); 

    std::string line;
    std::cin >> line;
    int man_id = 0;
    for (int i = 0; i < num_pulls; i++) {
        std::cin >> man_id;
        man[man_id - 1].push('I' - line[i]);
    }
    man[man_id - 1].push(9);                    // 最后一位获得 S
    for (auto& queue: man) {
        if (queue.top() == 9) {
            std::cout << 'S';
            queue.pop();
        }
        while (queue.empty() == false) {
            int val = queue.top();
            queue.pop();
            std::cout << char('I' - val);
        }
        std::cout << std::endl;
    }
    return 0;
}