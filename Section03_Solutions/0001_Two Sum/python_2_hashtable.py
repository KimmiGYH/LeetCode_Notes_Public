# 1. Two Sum Solution2
# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dct = {}
        for i, n in enumerate(nums):
            if target - n in nums:
                return[dct[target - n], i]
            dct[n] = i