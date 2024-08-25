#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Member {
    std::vector<Member*> childs;
    std::string name;
    bool alive;

    Member(std::string&& n): name(std::move(n)), alive(true) {
        childs.reserve(2);
    }
};

/**
 * 秒杀水平... 垃圾题，就是考你能不能看懂，看懂了思路一下就有
 * 树 + Hash
 * runtime: 100.00%
 * memory:  33.33%
 */
class ThroneInheritance {
private:
    std::unordered_map<string, Member*> all_members;
    Member king;
public:
    ThroneInheritance(string kingName): king(std::move(kingName)) {
        all_members[king.name] = &king;
    }
    
    void birth(string parentName, string childName) {
        Member* new_child = new Member(std::move(childName));
        all_members[new_child->name] = new_child;
        all_members[parentName]->childs.emplace_back(std::move(new_child));
    }
    
    void death(string name) {
        all_members[name]->alive = false;
    }
    
    vector<string> getInheritanceOrder() {
        std::vector<string> results;
        std::vector<Member*> stack = {&king};
        while (stack.empty() == false) {
            Member* top = stack.back();
            stack.pop_back();
            if (top->alive)
                results.push_back(top->name);
            for (auto rit = top->childs.crbegin(); rit != top->childs.crend(); rit++) {
                auto ptr = *rit;
                if (!ptr) continue;
                stack.push_back(ptr);
            }
        }
        return results;
    }
};

int main(int argc, char** argv) {

    return 0;
}