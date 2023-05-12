class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // [0, n-2]，下面解释为什么取到 n-2 而不是 n-2
        // (-1, n-1) 开区间
        int l = -1 , r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid+1]) r = mid;
            else l = mid;
        }
        return r;
    }
};

/*【问】：为什么要拿mid的值和right处的值比，不能用mid处的值和mid+1处的值比较么？

【答】：除了最小值旁边的元素，其它位置都满足 nums[mid] < nums[mid+1]，无法通过这个判断怎么染色。
*/



/*【问】：162的右边界要初始成为 n-2（如果用闭区间的话），这个是怎么想到的呢？是因为我们需要用到 m 和 m+1 吗？
【答】：因为 n-1 要么是答案，要么在答案右侧，所以 n-1 一定是蓝色，无需二分。


【追问】：
1. 这种提前判断一个边界元素的方法会影响最终结果吗，还是只是二分范围减小了1和在某些条件下可以简化判断？
2. 感觉网上包括国区美区lc每次二分的题的题解大家的写法都不太一样，可以说五花八门。。。甚至还有我认为“终止条件”和“收缩边界”混写的（区间与收缩边界），然后是正确答案的，这种需要去尝试搞清别人的思路吗，还是就自己一直使用一种方法比如闭区间一直写不同的题写下去？ 更具体的说，有些题解比如 left = 0， right = n-1，是左闭右闭，但循环条件是 while (l < r)，这种能正确是不是可能也是因为 n-1 其实不用进行二分？所以其实他这个 left 和 right 是左闭右开？

【答】
1. 提前判断一个边界元素的方法，不会影响结果（如果答案是最后一个元素，视频中的写法仍然是正确的）。这种写法的好处是可以简化代码。
2. 有的题解写的左闭右闭，但是循环条件写的是左闭右开，这属于没有透彻理解二分的糊涂写法，这种写法会提前退出循环，导致循环结束后，还要再做额外的判断。
*/