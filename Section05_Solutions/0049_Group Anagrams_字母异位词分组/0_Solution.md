# 49_Group Anagrams_字母异位词分组 (Medium)

**题目大意**：这道题让我们群组给定字符串集中所有的错位词，所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，比如 abc，bac, cba 等它们就互为错位词。

## 写法一：哈希表

- 那么如何判断两者是否是错位词呢，可以发现如果把错位词的字符顺序**重新排列**，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法；
- 由于错位词重新排序后都会得到相同的字符串，以此作为 $key$，将所有错位词都保存到字符串数组中，建立 $key$ 和当前的不同的错位词集合之间的映射；
- 最后再将哈希表中的集合拷贝到结果 $res$ 中。

## 写法二：哈希表

- 在上面的写法基础上，当检测到当前的单词不在哈希表中，此时知道这个单词将属于一个新的错位词集合，所以将其映射为当前的错位词集合的个数，然后在 $res$ 中新增一个空集合，这样就可以通过其映射值，直接找到新的错位词集合的位置，从而将新的单词存入结果 $res$ 中

## 解法二：数字统计

- 这种解法没有用到排序，用一个大小为 $26$ 的 `int` 数组来统计每个单词中字符出现的次数，然后将 `int` 数组转为一个唯一的字符串，跟字符串数组进行映射，这样就不用给字符串排序了。
