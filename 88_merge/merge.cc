#include <vector>
#include <iostream>

/**
 * So easy:
 * runtime: 51.27%
 * memory:  15.42%
 * 
*/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) const {
        for (int i = m - 1; i >= 0; i--)
            nums1[n + i] = nums1[i];
        auto ptr1 = nums1.begin() + n, ptr = nums1.begin();
        auto ptr2 = nums2.cbegin();
        for (; ptr1 != nums1.end() && ptr2 != nums2.cend(); ptr++) {
            if (*ptr1 > *ptr2) {
                *ptr = *ptr2;
                ptr2++;
            } else {
                *ptr = *ptr1;
                ptr1++;
            }
        }
        if (ptr1 == nums1.end()) {
            for (ptr2; ptr2 != nums2.cend(); ptr++, ptr2++)
                *ptr = *ptr2;
        } else {                        // if the second array depletes itself, we just return
            return;
        }
    }
};

int main() {
    std::vector<int> a1{1, 2, 2, 6, 8, 9, 10, 12, 15, 0, 0, 0, 0, 0}, a2{1, 2, 2, 6, 8, 9, 10, 12, 15, 0, 0, 0, 0, 0};
    std::vector<int> b1{1, 2, 3, 4, 5}, b2{1, 10, 12, 16, 18};
    Solution sol;
    sol.merge(a1, a1.size() - b1.size(), b1, b1.size());
    for (int v: a1) {
        printf("%d, ", v);
    }
    printf("(%lu)\n", a1.size());
    sol.merge(a2, a2.size() - b2.size(), b2, b2.size());
    for (int v: a2) {
        printf("%d, ", v);
    }
    printf("(%lu)\n", a1.size());
    return 0;
}