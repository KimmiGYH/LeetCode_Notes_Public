#include <iostream>
using namespace std;

int main()
{
    int a = 3, b = 4;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << a << " " << b << endl;
}