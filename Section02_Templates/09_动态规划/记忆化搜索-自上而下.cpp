#include <vector>
using namespace std;

vector<int> memo;

int fib( int n ) {
    
    if ( n == 0 )
        return 0;
    
    if ( n == 1 )
        return 1;
    
    if ( memo[n] == -1 )
        memo[n] = fib(n-1) + fib(n-2);
    
    return memo[n];
}