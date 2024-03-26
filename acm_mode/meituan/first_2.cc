#include <iostream>
#include <sstream>
#include <vector>

int main() {
    int string_len = 0;
    std::string s, t;
    std::cin >> string_len;
    std::cin.get();
    std::cin >> s;
    std::cin.get();
    std::cin >> t;
    std::cin.get();

    int match_num = 0;
    std::vector<int> track;
    for (int i = 0; i < string_len; i++) {
        if (s[i] == t[i]) {
            ++ match_num; 
        } else {
            track.emplace_back(i);
        }
    }
    if (match_num >= string_len - 1) {
        std::cout << match_num << std::endl;
        return 0;
    }
    // 记录未匹配的 s字母以及未匹配的t字母
    // 如果 s 存在某个字母空缺，t正好有，则至少 + 1
    int increment = 0;
    for (size_t i = 0; i < track.size(); i++) {
        int index_i = track[i];
        char s_i = s[index_i], t_i = t[index_i];
        for (size_t j = i + 1; j < track.size(); j++) {
            int index_j = track[j];
            if (t[index_j] == s_i) {
                increment = 1;
                if (s[index_j] == t_i) {
                    std::cout << match_num + 2 << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << match_num + increment << std::endl;
    return 0;
}