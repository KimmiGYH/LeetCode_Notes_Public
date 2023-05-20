class Solution {
public:
    int get(int n) {//不要加&，否则报错
        int s = 0;
        while (n) {
            s += (n % 10) * (n % 10);
            n -= n % 10; //可以省去
            n /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        int fast = get(n), slow = n;
        while(fast != slow) {
            fast = get(get(fast));
            slow = get(slow);
        }
        return fast == 1;
    }
};
/*【注意】快慢指针从哪个点走都可以，只要有环，最终两个指针都会相遇。
初始时，你可以看成有一个虚拟的点，下一步指向n，slow走一步就slow = n，fast走两步就fast = get(n)
*/

//===============================================
【报错信息】：
Compile Error
Line 17: Char 24: error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
            fast = get(get(fast));
                       ^~~~~~~~~
Line 3: Char 18: note: passing argument to parameter 'n' here
    int get(int& n) {
                 ^
1 error generated.

【ChatGPT给到的解释】：
这个编译错误是因为你的代码试图将一个临时值（即右值）绑定到一个非常量的左值引用上。在 C++ 中，左值引用必须绑定到一个左值（可以取地址的表达式或对象）。而右值引用则可以绑定到右值（不可取地址的表达式或对象）。

在这个错误信息中，non-const lvalue reference 意味着非常量的左值引用，type 'int' 表示引用的类型是 int，cannot bind to a temporary of type 'int' 意味着不能将类型为 int 的临时值绑定到这个左值引用上。