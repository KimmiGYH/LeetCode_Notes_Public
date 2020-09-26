# 018/067 Maximum path sum I

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

​     **3**
​    **7** 4
  2 **4** 6
8 5 **9** 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

​                                  75
​                                95 64
​                             17 47 82
​                           18 35 87 10
​                         20 04 82 47 65
​                      19 01 23 75 03 34
​                    88 02 77 73 07 63 67
​                  99 65 04 28 06 16 70 92
​               41 41 26 56 83 40 80 70 33
​             41 48 72 33 47 32 37 16 94 29
​          53 71 44 65 25 43 91 52 97 51 14
​       70 11 33 28 77 73 17 78 39 68 17 57
​     91 71 52 38 17 14 91 43 58 50 27 29 48
   63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

**NOTE:** As there are only 16384 routes, it is possible to solve this problem by trying every route. However, [Problem 67](https://projecteuler.net/problem=67), is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)



-----

解法：

You have such triangle:

```
   3
  7 4
 2 4 6  
8 5 9 3
```

When you move from the bottom to the top, you can calculate the best choices on last iteration. In this case you take the last row `8 5 9 3` and maximize sum in addition to previous line.

Iteration 1: Assume that you are on `last-1` step.

You have line `2 4 6`, let's iterate on it.

**From 2**, you can go to either **8** or 5, so **8** is better (maximize your result from 2) so you calculate first sum 8 + 2 = 10.

**From 4**, you can go to either 5 or **9**, so **9** is better (maximize your result from 4) so you calculate second sum 9 + 4 = 13.

**From 6**, you can go to either **9** or 3, so **9** is better again (maximize your result from 6) so you calculate third sum 9 + 6 = 15.

This is the end of first iteration and you got the line of sums `10 13 15`.

Now you've got triangle of lower dimension:

```
    3
  7  4
10 13 15  
```

Now go on until you get one value, which is exactly 23.

-----

:heart: **Solution 1: Bottom-up solution**

```python
# Project Euler problem #18 Solution2: Bottum-up
# Ans: 1074

'''
def get_data():
    with open('p018_data.txt') as f:
        lines = f.readlines()

    data = []
    for line in lines:
        nested_list = list(map(int, line.split()))
        data.append(nested_list)
    return data
'''

data = [
    [75],
    [95, 64],
    [17, 47, 82],
    [18, 35, 87, 10],
    [20, 4, 82, 47, 65],
    [19, 1, 23, 75, 3, 34],
    [88, 2, 77, 73, 7, 63, 67],
    [99, 65, 4, 28, 6, 16, 70, 92],
    [41, 41, 26, 56, 83, 40, 80, 70, 33],
    [41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
    [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
    [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
    [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
    [63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
    [4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23]
]


def max_path_sum(triangle):
    for row in range(len(triangle)-2, -1, -1):
        for col in range(len(triangle[row])):
            triangle[row][col] += max(triangle[row+1][col], triangle[row+1][col+1])
    return triangle[0][0]


if __name__ == '__main__':
    print(max_path_sum(data))

```



**Solution 2: Top-down solution**

```python
# Project Euler problem #18 Solution2: Top-down
# Ans: 1074

def max_sum_path(filename):
    lines = open(filename).read().split('\n')
    ans_row = [int(lines[0])]
    temp_row = list()
    lines = lines[1:]
    for line in lines:
        nums = line.split(' ')
        for n in range(len(nums)):
            if n == 0:
                temp_row.append(int(nums[n]) + ans_row[n])
            elif n == len(nums) - 1:
                temp_row.append(int(nums[n]) + ans_row[n-1])
            else:
                temp_row.append(int(nums[n]) + max(ans_row[n], ans_row[n-1]))
        ans_row = temp_row.copy()
        temp_row.clear()
    return max(ans_row)


if __name__ == "__main__":
    print(max_sum_path('p018_data.txt'))
```



**Solution3-1 (Top-down): Solution 2 的改进版 lastdrop, `dict.get(key, default_value)`**

```python
# Project Euler Problem #18 Solution 3
# Lastdrop, dict.get(key, default_value), Top-down
# Ans: 1074

S = '''75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23'''


def hacks():
    d = {i: {} for i in range(-1, 15)}
    best = 0
    for i, row in enumerate(S.split('\n')):
        for j, v in enumerate(map(int, row.split(' '))):
            d[i][j] = max(d[i-1].get(j-1, 0), d[i-1].get(j, 0)) + v
            best = max(best, d[i][j])
    print(best)


if __name__ == "__main__":
    hacks()
```



:heart:  **Solution3-2 (Bottom-up): Solution 1 的方法类似 lastdrop, `dict.get(key, default_value)`**

```python
# Project Euler Problem #18 Solution 3
# Lastdrop, dict.get(key, default_value), Bottom-up
# Ans: 1074

S = '''75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23'''


def hacks(n = 15):
    d = {i: {} for i in range(-1, n)}
    for i, row in enumerate(reversed(S.split('\n'))):
        for j, v in enumerate(map(int, row.split(' '))):
            d[i][j] = max(d[i-1].get(k, 0) for k in [j, j+1]) + v
        # del d[i-1]
    return d[n-1][0]


if __name__ == "__main__":
    print(hacks())
```



**Solution 4: Recursion** 这里无法用 `@lru_cache`，因为`TypeError: unhashable type: 'list'`

```python
# Project Euler Problem #18 Solution 4: Recursion
# Ans: 1074

data_str = '''
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
'''.strip().split('\n')

data = [list(map(int, line.split())) for line in data_str]

def maxpath(datum, index):
    if len(datum) == 1:
        return datum[0][index]
    return datum[0][index] + max(maxpath(datum[1:], index), maxpath(datum[1:], index + 1))


if __name__ == "__main__":
    print(maxpath(data, 0))
```



**Solution 4: Recursion 改进版，可以用`@lru_cache`**  http://tiny.cc/5dx5cz

```python
# Project Euler Problem #18 Solution 4: Recursion v2
# Ans: 1074

from functools import lru_cache
from time import time as t

# p018 Solution：
data_str = '''
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
'''.strip().split('\n')

data = [list(map(int, line.split())) for line in data_str]

# p067 Solution：
with open('p067_data.txt') as file:
    data = [list(map(int, line.split())) for line in file.read().split('\n')]

@lru_cache(None)
def maxpath(row, col):
    if row == len(data) - 1:
        return data[row][col]
    return data[row][col] + max(maxpath(row + 1, col), maxpath(row + 1, col + 1))


if __name__ == "__main__":
    start = t()
    print(maxpath(0,0), "Time taken:",t() - start)

# Prob#18 Time taken: 0.0009989738464355469
# Prob#67 Time taken: 0.007991790771484375
```



:heart: **Solution 5: DP Jan的版本** http://tiny.cc/aky5cz 耗时只有我的一半

```python
# Project Euler Problem #18, 67
# Ans: 1074， 7273

from time import time as t

with open('p067_data.txt') as file:
    data = [list(map(int, line.split())) for line in file.read().split('\n')]

def find_max_path_value(d):
    if len(d) == 1:
        return d[0][0]
    for i in range(len(d[-2])):
        d[-2][i] += max(d[-1][i], d[-1][i+1])
    return find_max_path_value(d[:-1])


if __name__ == "__main__":
    start = t()
    print(find_max_path_value(data), "Time taken:",t() - start)

# Output: 7273 Time taken: 0.003995418548583984
```

**还原成iteration：**

```python
# Project Euler Problem #18, 67
# Ans: 7273

from time import time as t

with open('p067_data.txt') as file:
    data = [list(map(int, line.split())) for line in file.read().split('\n')]

def maxpath(d):
    if len(d) == 1:
        return d[0][0]
    for i in range(len(d[-2])):
        d[-2][i] += max(d[-1][i], d[-1][i+1])
    return maxpath(d[:-1])


if __name__ == "__main__":
    start = t()
    print(maxpath(data), "Time taken:",t() - start)

# Output: 7273 Time taken: 0.003995418548583984
```

