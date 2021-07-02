# Leetcode 997 Find the Town Judge

## Problem Statement

[https://leetcode.com/problems/find-the-town-judge/](https://leetcode.com/problems/find-the-town-judge/)

In a town, there are `n` people labelled from `1` to `n`.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody \(except for the town judge\) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled `a` trusts the person labelled `b`.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return `-1`.

**Example 1:**

```text
Input: n = 2, trust = [[1,2]]
Output: 2
```

**Example 2:**

```text
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

**Example 3:**

```text
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

**Example 4:**

```text
Input: n = 3, trust = [[1,2],[2,3]]
Output: -1
```

**Example 5:**

```text
Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```

**Constraints:**

* `1 <= n <= 1000`
* `0 <= trust.length <= 10^4`
* `trust[i].length == 2`
* `trust[i]` are all different
* `trust[i][0] != trust[i][1]`
* `1 <= trust[i][0], trust[i][1] <= n`

## Solution

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Graph based approach:
        // Condition 1:
        // Town Judge Trust nobody, it means his out-degree is 0.
        // Condition 2:
        // Everyone else trusts Judge, their out-degree is min 1.
        // Judge's in-degree should be n-1.
        
        // Algorithm: Find the node with out-degree of 0 and in-degree of n-1
        
        vector<bool> Do_I_Trust_Anyone(n+1, false); // out-degree
        vector<int> trusts_me(n+1, 0); // in-degree
        for(int trust_num = 0; trust_num < trust.size(); trust_num++)
        {
            Do_I_Trust_Anyone[trust[trust_num][0]] = true;
            trusts_me[trust[trust_num][1]]++;
        }
        
        int person = 1;
        for(; person <= n; person++)
        {
            if(Do_I_Trust_Anyone[person] == false && trusts_me[person] == n-1)
                break;
        }
        
        return (person <= n) ? person : -1;
    }
};
```

