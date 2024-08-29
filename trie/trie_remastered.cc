#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Trie Remastered
 * 这个数据结构有点重要，但是忘记了
 * 此数据结构用于存储多个有相同前缀的数据
 * 这个版本很慢，为什么？
 * runtime: 5.86%
 * memory:  8.77%
 */
class TrieNode {
public:
    bool valid;
    std::unordered_map<char, TrieNode> data;
public:
    TrieNode(): valid(false) {}

    void insert(const std::string& s, int index) {
        char c = s[index ++];
        auto [it, inserted] = data.emplace(c, TrieNode());
        if (index < s.size())
            it->second.insert(s, index);
        else
            it->second.valid = true;
    }

    const TrieNode* find(char c) const {
        auto it = data.find(c);
        if (it == data.end()) return nullptr;
        return &it->second;
    }

    bool is_valid() const {
        return valid;
    }
};

class Trie {
    TrieNode root;
public:
    void insert(const std::string& s) {
        root.insert(s, 0);
    }

    bool startsWith(const std::string& s) const {
        const TrieNode* ptr = &root;
        for (char c: s) {
            ptr = ptr->find(c);
            if (!ptr) return false; 
        }
        return true;
    }

    bool search(const std::string& s) const {
        const TrieNode* ptr = &root;
        for (char c: s) {
            ptr = ptr->find(c);
            if (!ptr) return false; 
        }
        return ptr->is_valid();
    }
};

int main(int argc, char** argv) {

    return 0;
}