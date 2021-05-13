# Leetcode 307 Range Sum Query - Mutable

## Problem Statement

[https://leetcode.com/problems/range-sum-query-mutable/](https://leetcode.com/problems/range-sum-query-mutable/)

Given an integer array `nums`, handle multiple queries of the following types:

1. **Update** the value of an element in `nums`.
2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

* `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
* `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
* `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** \(i.e. `nums[left] + nums[left + 1] + ... + nums[right]`\).

**Example 1:**

```text
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
```

**Constraints:**

* `1 <= nums.length <= 3 * 10^4`
* `-100 <= nums[i] <= 100`
* `0 <= index < nums.length`
* `-100 <= val <= 100`
* `0 <= left <= right < nums.length`
* At most `3 * 10^4` calls will be made to `update` and `sumRange`.

## Solution

### Binary Indexed Tree \(BIT\) Approach

For more details on BIT, please check this [link](https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees).

```cpp
class NumArray {
public:
    vector<int> tree;
    vector<int> orig_nums;
    int size;
    int compute(int index)
    {
        int sum = 0;
        index++;
        while(index > 0)
        {
            sum += tree[index];
            index -= (index & -index);
        }
        return sum;
    }
    
    void init(int index, int val)
    {
        index++;
        while(index <= size)
        {
            tree[index] += val;
            index += (index & -index);
        }
    }
    
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree.resize(size + 1,0);
        orig_nums = nums;
        for(int i = 0; i < nums.size(); i++)
           init(i, nums[i]);
    }
    
    void update(int index, int val) {
        int diff = val - orig_nums[index];
        orig_nums[index] = val;
        init(index, diff);
    }
    
    int sumRange(int left, int right) {
        return compute(right) - compute(left-1);
    }
};
```

