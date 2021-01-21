from typing import List

triangle = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

class Solution:
    def minimum_total(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        d = {i: {} for i in range(-1, n)}
        for i, row in enumerate(triangle):
            for j, v in enumerate(row):
                d[i][j] = max(d[i-1].get(k, 0) for k in [j, j+1]) + v
        return d[n-2][0]


if __name__ == '__main__':
    solution = Solution()
    print(solution.minimum_total(triangle)) # 11
