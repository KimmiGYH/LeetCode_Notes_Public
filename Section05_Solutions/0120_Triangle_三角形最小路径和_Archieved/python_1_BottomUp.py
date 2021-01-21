from typing import List

data = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
        return triangle[0][0]


if __name__ == '__main__':
    solution = Solution()
    print(solution.minimumTotal(data)) # 11
