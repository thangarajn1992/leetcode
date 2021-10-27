# Leetcode 76 Minimum Window Substring

## Problem Statement

[https://leetcode.com/problems/minimum-window-substring/](https://leetcode.com/problems/minimum-window-substring/)

Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the **minimum window substring** of_ `s` _such that every character in_ `t` _(**including duplicates**) is included in the window. If there is no such substring, return the empty string_ `""`_._

The testcases will be generated such that the answer is **unique**.

A **substring** is a contiguous sequence of characters within the string.

**Example 1:**

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: 
The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**

```
Input: s = "a", t = "a"
Output: "a"
Explanation: 
The entire string s is the minimum window.
```

**Example 3:**

```
Input: s = "a", t = "aa"
Output: ""
Explanation: 
Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

**Constraints:**

* `m == s.length`
* `n == t.length`
* `1 <= m, n <= 10^5`
* `s` and `t` consist of uppercase and lowercase English letters.

&#x20; **Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

## Solution

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> t_dict;
        for(char c : t)
            t_dict[c]++;
       
        int required = t_dict.size(); // No. of unique characters in t
        
        vector<pair<int,char>> filtered_s;
        for(int i = 0; i < s.size(); i++)
            if(t_dict[s[i]])
                filtered_s.push_back(make_pair(i, s[i]));
        
        // two pointer sliding window
        int left = 0, right = 0, formed = 0;
        map<char, int> cur_window_count;
        
        int result[3] = {-1, 0, 0}; // length, start, end
        
        while( right < filtered_s.size())
        {
            char c = filtered_s[right].second;
            cur_window_count[c]++;
            
            if(t_dict[c] && cur_window_count[c] == t_dict[c])
                formed++;
            
            
            // Once we reach desirable window, try to reduce the window size
            // till the point where we can still meet the criteria
            while(left <= right && formed == required)
            {
                c = filtered_s[left].second;
                
                int start = filtered_s[left].first;
                int end = filtered_s[right].first;
                // save the smallest window till now
                if(result[0] == -1 || result[0] > end - start +1)
                {
                    result[0] = end - start + 1;
                    result[1] = start;
                    result[2] = end;
                }
                
                cur_window_count[c]--;
                
                if(t_dict[c] && t_dict[c] > cur_window_count[c])
                    formed--;
                
                left++;
            }
            right++;
        }
        return result[0] == -1 ? "" : s.substr(result[1], result[2]-result[1]+1);
    }
};
```
