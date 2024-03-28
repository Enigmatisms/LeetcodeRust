#include <exception>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

void a_plus_b_1() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        int v1 = 0, v2 = 0;
        ss >> v1 >> v2;
        std::cout << v1 + v2 << std::endl;
    }
}

void a_plus_b_2() {
    std::string line;
    int num_lines = 0;
    std::cin >> num_lines;
    std::cin.get();
    for (int i = 0; i < num_lines; i++) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int v1 = 0, v2 = 0;
        ss >> v1 >> v2;
        std::cout << v1 + v2 << std::endl;
    }
}

void a_plus_b_3() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int v1 = 0, v2 = 0;
        ss >> v1 >> v2;
        if (v1 == 0 && v2 == 0) return;
        std::cout << v1 + v2 << std::endl;
    }
}

void sum_4() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int num_numbers = 0, result = 0;
        ss >> num_numbers;
        if (!num_numbers) break;
        for (int i = 0; i < num_numbers; i++) {
            int temp = 0;
            ss >> temp;
            result += temp;
        }
        std::cout << result << std::endl;
    }
}

void sum_4_2() {
    std::string line;
    int num_lines = 0;
    std::cin >> num_lines;
    std::cin.get();
    for (int i = 0; i < num_lines; i++) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int num_numbers = 0, result = 0;
        ss >> num_numbers;
        if (!num_numbers) break;
        for (int i = 0; i < num_numbers; i++) {
            int temp = 0;
            ss >> temp;
            result += temp;
        }
        std::cout << result << std::endl;
    }
}

void sum_4_3() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        int num_numbers = 0, result = 0;
        ss >> num_numbers;
        if (!num_numbers) break;
        for (int i = 0; i < num_numbers; i++) {
            int temp = 0;
            ss >> temp;
            result += temp;
        }
        std::cout << result << std::endl;
    }
}


void sum_4_4() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        int result = 0;
        while (ss.eof() == false) {
            int temp;
            ss >> temp;
            result += temp;
        }
        std::cout << result << std::endl;
    }
}

void cin_sort_string_1() {
    int num_words = 0;
    std::cin >> num_words;
    std::cin.get();
    if (num_words) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::vector<std::string> sorted_words(num_words);
        for (int i = 0; i < num_words; i++)
            ss >> sorted_words[i];
        std::sort(sorted_words.begin(), sorted_words.end());
        std::cout << sorted_words[0];
        for (int i = 1; i < num_words; i++)
            std::cout << ' ' << sorted_words[i];
        std::cout << std::endl;
    }
}

void cin_sort_string_2() {
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        std::vector<std::string> sorted_words;
        while (ss.eof() == false) {
            sorted_words.emplace_back();
            ss >> sorted_words.back();
        }
        std::sort(sorted_words.begin(), sorted_words.end());
        std::cout << sorted_words[0];
        for (auto cit = sorted_words.cbegin() + 1; cit != sorted_words.cend(); cit++)
            std::cout << ' ' << *cit;
        std::cout << std::endl;
    }
}

void cin_sort_string_3() {
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        std::vector<std::string> sorted_words;
        std::string word;
        while (std::getline(ss, word, ',')) {
            sorted_words.emplace_back(word);
        }
        std::sort(sorted_words.begin(), sorted_words.end());
        std::cout << sorted_words[0];
        for (auto cit = sorted_words.cbegin() + 1; cit != sorted_words.cend(); cit++)
            std::cout << ',' << *cit;
        std::cout << std::endl;
    }
}



#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
int main(int argc, char** argv) {
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) break;
        std::stringstream ss(line);
        std::vector<std::string> sorted_words;
        std::string word;
        while (std::getline(ss, word, ',')) {
            sorted_words.emplace_back(word);
        }
        std::sort(sorted_words.begin(), sorted_words.end());
        std::cout << sorted_words[0];
        for (auto cit = sorted_words.cbegin() + 1; cit != sorted_words.cend(); cit++)
            std::cout << ',' << *cit;
        std::cout << std::endl;
    }
    return 0;
}
