# Leetcode 155 Min Stack

## Problem Statement

[https://leetcode.com/problems/min-stack/](https://leetcode.com/problems/min-stack/)

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

* `MinStack()` initializes the stack object.
* `void push(val)` pushes the element `val` onto the stack.
* `void pop()` removes the element on the top of the stack.
* `int top()` gets the top element of the stack.
* `int getMin()` retrieves the minimum element in the stack.

**Example 1:**

```text
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Constraints:**

* `-2^31 <= val <= 2^31 - 1`
* Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
* At most `3 * 10^4` calls will be made to `push`, `pop`, `top`, and `getMin`.

## Solution

```cpp
class MinStack {
public:
    /* initialize your data structure here. */
    stack<pair<int,int>> s;
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push(make_pair(val,val));
        else 
           s.push(make_pair(val, min(val, s.top().second)));
    }
    
    void pop() { s.pop(); }
    
    int top()  { return s.top().first; }
    
    int getMin() { return s.top().second; }
};
```

