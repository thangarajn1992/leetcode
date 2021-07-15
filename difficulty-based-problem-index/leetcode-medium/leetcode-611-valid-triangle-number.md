# Leetcode 611 Valid Triangle Number

## Problem Statement

[https://leetcode.com/problems/valid-triangle-number/](https://leetcode.com/problems/valid-triangle-number/)

Given an integer array `nums`, return _the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle_.

**Example 1:**

```text
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Example 2:**

```text
Input: nums = [4,2,3,4]
Output: 4
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`

## Solution

### Mathematics Approach

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int freq[1001]; memset(freq, 0, sizeof(freq));
        int prefix_sum[1001]; memset(prefix_sum, 0, sizeof(prefix_sum));
        int ans = 0;
         
        for(int side : nums)  
            freq[side]++; 

        for(int i = 1; i <= 1000; i++)    
            prefix_sum[i] = prefix_sum[i-1] + freq[i];
        
        int first_side, second_side, third_side_max, side;
        // Triangles of 3 different sides
        // different sides can only be from 2 to 998
        for(first_side = 2; first_side <= 998; first_side++)
        {
            if(freq[first_side] > 0)
            {
                for(second_side = first_side+1; second_side < 1000; second_side++){
                    third_side_max = min(first_side + second_side - 1, 1000);
                    ans += (prefix_sum[third_side_max] - prefix_sum[second_side]) * freq[first_side] * freq[second_side];
                }
            }
        }
        
        // Triangles with same sides  = nC3  =>  (n * (n-1) * (n-2))/(1 * 2 * 3)
        for(side = 1; side <= 1000; side++)
            if(freq[side] > 2)
                ans += (freq[side] * (freq[side] - 1) * (freq[side] - 2))/6;
        
        
        // Triangles with 2 Same side + 1 different side
        // 3rd side can be any number from 1 to 2*same_side - 1
        // Combinations : selecting 2 same sides from freq * total numbers from 1 to 2*side-1 except that side
        // Combination : nC2 * total numbers from 1 to 2*side-1 except that side
        // nC2 = (n * (n-1)) / (1 * 2)
        for(side = 1; side <= 1000; side++)
        {
            if(freq[side] > 1) 
            {
                third_side_max = min((2 * side) - 1, 1000);
                int combo_selecting_two_same_sides = ((freq[side] * (freq[side] - 1))/2);
                ans += (prefix_sum[third_side_max] - freq[side]) * combo_selecting_two_same_sides;
            }
        }
        return ans;
    }
};
```

### Sorting + Linear Traversal

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < size - 2; i++)
        {
            if(nums[i] != 0)
            {
                int k = i + 2;
                for(int j = i+1; j < size - 1; j++)
                {
                    while(k < size && nums[i] + nums[j] > nums[k])
                        k++;
                    count += (k - j - 1);
                }
            }
        }
        return count;
    }
};
```

