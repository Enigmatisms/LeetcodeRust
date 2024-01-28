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
 * next 的妙用
 * runtime: 99.37%
 * memory:  99.95%
 */
class Solution {
public:
    // O(1) 内存
    Node* connect(Node* root) {
        if (!root) return root; 
        Node* cur_val = root, *next_first = nullptr, *next_ptr = nullptr;
        while (cur_val) {
            if (cur_val->left) {
                if (next_ptr) {
                    next_ptr->next = cur_val->left;
                    next_ptr = next_ptr->next;
                } else {
                    next_ptr = cur_val->left;
                    next_first = next_ptr;
                }
            }
            if (cur_val->right) {
                if (next_ptr) {
                    next_ptr->next = cur_val->right;
                    next_ptr = next_ptr->next;
                } else {
                    next_ptr = cur_val->right;
                    next_first = next_ptr;
                }
            }
            cur_val = cur_val->next;
            if (cur_val == nullptr) {
                cur_val = next_first;
                next_first = nullptr;
                next_ptr = nullptr;
            }
        }
        return root;
    }

    // simple layer order: 92.13%, 90.89%, O(N) 内存
    Node* connect2(Node* root) {
        if (!root) return root; 
        std::vector<Node*> layer = {root};
        while (layer.empty() == false) {
            std::vector<Node*> new_layer;
            new_layer.reserve(layer.size() << 1);
            Node* last = layer.front();
            const bool has_next_level = (last->left != nullptr);
            for (size_t i = 1; i < layer.size(); i++) {
                if (last->left)  new_layer.push_back(last->left);
                if (last->right) new_layer.push_back(last->right);
                last->next = layer[i];
                last = last->next;
            }
            if (last->left)  new_layer.push_back(last->left);
            if (last->right) new_layer.push_back(last->right);
            layer = std::move(new_layer);
        }
        return root;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}