# 791_Custom Sort String_自定义字符串排序

## 解法一：字符串哈希

给我们两个字符串 $order$ 和 $s$，让我们将 $s$ 按照 $order$ 的顺序进行排序，即如果 $order$ 中字母 x 排在字母 y 之前，那么排序后的 $s$ 中字母 x 也要在 y 之前，其他 $s$ 中未出现的字母位置无所谓。

我们看 $order$ 中的字母，只要按 $order$ 中的字母顺序遍历，对于遍历到的每个字母，如果 $s$ 中有的话，就先排出来，这样等 $order$ 中的字母遍历完了，再将 $s$ 中剩下的字母加到后面即可。

所以我们先用哈希表统计 $s$ 中每个字母出现的次数，然后遍历 $order$ 中的字母，只要 $s$ 中有，九江该字母重复其出现次数个，加入结果 $res$ 中，然后将该字母出现次数重置为 $0$。之后再遍历一遍哈希表，将 $s$ 中其他字母加入结果 $res$ 中即可。

## 解法二：用数组映射

解法二的思路和上面的一样，只不过这里没有使用哈希表，而是使用了一个长度为 $26$ 的数组。

【知识点】：

- `--t` 前减减是先减，再用减完的值作比较；
- `t--` 后减减是先做比较再减，减完的值就不参与比较了。
- `while (t--)` 和 `while(t-- > 0)`的区别，看初始 `t` 从多少开始取，如果是从 $= 0$ 开始的，那么递减一下就成负数了。

## 解法三：lambda函数对象

自定义了 $sort$ 的排序方式，对于字符串 $s$ 中的任意两个字母 `a` 和 `b`，按照其在 $order$ 中的顺序排序，在 `order` 中排前面的在 `s` 中也排前面。

- Primer P351 隐式捕获。`&` 告诉编译器采用捕获引用方式，`=` 则表示采用值捕获方式。
- Primer P510 在算法中使用标准库函数对象

## 解法四：哈希表+lambda

这种解法没有用到 STL 中内置的 `find` 函数，而是用了哈希表来建立 `order` 中每个字母和其出现位置之间的映射，这样在自定义排序方法的时候，就可以直接从哈希表中取位置了。
