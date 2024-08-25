#include <iostream>
using namespace std;

class Solution {
public:
    void inverse(const std::string& str) {
        int str_len = str.length();
        for (int i = str_len - 1; i >= 0; i--) {
            int ptr = i;
            for (; ptr > -1 && str[ptr] != ' '; --ptr) {;}
            std::cout << str.substr(ptr + 1, i - ptr);
            if (ptr > -1)
                std::cout << " ";
            i = ptr;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution sol;
    int num_line = 0;
    std::cin >> num_line;
    std::cin.get();
    for (int i = 0; i < num_line; i++) {
        std::string str;
        std::getline(std::cin, str);
        sol.inverse(str);
    }
    return 0; 
}