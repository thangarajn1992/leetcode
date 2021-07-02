# Leetcode 341 Flatten Nested List Iterator

## Problem Statement

[https://leetcode.com/problems/flatten-nested-list-iterator/](https://leetcode.com/problems/flatten-nested-list-iterator/)

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

* `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.
* `int next()` Returns the next integer in the nested list.
* `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

**Example 1:**

```text
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: 
By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1,1,2,1,1].
```

**Example 2:**

```text
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: 
By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1,4,6].
```

**Constraints:**

* `1 <= nestedList.length <= 500`
* The values of the integers in the nested list is in the range `[-10^6, 10^6]`.

## Solution

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, 
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, 
 *     // if it holds a single integer.
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, 
 *     // if it holds a nested list.
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
    queue<int> data;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    void flatten(vector<NestedInteger> &nestedList){
        for (NestedInteger el : nestedList){
            if (el.isInteger()) data.push(el.getInteger());
            else
                flatten(el.getList());
        }       
    }
    int next() {
        int res = data.front();
        data.pop();
        return res;
    } 
    bool hasNext() {
        return !data.empty();
    }
};
```

