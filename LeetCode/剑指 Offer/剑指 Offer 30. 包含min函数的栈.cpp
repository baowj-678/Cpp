/**
 * @author: Bao Wenjie
 * @link: https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 * @date: 2021/9/4
 */
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> S;
    stack<int> Min;
    MinStack() {

    }

    void push(int x) {
        S.push(x);
        if (!Min.empty())
        {
            Min.push(std::min(Min.top(), x));
        }
        else
            Min.push(x);
    }

    void pop() {
        if (!S.empty())
        {
            S.pop();
            Min.pop();
        }
    }

    int top() {
        return S.top();
    }

    int min() {
        return Min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */