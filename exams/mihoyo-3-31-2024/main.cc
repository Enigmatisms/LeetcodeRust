#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

long long solve(std::unordered_map<int, std::priority_queue<int>>& map_queue, int target) {
    long long max_score = 0;
    for (auto& [_, queue]: map_queue) {
        max_score += queue.top();
        queue.pop();
    }
    if (target == 0) return max_score;
    std::priority_queue<int> new_queue;
    for (auto& [_, queue]: map_queue) {
        while (queue.empty() == false) {
            new_queue.push(queue.top());
            queue.pop();
        }
    }
    for (int i = 0; i < target; i++) {
        max_score += new_queue.top();
        new_queue.pop();
    }
    return max_score;
}

int main(int argc, char** argv) {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;
    std::cin.get();
    std::unordered_map<int, std::priority_queue<int>> map_queue;
    map_queue.reserve(m);
    for (int i = 0; i < n; i++) {
        int score = 0, artifact_type = 0;
        std::cin >> score >> artifact_type;
        std::cin.get();
        map_queue[artifact_type].push(score);
    }
    std::cout << solve(map_queue, k - m) << std::endl;
    return 0;
}