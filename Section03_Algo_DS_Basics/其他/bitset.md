### C++ STL bitset 用法整理

`std::bitset` 是 `STL` 的一部分，准确地说，`std::bitset` 是一个**模板类**，它的模板参数不是类型，而整形的数值（这一特性是ISO C++2003的新特性），有了它我们**可以像使用数组一样使用位**。

下面看一个例子：

```c++
#include<bitset>
std::bitset<8> bs;//它是一个模板，传递的参数告诉编译器bs有8个位。
```

我们接着看上面的代码，通过上面两行的代码我们得到一个 `bitset` 的对象 `bs`，`bs` 可以装入 `8` 个位，我们可以通过数组的下标运算符来存取：

```c++
bs[0]=1;	//把第0位设置为1
bs[3]=true;	//把第3位设置为1,因为true可以转换为1
bs[7]=0;	//这个大家都明白了
```

`bitset` 被设计为开放的，也就是说一个 `bitset` 对象可以转换为其它类型的值，典型的，我们想把一个整数设置成具有特定的位模式，我们可以简单地把一个 `bitset` 转换为一个整数：

```c++
unsigned long value=bs.to_ulong();
std::bitset<32> bs32(value);
bs32[15]=1;
value=bs32.to_ulong();
```

此外bitset还可以也字符串互换，这样我们就可以更直观对bitset进行操作了，我只是简单地把我们想要的”01“字符串就可以了：
std::bitset<32> bs("011010101001");
std::string str=bs.to_string();

//=======================================
bitset<n> b;
 b有n位，每位都为0.参数n可以为一个表达式.
如bitset<5> b0;则"b0"为"00000";

bitset<n> b(unsigned long u);
 b有n位,并用u赋值;如果u超过n位,则顶端被截除
如:bitset<5>b0(5);则"b0"为"00101";

bitset<n> b(string s);
 b是string对象s中含有的位串的副本
string bitval("10011");
bitset<5> b0(bitval4);
则"b0"为"10011";


bitset<n> b(s, pos);
 b是s中从位置pos开始位的副本,前面的多余位自动填充0;
string bitval("01011010");
bitset<10> b0(bitval5, 3);
则"b0" 为 "0000011010";

bitset<n> b(s, pos, num);
 b是s中从位置pos开始的num个位的副本,如果num<n,则前面的空位自动填充0;
string bitval("11110011011");
bitset<6> b0(bitval5, 3, 6);
则"b0" 为 "100110";

// 流
os << b
 把b中的位集输出到os流
os >>b
输入到b中,如"cin>>b",如果输入的不是0或1的字符,只取该字符前面的二进制位.

// 属性方法
bool any()
 是否存在置为1的二进制位?和none()相反

bool none()
是否不存在置为1的二进制位,即全部为0?和any()相反.

size_t count()
二进制位为1的个数.

size_t size()
 二进制位的个数

flip()
 把所有二进制位逐位取反

flip(size_t pos)
 把在pos处的二进制位取反

bool operator[](size_type _Pos)
 获取在pos处的二进制位

set()
 把所有二进制位都置为1

set(pos)
 把在pos处的二进制位置为1

reset()
 把所有二进制位都置为0

reset(pos)
 把在pos处的二进制位置为0

test(size_t pos)
在pos处的二进制位是否为1?

unsigned long to_ulong()
 用同样的二进制位返回一个unsigned long值

string to_string()
返回对应的字符串.