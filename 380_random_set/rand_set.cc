#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 
 * runtime: 99.14%
 * memory:  9.14%
 */
class RandomizedSet {
public:
    RandomizedSet(): _ptr(0) {}
    
    bool insert(int val) {
        if (_set.count(val)) return false;
        _set.emplace(val);
        _vec.push_back(val);
        std::swap(_vec[_ptr], _vec.back());
        _ptr++;
        return true;
    }
    
    bool remove(int val) {
        auto it = _set.find(val);
        if (it != _set.end()) {
            _set.erase(it);
            _ptr--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        while (_vec.empty() == false) {
            int rand_num = rand();
            if (rand_num < 0) rand_num = -rand_num;
            rand_num %= _ptr;
            int val = _vec[rand_num];
            if (_set.count(val)) return val;
            std::swap(_vec[rand_num], _vec.back());
            _vec.pop_back();
        }
        return 0;
    }
private:
    std::unordered_set<int> _set;
    std::vector<int> _vec;
    int _ptr;
};

int main(int argc, char** argv) {

    return 0;
}