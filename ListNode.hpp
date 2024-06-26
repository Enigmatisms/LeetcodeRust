/**
 * @file ListNode.hpp
 * 
 * @author Qianyue He
 * @brief Utility function for ListNode
 */
#pragma once
#include <vector>
#include <iostream>
#include <chrono>

class TicToc {
private:
    std::chrono::system_clock::time_point tp;
public:
    void tic() {
        tp = std::chrono::system_clock::now();
    }

    double toc() const {
        auto dur = std::chrono::system_clock::now() - tp;
        auto count = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
        return static_cast<double>(count) / 1e3;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    LinkedList(): head(-1), tail(&head), _length(0) {}

    ~LinkedList() {
        // 手动顺序析构
        ListNode* current = head.next;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(int val) {
        tail->next = new ListNode(val, nullptr);
        tail = tail->next;
        ++ _length;
    }

    class iterator {
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = ListNode*;
            using pointer           = ListNode**;  // or also value_type*
            using reference         = ListNode*&;  // or also value_type&


            iterator(pointer ptr): m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() const { return m_ptr; }

            iterator& operator++() {
                if (m_ptr == nullptr) return *this;
                auto ptr = (*m_ptr)->next;
                // 千万注意二重指针取得是什么地址，这里直接写 &ptr 是会炸掉的，ptr 是局部变量
                m_ptr = ptr == nullptr ? nullptr: &((*m_ptr)->next);
                return *this;
            }

            friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };
        private:
            ListNode** m_ptr;
    };

    iterator begin() {
        // implicit conversion
        return &(head.next);
    }

    iterator end() {
        return nullptr;
    }

    int length() const {
        return this->_length;
    }
private:
    ListNode head;
    ListNode* tail;
    int _length;
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
