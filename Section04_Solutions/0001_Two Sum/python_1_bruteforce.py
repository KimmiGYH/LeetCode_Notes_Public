# 1. Two Sum
# Time Complexity: O(n^2)
# Space Complexity: O(1)

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if (nums[j] + nums[i] == target):
                    return [i, j]