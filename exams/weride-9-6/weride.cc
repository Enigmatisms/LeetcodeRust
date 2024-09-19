/*
给定数组a[0..n-1]和整数m，m个请求，每个请求i包含起点si终点ei，请求a[si..ei]的区间和。现在随意对a安排顺序，使所有请求区间和的和最大，求所有排序下区间和的和的最大值。|a[i]|, n, m <= 1e5, 0 <= si <= ei < n
*/

#include <cassert>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <numeric>

long long max_interval_sum(std::vector<int> array,
                           std::vector<std::pair<int, int>> queries) {
  int size = array.size();
  std::vector<int> access_cnts(array.size(), 0);
  
  for (const auto& [si, ei]: queries) {
      access_cnts[si] ++;
      if (ei < size)
        access_cnts[ei + 1] --;
  }    //O(n)
  std::partial_sum(access_cnts.begin(), access_cnts.end(), access_cnts.begin());
  std::vector<int> cnt_pos;
  for (size_t i = 0; i < array.size(); i++) {
    if (access_cnts[i] == 0) continue;
    cnt_pos.emplace_back(access_cnts[i]);
  }  
  std::sort(cnt_pos.begin(), cnt_pos.end(), std::greater<>()); // O(nlogn)
  std::sort(array.begin(), array.end(), std::greater<>());  // O(nlogn)
  long long result = 0;
  for (size_t i = 0; i < cnt_pos.size(); i++) {
    result += (long long)(cnt_pos[i]) * (long long)(array[i]);
  }  // O(n)
  return result;
}

#define ASSERT(COND, VAL) \
  do { \
    if (auto test_val = COND; test_val != VAL) { \
      std::cout << test_val << " vs " << VAL << std::endl; \
      assert(false); \
    } \
  } while (false)

void test1() {
  ASSERT(max_interval_sum({1, 2, 3}, {{0, 0}}), 3);
  ASSERT(max_interval_sum({1, 2, 3}, {{0, 0}, {1, 1}}), 5);
  ASSERT(max_interval_sum({1, 2, 3}, {{0, 1}, {1, 2}}), 9);
  ASSERT(max_interval_sum({}, {}), 0);
  ASSERT(max_interval_sum({100'000}, std::vector(100'000, std::pair{0, 0})), 10'000'000'000);
  std::cout << "AC" << std::endl;
}

int main() {
  test1();
}
