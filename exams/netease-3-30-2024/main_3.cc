#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 
 * runtime: 
 * memory:  
 */
void solve(std::vector<int>& mobs, std::vector<int>& bosses, int num_mob, int num_boss) {
    
}

int main(int argc, char** argv) {
    int init_p = 0, num_mob = 0, num_boss = 0;
    std::cin >> init_p >> num_mob >> num_boss;
    std::cin.get();
    std::vector<int> mob_rooms(num_mob), boss_rooms(num_boss), prefix_mob(num_mob);
    for (int i = 0; i < num_mob; i++) {
        std::cin >> mob_rooms[i];
        std::cin.get();
    }
    for (int i = 0; i < num_boss; i++) {
        std::cin >> boss_rooms[i];
        std::cin.get();
    }
    solve(mob_rooms, boss_rooms, num_mob, num_boss);
    return 0;
}