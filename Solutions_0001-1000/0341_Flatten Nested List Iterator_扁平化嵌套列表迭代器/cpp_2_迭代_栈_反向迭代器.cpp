#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// 构造时仅仅扒一层皮就 逆向 堆入栈中，在用户调用 hasNext 时才做深入扒皮搜索。
// rbegin, rend 是反向迭代器
class NestedIterator {
private:
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++)
            stk.push(*iter);
    }

    int next() {
        auto t = stk.top();
        stk.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto cur = stk.top();
            if (cur.isInteger()) return true;
            stk.pop();
            auto curList = cur.getList();
            for (auto iter = curList.rbegin(); iter != curList.rend(); iter++)
                stk.push(*iter);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */