#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Trie {
private:
    std::vector<Trie*> childs;
    int value;
public:
    Trie(): childs(26, nullptr), value(0) {}

    Trie* search_prefix(const std::string& prefix) {
        Trie* ptr = this;
        for (char v: prefix) {
            int index = v - 'a';
            Trie* child = ptr->childs[index];
            if (!child) return nullptr;
            ptr = child;
        }
        return ptr;
    }

    void insert(const std::string& prefix, int value) {
        Trie* ptr = this;
        for (char v: prefix) {
            int index = v - 'a';
            if (!ptr->childs[index]) {
                ptr->childs[index] = new Trie();
            }
            ptr = ptr->childs[index];
        }
        ptr->value = value;
    }

    int self_sum() const {
        int sum = value;
        for (const auto& child: childs) {
            if (!child) continue;
            sum += child->self_sum();
        }
        return sum;
    }
};

/**
 * 需要写一个字典树, easy 秒杀
 * runtime: 100.00%
 * memory:  37.82%
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        dict_tree.insert(key, val);
    }
    
    int sum(string prefix) {
        Trie* node = dict_tree.search_prefix(prefix);
        if (!node) return 0;
        return node->self_sum();
    }
private:
    Trie dict_tree;
};

int main(int argc, char** argv) {

    return 0;
}