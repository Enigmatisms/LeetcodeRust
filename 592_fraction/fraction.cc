#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 写这种题目真的花一小多小时...搞出一堆bug的你怕不是个傻逼
 * runtime: 100.00%
 * memory:  26.04%
 */
class Solution {
public:
    string fractionAddition(string expression) {
        int length = expression.length(), denom = 1, nom = 0, cur_denom = 0, cur_nom = 0;
        bool is_positive = true, is_denom = false;  
        for (int ptr = 0; ptr < length; ptr++) {
            char cur_char = expression[ptr];
            if (cur_char < '/') {
                denom = lcm_scale(denom, cur_denom, nom, cur_nom);
                if (is_positive) 
                    nom += cur_nom;
                else
                    nom -= cur_nom;
                cur_denom = 0;
                cur_nom   = 0;
                is_denom = false;
                is_positive = cur_char != '-';
            } else if (cur_char > '/') {
                if (is_denom) {
                    cur_denom *= 10;
                    cur_denom += static_cast<int>(cur_char - '0');
                } else {
                    cur_nom *= 10;
                    cur_nom += static_cast<int>(cur_char - '0');
                }
            } else {
                is_denom = true;
            }
        }
        denom = lcm_scale(denom, cur_denom, nom, cur_nom);
        if (is_positive) 
            nom += cur_nom;
        else
            nom -= cur_nom;
        if (nom == 0) return "0/1";
        int gcd_num = gcd(std::abs(nom), denom);
        nom   /= gcd_num;
        denom /= gcd_num;
        return (nom < 0 ? "-" : "") + std::to_string(std::abs(nom)) + "/" + std::to_string(denom);
    }

    static int lcm_scale(int denom, int cur_denom, int& nom, int& cur_nom) {
        if (cur_nom == 0) return 1;
        int gcd_num = gcd(cur_denom, denom), nom_scale = cur_denom / gcd_num;
        nom        *= nom_scale;
        cur_nom    *= denom / gcd_num;
        return denom * nom_scale;
    }

    static int gcd(int a, int b) {
        if (a > b) std::swap(a, b);
        while (true) {
            int res = b % a;
            if (res == 0) return a;
            b = a;
            a = res;
        }
        return 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.fractionAddition("0/1+1/3") << std::endl;
    return 0;
}