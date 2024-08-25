#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

void input_1() {
    std::string line;
    int num_inputs = 0;
    std::cin >> num_inputs;
    for (int i = 0; i < num_inputs; i++) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
}

void input_2() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int a = 0, b = 0;
        ss >> a >> b;
        if (!a && !b) break;
        std::cout << a + b << std::endl;
    }
}

void input_3() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) return;
        std::stringstream ss(line);
        int num_elements = 0;
        ss >> num_elements;
        if (num_elements == 0) return;
        int result = 0;
        for (int i = 0; i < num_elements; i++) {
            int temp = 0;
            ss >> temp;
            result += temp;
        }
        std::cout << result << std::endl;
    }
}

void input_4() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) return;
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> words;
        while (getline(ss, word, ',')) {
            words.emplace_back(word);
        }
        std::sort(words.begin(), words.end());
        std::cout << words[0];
        for (auto it = words.begin() + 1; it != words.end(); it ++) {
            std::cout << "," << *it;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    input_4();
    return 0;
}