# Leetcode 677 Map Sum Pairs

## Problem Statement

[https://leetcode.com/problems/map-sum-pairs/](https://leetcode.com/problems/map-sum-pairs/)

Implement the `MapSum` class:

* `MapSum()` Initializes the `MapSum` object.
* `void insert(String key, int val)` Inserts the `key-val` pair into the map. If the `key` already existed, the original `key-value` pair will be overridden to the new one.
* `int sum(string prefix)` Returns the sum of all the pairs' value whose `key` starts with the `prefix`.

**Example 1:**

```text
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
```

**Constraints:**

* `1 <= key.length, prefix.length <= 50`
* `key` and `prefix` consist of only lowercase English letters.
* `1 <= val <= 1000`
* At most `50` calls will be made to `insert` and `sum`.

## Solution

### My Working Code

```cpp
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> maps;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        maps[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(auto it = maps.begin(); it != maps.end(); it++)
        {
            if(it->first[0] < prefix[0])
                continue;
            else if(it->first[0] > prefix[0])
                return sum;
            else if(it->first.size() < prefix.size())
                continue;
            else 
            {
                int index = 0;
                for(; index < prefix.size() && prefix[index] == it->first[index] ; index++);
                if(index == prefix.size())
                    sum += it->second;
            }
        }
        return sum;
    }
};
```

### Prefix Sum Approach

```cpp
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> maps;
    map<string, int> prefix_sum;
    
    MapSum() { 
    }
    
    void insert(string key, int val) {
        const int delta = val - maps[key];
        maps[key] = val;
        string prefix = "";
        for(const char &c : key)
        {
            prefix += c;
            prefix_sum[prefix] += delta;
        }
    }
    
    int sum(string prefix) {
        return prefix_sum[prefix];
    }
};
```

### Trie Approach

```cpp
class TrieNode{
public:
    int score;
    map<char, TrieNode*> children;
};

class MapSum {
public:
    map<string, int> maps;
    TrieNode root;
    MapSum() {  
    }
    
    void insert(string key, int val) {
        const int delta = val - maps[key];
        maps[key] = val;
        TrieNode *cur = &root;
        cur->score += delta;
        for(const char c : key)
        {
            if(cur->children[c] == nullptr)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->score += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *cur = &root;
        for(const char &c: prefix)
        {
            cur = cur->children[c];
            if(cur == nullptr)
                return 0;
        }
        return cur->score;
    }
};
```

