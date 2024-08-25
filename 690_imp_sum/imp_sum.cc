#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 顶级简单题
 * runtime: 93.06%
 * memory:  63.20%
 */

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int num_emp = employees.size();
        std::unordered_map<int, Employee*> mapping;
        mapping.reserve(num_emp);
        for (int i = 0; i < num_emp; i++) {
            Employee* emp = employees[i];
            mapping.emplace(emp->id, emp);
        }
        std::vector<Employee*> stack = {mapping[id]};
        int imp_sum = 0;
        while (stack.empty() == false) {
            auto top = stack.back();
            stack.pop_back();
            imp_sum += top->importance;
            for (int sub: top->subordinates) {
                stack.emplace_back(mapping[sub]);
            }
        }
        return imp_sum;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}