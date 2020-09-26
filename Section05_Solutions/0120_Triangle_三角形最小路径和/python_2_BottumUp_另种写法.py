from typing import List

data = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return None
        res = triangle[-1]
        for i in reversed(range(len(triangle) - 1)):
            for j in range(len(triangle[i])):
                res[j] = min(res[j], res[j+1]) + triangle[i][j]
        return res[0]


if __name__ == '__main__':
    solution = Solution()
    print(solution.minimumTotal(data)) # 11
