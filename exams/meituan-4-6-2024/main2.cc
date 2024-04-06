#include <iostream>

bool is_real(const std::string& str) {
    int s_size = str.size(), i_pos = 0, num = 0;
    for (; i_pos < s_size; i_pos++) 
        if (str[i_pos] == 'i') break;
    if (i_pos >= s_size) return true;
    for (int i = i_pos - 1; i >= 0; i--) {
        if (str[i] < '0') {
            if (i + 1 < i_pos) {
                int num = atoi(str.substr(i + 1, i_pos - i - 1).c_str());
                return num == 0;
            } else return false;
        }
    }
    num = atoi(str.substr(0, i_pos).c_str());
    return num == 0;
}

int main(int argc, char** argv) {
    int num_str = 0, num_comp = 0;
    std::cin >> num_str;
    for (int i = 0; i < num_str; i++) {
        std::string str;
        std::cin >> str;
        num_comp += is_real(str);
    }
    std::cout << num_comp << std::endl;
    return 0;
}