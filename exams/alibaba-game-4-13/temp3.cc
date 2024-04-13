#include <iostream>
#include <vector>
using namespace std;

// 这道题不是力扣原题？之前做过啊
class Solution {
public: 
    int find_fuel_station(std::vector<int>& gas, std::vector<int>& cost, int num_stations) const {
        int all_cost = 0, all_gas = 0, max_cost = INT32_MAX, acc_cost = 0, station = 0;
        for (int i = 0; i < num_stations; i++) {
            int cur_gas = gas[i], cur_cost = cost[i];
            acc_cost += cur_gas - cur_cost;
            if (acc_cost < max_cost) {
                max_cost = acc_cost;
                station  = i;
            }
            all_cost += cur_cost;
            all_gas  += cur_gas;
        }
        if (all_gas < all_cost) return -1;
        return (station + 1) % num_stations;
    }
};

int main() {
    Solution sol;
    int num_stations = 0;
    std::cin >> num_stations;
    std::vector<int> gas(num_stations), cost(num_stations);
    for (int i = 0; i < num_stations; i++)
        std::cin >> gas[i];
    for (int i = 0; i < num_stations; i++)
        std::cin >> cost[i];
    std::cout << sol.find_fuel_station(gas, cost, num_stations) << std::endl;
    return 0; 
}