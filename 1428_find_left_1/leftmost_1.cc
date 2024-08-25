#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};

/**
 * 很简单嘛
 * runtime: 100.00%
 * memory:  66.67%
 */
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        bool success = false;
        int rows = dims[0], cols = dims[1], result = cols - 1;
        for (int i = 0; i < rows; i++) {
            int one_col = binary_search(binaryMatrix, i, result);
            if (one_col >= 0) {
                if (one_col == 0) return 0;
                success = true;
                result  = one_col;
            }
        }
        return success ? result : -1;
    }

    // find the first 1 in a row
    int binary_search(BinaryMatrix &binaryMatrix, int row, int end_col) const {
        if (binaryMatrix.get(row, end_col) == 0) return -1;
        int sptr = 0, eptr = end_col, mptr = 0;
        while (sptr < eptr) {
            mptr = (sptr + eptr) >> 1;
            int val = binaryMatrix.get(row, mptr);
            if (val)
                eptr = mptr;
            else
                sptr = mptr + 1;
        }
        return eptr;
    }
};

int main(int argc, char** argv) {
    Solution sol;

    return 0;
}