 #include <iostream>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 /**
  * 
  * runtime: 
  * memory:  
  */
 class Solution {
 public:
    int maxProduct(vector<int>& nums) {
        bool has_positive = false;
        int max_prod = -10, positive = 1, negative = 1;
        for (int num: nums) {
            if (!has_positive)
                max_prod = std::max(max_prod, num);
            if (num) {
                if (num > 0) {
                    has_positive = true;
                    positive *= num;
                    if (negative < 0)
                        negative *= num;
                } else {
                    if (negative < 0) {
                        positive = std::max(positive, negative * num);
                        max_prod = std::max(max_prod, positive);
                        negative = num;
                        has_positive = true;
                    } else {
                        negative = positive * num;
                        if (has_positive) max_prod = std::max(max_prod, positive);
                        positive = 1;
                    }
                }
            } else {
                if (has_positive) max_prod = std::max(max_prod, positive);
                positive = 1;
                negative = 1;
            }
        }
        if (!has_positive) return max_prod;
        return std::max(max_prod, positive);
    }
 };
 
 int main(int argc, char** argv) {
    Solution sol;
    
    return 0;
 }