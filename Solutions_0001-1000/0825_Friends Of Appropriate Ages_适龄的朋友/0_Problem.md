# [825. Friends Of Appropriate Ages](https://leetcode.com/problems/friends-of-appropriate-ages/) (Medium)

There are `n` persons on a social media website. You are given an integer array `ages` where `ages[i]` is the age of the `ith` person.

A Person `x` will not send a friend request to a person `y` (`x != y`) if any of the following conditions is true:

- `age[y] <= 0.5 * age[x] + 7`
- `age[y] > age[x]`
- `age[y] > 100 && age[x] < 100`

Otherwise, `x` will send a friend request to `y`.

Note that if `x` sends a request to `y`, `y` will not necessarily send a request to `x`. Also, a person will not send a friend request to themself.

Return *the total number of friend requests made*.

 

**Example 1:**

```
Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
```

**Example 2:**

```
Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
```

**Example 3:**

```
Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
```

 

**Constraints:**

- `n == ages.length`
- `1 <= n <= 2 * 10^4`
- `1 <= ages[i] <= 120`



# [825. 适龄的朋友](https://leetcode-cn.com/problems/friends-of-appropriate-ages/)

难度中等

在社交媒体网站上有 `n` 个用户。给你一个整数数组 `ages` ，其中 `ages[i]` 是第 `i` 个用户的年龄。

如果下述任意一个条件为真，那么用户 `x` 将不会向用户 `y`（`x != y`）发送好友请求：

- `ages[y] <= 0.5 * ages[x] + 7`
- `ages[y] > ages[x]`
- `ages[y] > 100 && ages[x] < 100`

否则，`x` 将会向 `y` 发送一条好友请求。

注意，如果 `x` 向 `y` 发送一条好友请求，`y` 不必也向 `x` 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

 

**示例 1：**

```
输入：ages = [16,16]
输出：2
解释：2 人互发好友请求。
```

**示例 2：**

```
输入：ages = [16,17,18]
输出：2
解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
```

**示例 3：**

```
输入：ages = [20,30,100,110,120]
输出：3
解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
```

 

**提示：**

- `n == ages.length`
- `1 <= n <= 2 * 10^4`
- `1 <= ages[i] <= 120`

