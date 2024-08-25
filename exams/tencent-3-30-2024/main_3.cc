#include <iostream>
#include <vector>
#include <algorithm>

int weird_scores(std::vector<std::vector<int>>& stu_probs, std::vector<int>& a_difficulity, int n, int k, int num_stu) {
    int weird_stu = 0;
    for (auto& stu: stu_probs) {        // 遍历所有学生
        // 需要二分查找吧，否则复杂度过不去
        // 第二个挺好判断的，第一个略麻烦一些
        // 先判断第二个条件, 相邻题目分数差大于 500
        int num_prob = stu.size(), cnt = 0;
        for (int i = 1; i < num_prob; i++) {
            int diff_2 = a_difficulity[stu[i] - 1], diff_1 = a_difficulity[stu[i - 1] - 1];         // 注意下标从 1开始，要减一
            cnt += std::abs(diff_2 - diff_1) >= 500;
        }
        if (cnt >= k) {
            ++ weird_stu;
            continue;
        }
        // 第一个条件，需要先按题号 sort 一下，方便查找（题号越大，难度越高）
        // sort... 复杂度可能有点高啊
        std::sort(stu.begin(), stu.end());
        for (int i = num_prob - 1; i >= 0; i--) {       // 从大向小搜
            int diff = a_difficulity[stu[i] - 1] - 500;     // 本题的难度 - 500
            // 题号大于等于 ub + 1 的题难度一定超过 x - 500，不用管，所以 题号为 ub 是最大需要考虑的（可能为0，x - 500 难度的题可能不存在）
            int ub = std::upper_bound(a_difficulity.begin(), a_difficulity.end(), diff) - a_difficulity.begin();
            if (ub == 0) continue;
            int num = std::upper_bound(stu.begin(), stu.end(), ub) - stu.begin();
            if (num != ub) {    // 小于 x - 500 的题不是全部做出来了（小于应该插入的位置）
                ++ weird_stu;
                break;
            }
        }   
    }
    return weird_stu;
}

int main(int argc, char** argv) {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::cin.get();
    std::vector<int> a_difficulity(n);
    for (int i = 0; i < n; i++)
        std::cin >> a_difficulity[i];
    int num_stu = 0;
    std::cin >> num_stu;
    std::cin.get();
    std::vector<std::vector<int>> stu_probs(num_stu);
    for (int i = 0; i < num_stu; i++) {
        int num_prob = 0;
        std::cin >> num_prob;
        std::cin.get();
        std::vector<int>& probs = stu_probs[i];
        probs.resize(num_prob);
        // for (int j = 0, prob_id = 0; j < num_prob; j++) {
        //     std::cin >> prob_id;
        //     probs[j] = a_difficulity[prob_id - 1];  // 直接转换为难度值，省去后续映射表的麻烦
        // }
        for (int j = 0; j < num_prob; j++)
            std::cin >> probs[j];
        std::cin.get();
        // 不能先 sort
    }
    std::cout << weird_scores(stu_probs, a_difficulity, n, k, num_stu) << std::endl;
    return 0;
}