class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        string res = "";
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c))
                n = n * 10 + (c - '0');
            else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
                res = res + s[i];
            else if (c == '[') {//将‘[’前的数字压入nums栈内，字母字符串压入strs栈内
                nums.push(n);
                n = 0;
                str.push(res);
                res = "";
            } else {//遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
                int times = nums.top();
                nums.pop();
                while (times--)  str.top() += res;
                res = str.top();
                str.pop();
            }
        }
        return res;
    }
};
/* Input: "3[a]2[bc]"

a aa aaa 
res: aaa

aaabc aaabcbc 
res: aaabcbc
*/
