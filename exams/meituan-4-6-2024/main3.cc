#include <iostream>
#include <vector>
#include <algorithm>

void solve(int arr_size, std::vector<long long>& arr1, std::vector<long long>& arr2) {
    // arr_size 是原始 size - 1
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    // 求出删除后的原始数组
    for (int i = arr_size - 1; i >= 1; i --) {
        arr1[i] -= arr1[i - 1];
        arr2[i] -= arr2[i - 1];
    }
    std::vector<long long> recover(arr_size + 1, 0);
    // 通过以上两个数组可以判断缺什么
    int p1 = 0, p2 = 0, ptr = 0;
    while (p1 < arr_size && p2 < arr_size) {
        if (arr1[p1] == arr2[p2]) {
            recover[ptr ++] = arr1[p1];
            ++ p1;
            ++ p2;
        } else {
            if (p1 + 1 < arr_size && arr1[p1 + 1] == arr2[p2]) {
                // 说明缺了 p2 这个位置的一个数字
                recover[ptr ++] = arr1[p1 ++];
                recover[ptr ++] = arr1[p1 ++];  // p1 共移动两个位置
                ++ p2;     
            } else if (p2 + 1 < arr_size && arr2[p2 + 1] == arr1[p1]) {
                // 说明缺了 p2 这个位置的一个数字
                recover[ptr ++] = arr2[p2 ++];
                recover[ptr ++] = arr2[p2 ++];  // p2 共移动两个位置
                ++ p1;      
            }
        }
    }
    if (p1 < arr_size) {
        recover[ptr] = arr1[p1];
    } else if (p2 < arr_size ) {
        recover[ptr] = arr2[p2];
    }
    std::cout << recover[0];
    for (int i = 1; i <= arr_size; i++)
        std::cout << ' ' << recover[i];
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int arr_size = 0;
    std::cin >> arr_size;
    std::vector<long long> prefix_1(arr_size - 1), prefix_2(arr_size - 1);
    for (int i = 0; i < arr_size - 1; i++)
        std::cin >> prefix_1[i];
    for (int i = 0; i < arr_size - 1; i++)
        std::cin >> prefix_2[i];
    solve(arr_size - 1, prefix_1, prefix_2);        
    return 0;
}