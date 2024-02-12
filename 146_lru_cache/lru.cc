#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 查找常数：哈希表显然
 * 放置有这一问题：如果不存在，直接插入即可，超过范围则可以pop，则双向结构都可以满足
 *      （1）双向队列（deque）（2）双向链表（dlink）
 * 但假设存在，则需要（1）取出对应位置的并放在队列头
 *      由于要求O（1），显然双向队列不行，故只有用双向链表 + 哈希表可以
 * runtime: 
 * memory:  
 */
class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {
       
    }
private:
    
};


int main(int argc, char** argv) {
    LRUCache sol(300);

    return 0;
}