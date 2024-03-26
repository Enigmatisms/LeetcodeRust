#include "./ListNode.hpp"

int main() {
    LinkedList list;

    list.push(1);
    list.push(3);
    list.push(4);
    list.push(2);
    list.push(6);
    list.push(7);
    list.push(8);

    printf("Push completed.\n");

    for (auto it = list.begin(); it != list.end(); ++it) {
        printf("%d->", (*it)->val);
    }
    printf("end\n");

    list.push(9);
    list.push(10);
    for (auto node: list) {
        printf("%d->", node->val);
    }
    printf("end\n");

    return 0;
}