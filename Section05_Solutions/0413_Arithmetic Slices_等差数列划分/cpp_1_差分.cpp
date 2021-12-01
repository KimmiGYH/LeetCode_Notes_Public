#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        for (int i = A.size() - 1; i > 0; i--)  A[i] -= A[i - 1];
        int res = 0;
        for (int i = 1; i < A.size(); i++) {
            int j = i; //双指针
            while (j < A.size() && A[j] == A[i]) j++; //计算相同的差分元素有多少个，移动右指针 
            int k = j - i; //k表示差分数组右端点可以取的数的个数
            res += k * (k - 1) / 2;
            i = j - 1; //更新i到差分数组相同的最后一个元素
        }
        return res;
    }
};