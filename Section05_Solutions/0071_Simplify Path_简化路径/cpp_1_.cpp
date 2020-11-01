#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> res;
        stack<string> stk;

        // 处理斜杠之间的内容 '/'
        for (int i = 0; i < n;)
        {
            string cur = "";
            int j = i + 1;
            while (j < n && path[j] != '/')
                cur += path[j++];
            i = j;
            res.push_back(cur);
        }

        // 处理 1) "" 和 "."    不做操作
        //     2) ".."         如果栈不为空就退栈
        //     3) filename     入栈
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == "" || res[i] == ".")  continue;
            else if (res[i] == "..") { if (!stk.empty())  stk.pop();}
            else stk.push(res[i]);
        }

        string ans = "";
        while (!stk.empty())
        {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans == "" ? "/" : ans;
    }
};