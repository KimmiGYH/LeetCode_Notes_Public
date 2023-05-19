//写法一：
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xorsum = 0;
        for (int& c : nums)
            xorsum ^= c;
        for (int i = 1; i <= nums.size(); i++)
            xorsum ^= i;
        int lowbit = xorsum & (-xorsum);
        int num1 = 0, num2 = 0;
        for (int& c : nums) {
            if ((c & lowbit) == 0) num1 ^= c;
            else num2 ^= c;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if ((i & lowbit) == 0) num1 ^= i;
            else num2 ^= i;
        }
        for (int& c : nums) {
            if (c == num1)
                return vector<int>{num1, num2};
        }
        return vector<int>{num2, num1};
    }
};
// 注意vector<int>{num1, num2} 的表示方法


//写法二：

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int xorsum = 0;
        for (int& c : nums)
            xorsum ^= c;
        for (int i = 1; i <= nums.size(); i++)
            xorsum ^= i;
        int lowbit = xorsum & (-xorsum);
        int num1 = 0, num2 = 0;
        for (int& c : nums) {
            if ((c & lowbit) == 0) num1 ^= c;
            else num2 ^= c;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if ((i & lowbit) == 0) num1 ^= i;
            else num2 ^= i;
        }
        for (int&c : nums) { //这里是我自己的写法
            if (c == num1)
                res[0] = num1, res[1] = num2;
            else if (c == num2)
                res[0] = num2, res[1] = num1;
        }
        return res;
    }
};