from typing import List

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        k = k % (m * n)
        flat_ori = [grid[i][j] for i in range(m) for j in range(n)]
        flat_mod = flat_ori[-k:] + flat_ori[:-k]
        return [[flat_mod[i * n + j] for j in range(n)] for i in range(m)]