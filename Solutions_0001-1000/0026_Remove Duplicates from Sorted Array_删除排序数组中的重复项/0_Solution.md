# 26. Remove Duplicates from Sorted Array

## 方法一：双指针法，时间复杂度 O(n)

此题使用双指针法，$O(n)$ 的时间复杂度。

参考动图：[LeetCode 官方题解](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-tudo/)

注意题目中：不要使用额外的数组空间，必须在 原地 修改输入数组 并在使用 $O(1)$ 额外空间的条件下完成。

判断 `nums[idx - 1]` 是否和 `nums[i]` 不同，如果不同，那么 `nums[idx++] = nums[i]`。

**通用解法**
为了让解法更具有一般性，我们将原问题的「最多保留 1 位」修改为「最多保留 k 位」。

对于此类问题，我们应该进行如下考虑：

- 由于是保留 `k` 个相同数字，对于前 `k` 个数字，我们可以直接保留。
- 对于后面的任意数字，能够保留的前提是：与当前写入的位置前面的第 `k` 个元素进行比较，不相同则保留。
  



举个🌰，我们令 `k=1`，假设有样例：`[3,3,3,3,4,4,4,5,5,5]`

1. 设定变量 `idx`，指向待插入位置。`idx` 初始值为 `0`，目标数组为 `[]`
2. 首先我们<u>先让第 `1` 位直接保留（性质 1）</u>。`idx` 变为 `1`，目标数组为 `[3]`
3. 继续往后遍历，<u>能够保留的前提是与 `idx` 的前面 `1` 位元素不同（性质 2）</u>，因此我们会跳过剩余的 `3`，将第一个 `4` 追加进去。`idx` 变为 `2`，目标数组为 `[3,4]`
4. 继续这个过程，跳过剩余的 `4`，将第一个 `5` 追加进去。`idx` 变为 `3`，目标数组为 `[3,4,5]`
5. 当整个数组被扫描完，最终我们得到了目标数组 `[3,4,5]` 和 答案 `idx` 为 `3`。

模板：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return solve(nums, 1);
    }
    
    int solve(vector<int>& nums, int k) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (idx < k || nums[idx-k] != nums[i])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};
```




**复杂度分析**

- 时间复杂度：$O(n)$，其中 $n$ 是数组的长度。快指针和慢指针最多各移动 $n$ 次。
- 空间复杂度：$O(1)$。只需要使用常数的额外空间。

**这是一种针对「数据有序，相同元素保留 `k` 位」问题更加本质的解法，该解法是从性质出发提炼的，利用了「数组有序 & 保留逻辑」两大主要性质。**

[26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

[80. 关于「删除有序数组重复项」的通解](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/)