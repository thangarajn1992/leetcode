# Leetcode 336 Palindrome Pairs

## Problem Statement

[https://leetcode.com/problems/palindrome-pairs/](https://leetcode.com/problems/palindrome-pairs/)

Given a list of **unique** words, return all the pairs of the **distinct** indices `(i, j)` in the given list, so that the concatenation of the two words `words[i] + words[j]` is a palindrome.

**Example 1:**

```text
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
```

**Example 2:**

```text
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
```

**Example 3:**

```text
Input: words = ["a",""]
Output: [[0,1],[1,0]]
```

**Constraints:**

* `1 <= words.length <= 5000`
* `0 <= words[i].length <= 300`
* `words[i]` consists of lower-case English letters.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            // For empty string handling
            if(mp.count("") && !words[i].empty() && is_palindrome(words[i]))
                result.push_back({i, mp[""]});
            
            string left, right;
            for(int j = 0; j < words[i].size(); j++)
            {
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                if(mp.count(left) && mp[left] != i && is_palindrome(right))
                    result.push_back({i, mp[left]});
                if(mp.count(right) && mp[right] != i && is_palindrome(left))
                    result.push_back({mp[right], i});
            }
        }
        return result;
    }
    
    bool is_palindrome(const string &s) const
    {
        const int n = s.size();
        for(int i = 0 ; i < n/2; i++)
            if(s[i] != s[n-1-i])
                return false;
        return true;
    }
};
```

