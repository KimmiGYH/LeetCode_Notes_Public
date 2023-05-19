from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def dfs(n, u, path):
            if n == len(path):
                ans.append(path.copy())
                return
            for i in range(u, len(nums)):
                path.append(nums[i])
                dfs(n, i + 1, path)
                path.pop()
        
        for i in range(len(nums) + 1):
            dfs(i, 0, [])
        
        return ans