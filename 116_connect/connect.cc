#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

using namespace std;

/**
 * 
 * runtime: 99.72%
 * memory:  5.05%
 */
class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root; 
        std::vector<Node*> layer = {root};
        while (true) {
            std::vector<Node*> new_layer;
            new_layer.reserve(layer.size() << 1);
            Node* last = layer.front();
            const bool has_next_level = (last->left != nullptr);
            for (size_t i = 1; i < layer.size(); i++) {
                if (has_next_level) {
                    new_layer.push_back(last->left);
                    new_layer.push_back(last->right);
                }
                last->next = layer[i];
                last = last->next;
            }
            if (has_next_level) {
                new_layer.push_back(last->left);
                new_layer.push_back(last->right);
            } else break;
            layer = std::move(new_layer);
        }
        return root;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}