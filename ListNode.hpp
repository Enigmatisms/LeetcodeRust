/**
 * @file ListNode.hpp
 * 
 * @author Qianyue He
 * @brief Utility function for ListNode
 */
#pragma once
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    std::vector<int> inorderTraversal() const {
        std::vector<int> results;
        recursive_traversal(this, results);
        return results;
    }
private:
    static void recursive_traversal(const TreeNode* const node, std::vector<int>& vals) {
        if (node->left)
            recursive_traversal(node->left, vals);
        vals.push_back(node->val);
        if (node->right)
            recursive_traversal(node->right, vals);
    }
};

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

bool print_link(ListNode* head, int max_depth = 25) {
    for (int cnt = 0;head && cnt < max_depth;head = head->next, cnt ++) {
        printf("%d", head->val);
        if (head->next)
            printf("->");
        else {
            printf("\n");
            return true;
        }
    }
    printf("(max-depth)\n");
    return false;
}

void create_link_list(const std::vector<int>& vals, std::vector<ListNode>& nodes) {
    nodes.resize(vals.size());
    for (size_t j = 0; j < vals.size(); j++) {
        nodes[j].val = vals[j];
        nodes[j].next = (j + 1 == vals.size()) ? nullptr : &nodes[j + 1];
    }
}
