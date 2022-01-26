//找出大于100000的第一个质数

#include <iostream>

using namespace std;

const int N = 100010;

int main()
{
    for (int i = 100000; ; i++)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

// 100003