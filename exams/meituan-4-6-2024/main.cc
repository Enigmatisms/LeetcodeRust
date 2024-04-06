#include <iostream>

int main(int argc, char** argv) {
    std::string str;
    std::cin >> str;
    const std::string reference = "meituan";
    int diff = 0;
    for (int i = 0; i < 7; i++) {
        diff += str[i] != reference[i];
    }
    std::cout << diff << std::endl;
    return 0;
}