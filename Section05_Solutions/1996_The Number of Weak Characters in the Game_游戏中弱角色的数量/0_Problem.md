# [1996. The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/) (Medium)

You are playing a game that contains multiple characters, and each of the characters has **two** main properties: **attack** and **defense**. You are given a 2D integer array `properties` where `properties[i] = [attacki, defensei]` represents the properties of the `ith` character in the game.

A character is said to be **weak** if any other character has **both** attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be **weak** if there exists another character `j` where `attackj > attacki` and `defensej > defensei`.

Return *the number of **weak** characters*.

 

**Example 1:**

```
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```

**Example 2:**

```
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
```

**Example 3:**

```
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
```

 

**Constraints:**

- `2 <= properties.length <= 10^5`
- `properties[i].length == 2`
- `1 <= attacki, defensei <= 10^5`



# [1996. 游戏中弱角色的数量](https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game/)

难度中等

你正在参加一个多角色游戏，每个角色都有两个主要属性：**攻击** 和 **防御** 。给你一个二维整数数组 `properties` ，其中 `properties[i] = [attacki, defensei]` 表示游戏中第 `i` 个角色的属性。

如果存在一个其他角色的攻击和防御等级 **都严格高于** 该角色的攻击和防御等级，则认为该角色为 **弱角色** 。更正式地，如果认为角色 `i` **弱于** 存在的另一个角色 `j` ，那么 `attackj > attacki` 且 `defensej > defensei` 。

返回 **弱角色** 的数量。

 

**示例 1：**

```
输入：properties = [[5,5],[6,3],[3,6]]
输出：0
解释：不存在攻击和防御都严格高于其他角色的角色。
```

**示例 2：**

```
输入：properties = [[2,2],[3,3]]
输出：1
解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
```

**示例 3：**

```
输入：properties = [[1,5],[10,4],[4,3]]
输出：1
解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
```

 

**提示：**

- `2 <= properties.length <= 10^5`
- `properties[i].length == 2`
- `1 <= attacki, defensei <= 10^5`