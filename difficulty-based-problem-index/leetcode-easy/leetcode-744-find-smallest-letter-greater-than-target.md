# Leetcode 744 Find Smallest Letter Greater Than Target

## Problem Statement

[https://leetcode.com/problems/find-smallest-letter-greater-than-target/](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

Given a characters array `letters` that is sorted in **non-decreasing** order and a character `target`, return _the smallest character in the array that is larger than_ `target`.

**Note** that the letters wrap around.

* For example, if `target == 'z'` and `letters == ['a', 'b']`, the answer is `'a'`.

**Example 1:**

```text
Input: letters = ["c","f","j"], target = "a"
Output: "c"
```

**Example 2:**

```text
Input: letters = ["c","f","j"], target = "c"
Output: "f"
```

**Example 3:**

```text
Input: letters = ["c","f","j"], target = "d"
Output: "f"
```

**Example 4:**

```text
Input: letters = ["c","f","j"], target = "g"
Output: "j"
```

**Example 5:**

```text
Input: letters = ["c","f","j"], target = "j"
Output: "c"
```

**Constraints:**

* `2 <= letters.length <= 10^4`
* `letters[i]` is a lowercase English letter.
* `letters` is sorted in **non-decreasing** order.
* `letters` contains at least two different characters.
* `target` is a lowercase English letter.

## Solution

### Binary Search Approach

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return letters[left % letters.size()];
    }
};
```

