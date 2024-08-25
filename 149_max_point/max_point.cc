#include <cmath>
#include <vector>
#include <numeric> 
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 
 * runtime: 
 * memory:  
 */
class Solution {
public:
    size_t hash(int a, int b){ 
        size_t h = (size_t(a)<<32)+size_t(b); 
        h*=1231231557ull; // "random" uneven integer 
        h^=(h>>32); 
        return h; 
    } 

    int maxPoints(vector<vector<int>>& points) {
        int num_points = points.size();
        std::unordered_map<size_t, short> counter;
        for (int i = 0; i < num_points; i++) {
            for (int j = i + 1; j < num_points; j++) {
                int dx = points[j].front() - points[i].front(),
                    dy = points[j].back() - points[i].back();
                if (dx < 0) {       // make sure dx being positive
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = dy < 0 ? -dy : dy;
                }
                int gcd_val = std::gcd(dx, dy);
                dx /= gcd_val;
                dy /= gcd_val;
                size_t hash_value = hash(dx, dy);
                auto it = counter.find(hash_value);
                if (it != counter.end())
                    it->second ++;
                else
                    counter[hash_value] = 1;
            }
        }
        short max_val = 0;
        for (auto [key, cnt]: counter) {
            max_val = std::max(max_val, cnt);
        }
        printf("Max val: %d, %f\n", max_val, std::sqrt(1.f + 8.f * float(max_val)));
        return (1 + static_cast<int>(std::sqrt(1 + 8 * max_val))) >> 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::vector<int>> testing = {{7,3},{19,19},{-16,3},{13,17},{-18,1},{-18,-17},{13,-3},{3,7},{-11,12},{7,19},{19,-12},{20,-18},{-16,-15},{-10,-15},{-16,-18},{-14,-1},{18,10},{-13,8},{7,-5},{-4,-9},{-11,2},{-9,-9},{-5,-16},{10,14},{-3,4},{1,-20},{2,16},{0,14},{-14,5},{15,-11},{3,11},{11,-10},{-1,-7},{16,7},{1,-11},{-8,-3},{1,-6},{19,7},{3,6},{-1,-2},{7,-3},{-6,-8},{7,1},{-15,12},{-17,9},{19,-9},{1,0},{9,-10},{6,20},{-12,-4},{-16,-17},{14,3},{0,-1},{-18,9},{-15,15},{-3,-15},{-5,20},{15,-14},{9,-17},{10,-14},{-7,-11},{14,9},{1,-1},{15,12},{-5,-1},{-17,-5},{15,-2},{-12,11},{19,-18},{8,7},{-5,-3},{-17,-1},{-18,13},{15,-3},{4,18},{-14,-15},{15,8},{-18,-12},{-15,19},{-9,16},{-9,14},{-12,-14},{-2,-20},{-3,-13},{10,-7},{-2,-10},{9,10},{-1,7},{-17,-6},{-15,20},{5,-17},{6,-6},{-11,-8}};

    int res = sol.maxPoints(testing);
    return 0;
}