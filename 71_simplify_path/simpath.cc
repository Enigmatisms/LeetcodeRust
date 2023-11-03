#include <iostream>
#include <vector>
#include <sstream>

/**
 * 只能说，求求看清楚题...
 * 题目里说了 ... 以及 xx.., .x 等 这样的串被看作是文件名，没看到，以为不会出现，结果设计出来的方法
 * 完全没有考虑如上情况... 导致写这么一道简单题花了40min，是不是脑瘫啊
 * runtime: 94.71%
 * memory:  73.69%
 */

class Solution {
public:
    std::string simplifyPath(std::string path) const {
        std::vector<std::string> directories;
        size_t dir_start = 0;
        for (size_t i = 0; i < path.length(); i++) {
            char path_v = path[i];
            if (path_v == '/') {
                size_t diff = i - dir_start;
                if (diff > 1) {
                    directories.emplace_back(path.begin() + dir_start + 1, path.begin() + i);
                    dir_start = i;
                } else if (diff == 1) {   // otherwise, length 1 and 0 means nothing
                    dir_start = i;
                }
            } else if (path_v == '.') {
                i++;
                for (; i < path.length(); i++)
                    if (path[i] == '/') break;
                size_t diff = i - dir_start - 1;
                if (diff <= 2) {
                    if (diff == 2 && path[dir_start + 2] == '.') {
                        if (directories.empty() == false)
                            directories.pop_back();
                        dir_start = i;
                    } else {
                        if (diff != 1)
                            directories.emplace_back(path.begin() + dir_start + 1, path.begin() + i);
                    }
                } else
                    directories.emplace_back(path.begin()+ dir_start + 1, path.begin() + i);
                dir_start = i;
            }
        }
        if (path.length() - dir_start > 1)
            directories.emplace_back(path.begin()+ dir_start + 1, path.end());
        std::stringstream ss;
        ss << "/";
        int num_dir = static_cast<int>(directories.size()) - 1;
        for (int i = 0; i < num_dir; i++) {
            ss << directories[i];
            ss << "/";
        }
        if (directories.empty() == false) ss << directories.back();
        return ss.str();
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests{
        "/home/", "/../", "/home//foo/", "/a/./b/../../c/", "/", "//a/b/c/d/..//../././/./d/../d/./../c/d/../d/", 
        "/.../.a.b.c/.././.a/..../../.b.c/./.a//", "/.../hello../world/hello..world/../..ds...//", "/hello../world"
    };
    for (std::string v: tests) {
        std::cout << sol.simplifyPath(v) << std::endl;
    }
    return 0;
}