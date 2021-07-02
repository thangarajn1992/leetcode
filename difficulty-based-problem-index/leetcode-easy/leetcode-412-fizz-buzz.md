# Leetcode 412 Fizz Buzz

## Problem Statement

[https://leetcode.com/problems/fizz-buzz/](https://leetcode.com/problems/fizz-buzz/)

Given an integer `n`, return _a string array_ `answer` \(**1-indexed**\) _where_:

* `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
* `answer[i] == "Fizz"` if `i` is divisible by `3`.
* `answer[i] == "Buzz"` if `i` is divisible by `5`.
* `answer[i] == i` if non of the above conditions are true.

**Example 1:**

```text
Input: n = 3
Output: ["1","2","Fizz"]
```

**Example 2:**

```text
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
```

**Example 3:**

```text
Input: n = 15
Output: 
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

**Constraints:**

* `1 <= n <= 10^4`

## Solution

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1; i <= n; i++)
        {
            int mod5 = i%5, mod3 = i%3;
            if(!mod5 && !mod3)  result.push_back("FizzBuzz");
            else if(!mod3) result.push_back("Fizz");
            else if(!mod5) result.push_back("Buzz");
            else result.push_back(to_string(i));
        }
        return result;
    }
};
```

