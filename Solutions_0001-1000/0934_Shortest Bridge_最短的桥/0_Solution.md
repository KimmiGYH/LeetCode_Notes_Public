# 934. Shortest Bridge_最短的桥



## 解法：DFS + BFS





1. Use DFS to find one island and color all the nodes as 2 (BLUE).
2. Use BFS to find the shortest path from any nodes with color 2 (BLUE) to any nodes with color 1 (RED).

Time complexity: $O(mn)$

Space complexity: $O(mn)$

