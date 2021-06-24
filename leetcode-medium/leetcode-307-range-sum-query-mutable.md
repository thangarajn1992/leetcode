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

{% tabs %}
{% tab title="Segment Tree Approach" %}
```cpp
class SegmentNode{
public:
    int start;
    int end;
    int sum;
    SegmentNode* left;
    SegmentNode* right;
    SegmentNode(int start,int end){
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
        this->sum = 0;
    }
};

class NumArray {
public:
    SegmentNode* root;
    vector<int> my_nums;

    NumArray(vector<int>& nums) {
        my_nums = nums;
        root = constructSt(0, nums.size()-1);
    }
    
    void update(int index, int val) {
        if(!root)
            return;
        int diff = my_nums[index] - val;
        my_nums[index] = val;
        SegmentUpdate(root, index, diff);
    }
    
    int sumRange(int left, int right) {
        if(!root)
            return 0;
        return SegmentSum(root, left, right);
    }
    
    SegmentNode *constructSt(int start, int end)
    {
        if(start > end)
            return nullptr;
        
        SegmentNode *node = new SegmentNode(start,end);
        if(start == end)
            node->sum = my_nums[start];
        else
        {
            int mid = start + (end-start)/2;
            node->left = constructSt(start, mid);
            node->right = constructSt(mid+1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }
    
    void SegmentUpdate(SegmentNode* root, int index, int diff)
    {
        if(!root || index < root->start || index > root->end)
            return;
        if(index >= root->start && index <= root->end)
            root->sum -= diff;
        SegmentUpdate(root->left, index, diff);
        SegmentUpdate(root->right, index, diff);
    }
    
    int SegmentSum(SegmentNode* root, int start, int end)
    {
        if(!root || start > root->end || end < root->start)
            return 0;
        if(start <= root->start && end >= root->end)
            return root->sum;
        else
            return SegmentSum(root->left, start, end) + SegmentSum(root->right, start, end);
    }
};
```
{% endtab %}

{% tab title="Binary Indexed Tree \(BIT\) Approach" %}
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
{% endtab %}
{% endtabs %}

### 

