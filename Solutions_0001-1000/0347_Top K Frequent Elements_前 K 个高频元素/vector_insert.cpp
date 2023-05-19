#include <iostream>
#include <vector>
 
void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}
 
int main ()
{
    std::vector<int> vec(3,100);
    print_vec(vec);
    // 100 100 100
 
    auto it = vec.begin();
    it = vec.insert(it, 200);
    print_vec(vec);
    // 200 100 100 100
 
    vec.insert(it, 2, 300);
    print_vec(vec);
    // 300 300 200 100 100 100
 
    // "it" 不再合法，获取新值：
    it = vec.begin();
 
    std::vector<int> vec2(2, 400);
    vec.insert(it + 2, vec2.begin(), vec2.end()); // 在 vec 下标为2的地方把 vec2 插进去
    print_vec(vec);
    // 300 300 400 400 200 100 100 100
 
    int arr[] = { 501,502,503 };
    vec.insert(vec.begin(), arr, arr+3); // 把数组查到首部
    print_vec(vec);
    // 501 502 503 300 300 400 400 200 100 100 100
}

/*
 100 100 100
 200 100 100 100
 300 300 200 100 100 100
 300 300 400 400 200 100 100 100
 501 502 503 300 300 400 400 200 100 100 100
*/