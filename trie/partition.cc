#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
    std::vector<int> a = {1, 1, 0, 1, 2, 2, 0, 1, 2, 0, 2, 1, 0, 0, 2, 1, 0, 2, 1};
    std::stable_partition(a.begin(), a.end(), [](int v){ return v <= 1;});
    for (int v: a) {
        printf("%d\n", v);
    }
    return 0;
}