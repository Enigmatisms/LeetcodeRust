#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * 挺弱智哈...
 * runtime: 87.96%
 * memory:  75.00%
 */
class FrequencyTracker {
private:
    std::unordered_map<int, int> map;
    std::unordered_map<int, int> freq_map;
public:
    FrequencyTracker() {
        map.reserve(8);
        freq_map.reserve(4);
    }
    
    void add(int number) {
        auto it = map.find(number);
        if (it != map.end()) {
            auto& val = it->second;
            -- freq_map[val];
            ++ freq_map[++ val];
        } else {
            map[number] = 1;
            ++ freq_map[1];
        }
    }
    
    void deleteOne(int number) {
        auto it = map.find(number);
        if (it != map.end()) {
            auto& val = it->second;
            -- freq_map[val];
            if (it->second == 0) {
                map.erase(number);
            } else {
                ++ freq_map[-- val];
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        auto it = freq_map.find(frequency);
        if (it == freq_map.end()) return false;
        return it->second > 0;
    }
};

int main(int argc, char** argv) {

    return 0;
}