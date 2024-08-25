#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * runtime: 100.00%
 * memory:  7.41%
 */
class HitCounter {
private:
    std::deque<int> hits;
public:
    HitCounter() {}

    void erase(int range_min) {
        if (!hits.empty() && hits.front() <= range_min) {
            auto max_iterator = std::upper_bound(hits.begin(), hits.end(), range_min);
            hits.erase(hits.begin(), max_iterator);
        }
    }
    
    void hit(int timestamp) {
        erase(timestamp - 300);
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        erase(timestamp - 300);
        return hits.size();
    }
};


int main(int argc, char** argv) {

    return 0;
}