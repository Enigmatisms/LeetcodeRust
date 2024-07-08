from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 1: return 0

        for i in range(1, length):
            nums[i] += nums[i - 1]

        sum = nums[-1]

        if sum - nums[0] == 0: return 0
        for i in range(1, length):
            if sum - nums[i] == nums[i - 1]: return i
        return -1