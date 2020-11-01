#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, name;
        if (path.back() != '/')  path += '/';
        for (auto c : path) {
            if (c != '/')  name += c;
            else {
                if (name == "..") {
                    while (res.size() && res.back() != '/')  res.pop_back(); // 去掉 'yxc'
                    if (res.size()) res.pop_back(); // 去掉 '/' 
                } else if (name != "." && name != "") {
                    res += '/' + name;
                }
                name.clear();
            }
        }
        if (res.empty()) res = '/';
        return res;
    }
};