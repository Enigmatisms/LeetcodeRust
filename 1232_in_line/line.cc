#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/**
 * 很简单 不愧是简单题
 * runtime: 95.71%
 * memory:  75.47%
 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        int diff_x = coordinates[1][0] - coordinates[0][0],
            diff_y = coordinates[1][1] - coordinates[0][1];
        if (diff_x == 0) {
            int start_x = coordinates[0][0];
            for (size_t i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != start_x) return false;
            }
        } else if (diff_y == 0) {
            int start_y = coordinates[0][1];
            for (size_t i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][1] != start_y) return false;
            }
        } else {
            int gcd_v = gcd(diff_x, diff_y);
            diff_x /= gcd_v;
            diff_y /= gcd_v;
            for (size_t i = 2; i < coordinates.size(); i++) {
                int newd_x = coordinates[i][0] - coordinates[i - 1][0],
                    newd_y = coordinates[i][1] - coordinates[i - 1][1];
                if (newd_x % diff_x > 0 || newd_y % diff_y > 0) return false;
                newd_x /= diff_x;
                newd_y /= diff_y;
                if (newd_x != newd_y) return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}