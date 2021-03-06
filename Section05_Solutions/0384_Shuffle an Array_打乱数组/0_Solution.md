# 384_Shuffle an Array_打乱数组

## 解法一：洗牌算法 $O(n)$

- 洗牌算法：对于数组的每一个元素，随机从这个元素以及后面的所有元素中选取一个元素与该元素交换。
- 正确性：一个数组全排列有 $n!$ 种情况，所以洗牌算法也需要有 $n!$ 种情况来满足排列的公平性。

- 数组：$1，2，3，4$
  - 第一轮：选中 $1$，在 $1，2，3$ 中随机选取一个数和 $1$ 交换，例如 $3$，得到 $3，2，1，4$
  - 第二轮：选中 $2$，在 $2，1，4$ 中随机选择一个数和 $2$ 交换，例如 $4$，得到 $3，4，1，2$
  - 第三轮：选中 $1$，在 $1，2$ 中随机选择一个数和 $1$ 交换，例如 $2$，得到 $3，4，2，1$
  - 第四轮：选中 $1$，这轮可以省略

一共有 $4·3·2·1$ 种情况，即 $n!$ 种情况，符合随机的要求。

重点代码：`swap(b[i], b[i + rand() % (n - i)]);`
