#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "../ListNode.hpp"

using namespace std;

/**
 * 
 * runtime: 100.00%
 * memory:  15.29%
 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        std::unordered_map<int, Node*> node_map;
        std::vector<Node*> node_stack = {node};
        while (!node_stack.empty()) {
            Node* top_node = node_stack.back();
            node_stack.pop_back();
            node_map[top_node->val] = new Node(top_node->val);
            for (Node* node: top_node->neighbors) {
                if (node_map.count(node->val)) continue;
                node_stack.push_back(node);
            }
        }
        node_stack = {node};
        std::unordered_set<int> accessed;
        while (!node_stack.empty()) {
            Node* top_node = node_stack.back(), *new_node = node_map[top_node->val];
            node_stack.pop_back();
            if (accessed.count(top_node->val)) continue;
            accessed.emplace(top_node->val);
            for (Node* node: top_node->neighbors) {
                new_node->neighbors.push_back(node_map[node->val]);
                if (accessed.count(node->val)) continue;
                node_stack.push_back(node);
            }
        }
        return node_map[node->val];
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}