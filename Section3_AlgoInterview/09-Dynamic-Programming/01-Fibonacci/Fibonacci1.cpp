#include <iostream>
#include <ctime>

using namespace std;

int num = 0;

// 递归求 Fibonacci 数列
int fib(int n) {
    
    num++;

    if (n == 0)
        return 0;
    
    if (n == 1)
        return 1;
    
    return fib(n-1) + fib(n-2);
}

int main() {

    num = 0;

    int n = 42;

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout << "fib(" << n << ") = " << res << endl;
    cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    cout << "run function fib() " << num << " times." << endl;

    return 0;
}

/* Output:
fib(42) = 267914296
time : 6.155 s
run function fib() 866988873 times.
*/