# [299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/) (Medium)

You are playing the **[Bulls and Cows](https://en.wikipedia.org/wiki/Bulls_and_Cows)** game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

- The number of "bulls", which are digits in the guess that are in the correct position.
- The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number `secret` and your friend's guess `guess`, return *the hint for your friend's guess*.

The hint should be formatted as `"xAyB"`, where `x` is the number of bulls and `y` is the number of cows. Note that both `secret` and `guess` may contain duplicate digits.

 

**Example 1:**

```
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
```

**Example 2:**

```
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
```

**Example 3:**

```
Input: secret = "1", guess = "0"
Output: "0A0B"
```

**Example 4:**

```
Input: secret = "1", guess = "1"
Output: "1A0B"
```

 

**Constraints:**

- `1 <= secret.length, guess.length <= 1000`
- `secret.length == guess.length`
- `secret` and `guess` consist of digits only.



# [299. 猜数字游戏](https://leetcode-cn.com/problems/bulls-and-cows/)

难度中等

你在和朋友一起玩 [猜数字（Bulls and Cows）](https://baike.baidu.com/item/猜数字/83200?fromtitle=Bulls+and+Cows&fromid=12003488&fr=aladdin)游戏，该游戏规则如下：

1. 你写出一个秘密数字，并请朋友猜这个数字是多少。
2. 朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
3. 朋友根据提示继续猜，直到猜出秘密数字。

请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 `xAyB` ，`x` 和 `y` 都是数字，`A` 表示公牛，用 `B` 表示奶牛。

- `xA` 表示有 `x` 位数字出现在秘密数字中，且位置都与秘密数字一致。
- `yB` 表示有 `y` 位数字出现在秘密数字中，但位置与秘密数字不一致。

请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。

 

**示例 1:**

```
输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
```

**示例 2:**

```
输入: secret = "1123", guess = "0111"
输出: "1A1B"
解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
```

 

**说明:** 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。



