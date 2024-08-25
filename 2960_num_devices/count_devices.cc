#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 快两周没做题... 第一道简单题发现是如此傻逼
 * runtime: 100.00%
 * memory:  55.39%
 */
class Solution {
public:
    int countTestedDevices(const vector<int>& batteryPercentages) const {
        int num_devices = 0;
        for (int battery: batteryPercentages) {
            num_devices += (battery - num_devices) > 0;
        }
        return num_devices;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}