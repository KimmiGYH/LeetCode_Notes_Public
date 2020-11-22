#include <iostream>
#include <stack>
// #include <string>

using namespace std;

stack<int> nums;
stack<char> ops;

void cal()
{
    int a = nums.top(); nums.pop();
    int b = nums.top(); nums.pop();
    char c = ops.top(); ops.pop();
    int r;

    if (c == '+')  r = b + a;
    else if (c == '-')  r = b - a;
    else if (c == '*')  r = b * a;
    else if (c == '/')  r = b / a;
    else // 如果是 ^，即 b ^ a
    {
        r = 1;
        while (a--)  r *= b;
    }
    nums.push(r);
}


int main()
{
    string str;
    cin >> str;
    // ((((((((((((2*3 的情况，要保证左括号比右括号多
    string left;
    for (int i = 0; i < str.size(); i++) left += '(';
    str = left + str + ')';



    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (c == ' ')  continue;
        if (isdigit(c)) {
            int j = i, x = 0;
            while (j < str.size() && isdigit(str[j]))
            {
                x = x * 10 + (str[j] - '0');
                j++;
            }
            i = j - 1;
            nums.push(x);
        } else {
            if ( c == '+' || c == '-')
            {
                // 判断负号
                if (c == '-' && !(isdigit(str[i-1]) || str[i-1] == ')'))
                {
                    int j = i + 1, x = 0; // j 从 i+1 开始，因为 i 是负号
                    while (j < str.size() && isdigit(str[j]))
                    {
                        x = x * 10 + (str[j] - '0');
                        j++;
                    }
                    i = j - 1;
                    nums.push(-x);
                }
                else
                {
                    while (ops.top() != '(')  cal();
                    ops.push(c);
                }
                
            }
            else if (c == '*' || c == '/')
            {
                while (ops.top() == '*' || ops.top() == '/' || ops.top() == '^')  cal();
                ops.push(c);
            }
            else if (c == '^')
            {
                while (ops.top() == '^')  cal();
                ops.push(c);
            }
            else if (c == '(')  ops.push('(');
            else if (c == ')')
            {
                while (ops.top() != '(')  cal();
                ops.pop();
            }
            else puts("Invalid operand!");
        }
    }
    cout << nums.top() << endl;
    return 0;
}

/*
Input: 2*-3^2-14
Output: 4
*/