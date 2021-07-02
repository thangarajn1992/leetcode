# Leetcode 1910 Remove All Occurrences of a Substring

## Problem Statement

[https://leetcode.com/problems/remove-all-occurrences-of-a-substring/](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)

Given two strings `s` and `part`, perform the following operation on `s` until **all** occurrences of the substring `part` are removed:

* Find the **leftmost** occurrence of the substring `part` and **remove** it from `s`.

Return `s` _after removing all occurrences of_ `part`.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**

```text
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
```

**Example 2:**

```text
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
```

**Constraints:**

* `1 <= s.length <= 1000`
* `1 <= part.length <= 1000`
* `s`​​​​​​ and `part` consists of lowercase English letters.

## Solution

### My Solution - Straight Forward

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool found = true;
        while(s.size() >= part.size() && found)
        {
            found = false;
            for(int i = 0; i + part.size() <= s.size() ; i++)
            {
                int j,k;
                for(j = 0, k = i; j < part.size() && s[k] == part[j]; j++, k++);
                if(j == part.size())
                {
                    s.erase(i, part.size());
                    found = true;
                    break;
                }
            }
        }
        return s;
    }
};
```

### Stack Approach

```cpp
class Solution {
public:
	string removeOccurrences(string s, string part)
	{
		string ans;
		for(char c:s)
		{
			ans.push_back(c);
			if(ans.size() >= part.size() && ans.substr(ans.size() - part.size()) == part)
			{
				int m = part.size();
				while(m--)
					ans.pop_back();
			}
		}
		return ans;
	}
};
```

