#include <iostream>
#include <unordered_set>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cin.ignore();
    int sum = 2015;
    std::unordered_set<char> seen;
    for (char v: line) {
        auto [it, is_new] = seen.emplace(v);
        if (!is_new) continue;
        sum -= int(v);
    }
    std::cout << sum << std::endl;
}
// 64 位输出请用 printf("%lld")