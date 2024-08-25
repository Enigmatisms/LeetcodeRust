#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    int num = 0;
    std::cin >> num;
    std::cin.get();
    std::vector<int> vec(num);
    for (int i = 0; i < num; i++)
        std::cin >> vec[i];
    std::cin.get();
    int q1 = 0, q2 = 0;
    std::cin >> q1 >> q2;
    for (int i = 0; i < num; i++) {
        int cur_num = vec[i];
        if (cur_num != q1 && cur_num != q2) continue;
        int next_num = vec[i + 1];
        if ((cur_num == q1 && next_num == q2) || (cur_num == q2 && next_num == q1)) 
            std::cout << "Yes" << std::endl;
        else 
            std::cout << "No" << std::endl;
        break;
    }
    return 0;
}