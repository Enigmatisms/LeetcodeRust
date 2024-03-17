#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 字典树的实现... 先理解字典树是啥吧 我只能说比较简单
 * 理解了意思以后，字典树就是一个... 多叉树
 * runtime: 40.25%
 * memory:  94.10%
 */
class Trie {
public:
    std::unordered_map<int, Trie*> childs;
    bool valid_word;
public:
    Trie(bool valid = false): valid_word(valid) {
        childs.reserve(2);
    }

    void insert(string word) {
        Trie* ptr = this;
        int word_len = word.size() - 1;
        for (int i = 0; i <= word_len; i++) {
            char v = word[i];
            int cidx = v - 'a';
            auto it = ptr->childs.find(cidx);
            if (it != ptr->childs.end()) {
                ptr = it->second;
                if (i == word_len)
                    ptr->valid_word = true;
            } else {
                auto new_node = new Trie(i == word_len);
                ptr->childs.emplace(cidx, new_node);
                ptr = new_node;
            }
        }
    }
    
    bool search(string word) {
        Trie* ptr = this;
        for (char v: word) {
            int cidx = v - 'a';
            auto it = ptr->childs.find(cidx);
            if (it != ptr->childs.end()) {
                ptr = it->second;
            } else {
                return false;
            }
        }
        return ptr->valid_word;
    }
    
    bool startsWith(string prefix) {
        Trie* ptr = this;
        for (char v: prefix) {
            int cidx = v - 'a';
            auto it = ptr->childs.find(cidx);
            if (it != ptr->childs.end()) {
                ptr = it->second;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    return 0;
}