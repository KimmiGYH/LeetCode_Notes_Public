# [781. Rabbits in Forest](https://leetcode.com/problems/rabbits-in-forest/) (Medium)

There is a forest with an unknown number of rabbits. We asked n rabbits **"How many rabbits have the same color as you?"** and collected the answers in an integer array `answers` where `answers[i]` is the answer of the `ith` rabbit.

Given the array `answers`, return *the minimum number of rabbits that could be in the forest*.

 

**Example 1:**

```
Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
```

**Example 2:**

```
Input: answers = [10,10,10]
Output: 11
```

 

**Constraints:**

- `1 <= answers.length <= 1000`
- `0 <= answers[i] < 1000`





# [781. 森林中的兔子](https://leetcode-cn.com/problems/rabbits-in-forest/)

难度中等

森林中有未知数量的兔子。提问其中若干只兔子 **"还有多少只兔子与你（指被提问的兔子）颜色相同?"** ，将答案收集到一个整数数组 `answers` 中，其中 `answers[i]` 是第 `i` 只兔子的回答。

给你数组 `answers` ，返回森林中兔子的最少数量。

 

**示例 1：**

```
输入：answers = [1,1,2]
输出：5
解释：
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。 
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。 
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。 
因此森林中兔子的最少数量是 5 只：3 只回答的和 2 只没有回答的。
```

**示例 2：**

```
输入：answers = [10,10,10]
输出：11
```

 

**提示：**

- `1 <= answers.length <= 1000`
- `0 <= answers[i] < 1000`