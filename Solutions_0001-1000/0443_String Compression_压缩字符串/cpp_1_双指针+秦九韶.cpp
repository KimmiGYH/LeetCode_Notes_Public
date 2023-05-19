class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0; //用k表示答案的位置
        for (int i = 0; i < chars.size(); i++) {
            int j = i + 1;
            while (j < chars.size() && chars[j] == chars[i])  j++;
            int len = j - i; //当前相同字符出现的长度
            chars[k++] = chars[i]; //先把当前字符存下来
            if (len > 1) { //如果len==1就不用管了
                int t = k;
                while (len) {
                    chars[t++] = '0' + len % 10;
                    len /= 10;
                } //比如123，存的时候变成321，所以还需要将 k 到 t-1 这部分字符翻转
                reverse(chars.begin() + k, chars.begin() + t);
                k = t;
            }
            i = j - 1;
        }
        return k;
    }
};