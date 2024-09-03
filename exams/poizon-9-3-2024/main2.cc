#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

// 好串：

int max_length_good(const std::string& line, int k) {
    int length = line.length();
    std::unordered_map<char, int> max_cnts;
    for (int i = 0; i < length; ) {
        char c = line[i];
        int spos = i, sptr = i + 1;
        while (true) {
            if (sptr >= length || line[sptr] != c) {
                int diff_len = sptr - spos;
                max_cnts[c] += diff_len / k;
                break;
            }
            sptr ++;
        }
        i = sptr;
    }
    int max_num = 0;
    for (auto [_k, v]: max_cnts) {
        max_num = std::max(max_num, v);
    }
}

int main() {
    int n = 0, k = 0;
    std::string input;
    std::cin >> n >> k;
    std::getline(std::cin, input);
    std::cin.ignore();
    std::cout << max_length_good(input, k) << std::endl;
    return 0;
}
// 64 位输出请用 printf("%lld")