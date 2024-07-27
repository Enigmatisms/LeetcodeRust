#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 小小单调栈而已，比较简单。
 * runtime: 88.45%
 * memory:  40.02%
 */
class StockSpanner {
private:
    std::vector<std::pair<int, short>> stocks;
    short cnt;
public:
    StockSpanner() noexcept {
        stocks.reserve(16);
        stocks.emplace_back(1e5 + 1, 0);
        cnt = 1;
    }
    
    inline int next(int price) noexcept {
        int back_stock = stocks.back().first, ret = 1;
        if (price >= back_stock) {
            do {
                stocks.pop_back();
                if (stocks.empty()) break;
                back_stock = stocks.back().first;
            } while (price >= back_stock);
            ret = cnt + 1;
            if (!stocks.empty()) {
                ret = cnt - stocks.back().second;
            }
        }
        stocks.emplace_back(price, cnt ++);
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(int argc, char** argv) {
    StockSpanner sol;

    return 0;
}