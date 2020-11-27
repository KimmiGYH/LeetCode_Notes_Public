# C++四种打印二维数组的风格



```c++
int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
```



## 1. 完全 C 风格的输出二维数组



`p` 指向含有四个整数的数组，则 `*p` 就是那个数组，而数组名就是数组首元素的指针，所以 `*p` 即为 `p` 所指向的那个数组的首元素的指针。



```c++
for( int(*p)[4] = ia; p != ia + 3; ++p) { //注意是 != 而不是 <
    for(int *q = *p; q = *p + 4; ++q) {
        cout << *q <<' ';
    }
    cout << endl;
}
```



## 2. C++ 风格 使用 iterator



```c++
// 用 begin() 和 end() 来替代手工的控制变量
for (auto p = begin(res); p != end(res); ++p) {
    for (auto q = begin(*p); q != end(*p); ++q) {
        cout<< *q <<' ';
    }
    cout << endl;
}
```



## 3. 使用了类型别名的 C 风格



```c++
using int_array = int[4];
//typedef int int_array[4]; //等价上一语句
for(int_array *p = ia; p != ia + 3; ++p) {
    for(int *q = *p; q != *p + 4; ++q) {
        cout << *q << ' ';
    }
    cout << endl;
}
```



## 4. 使用范围`for`的方式（`p` 指向的是包含了四个`int`的数组）



```c++
// 除了最内层随意之外，外层的 for 都必须用 &(引用方式)，如果没有 & 那么会被编译器把 p(数组名字) 自动转化为指向数组首元素的指针。最内层引用与否要看需不需要改变数组内容。
```

```c++
for(int (&p)[4] : ia) {
    for(int &q : p) {
        cout << q << ' ';
    }
    cout << endl;
}
```

