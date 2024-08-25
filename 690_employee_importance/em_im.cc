#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 这不就是一个图的深度优先搜索吗，为什么是中等题？
 * runtime: 97.98%
 * memory:  37.88%
 */
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int, Employee*> mapping;
        for (Employee* emp: employees)
            mapping[emp->id] = emp;
        std::vector<Employee*> stack;
        stack.emplace_back(mapping[id]);
        stack.reserve(8);
        int imp = 0;
        while (!stack.empty()) {
            auto emp = stack.back();
            stack.pop_back();
            imp += emp->importance;
            for (int emp_id: emp->subordinates) {
                auto sub_emp = mapping[emp_id];
                if (sub_emp->subordinates.empty())
                    imp += sub_emp->importance;
                else
                    stack.emplace_back(std::move(sub_emp));
            }
        }
        return imp;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}