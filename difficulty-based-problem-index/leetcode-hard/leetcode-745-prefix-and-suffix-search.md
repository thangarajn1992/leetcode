# Leetcode 745 Prefix and Suffix Search

## Problem Statement

[https://leetcode.com/problems/prefix-and-suffix-search/](https://leetcode.com/problems/prefix-and-suffix-search/)

Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the `WordFilter` class:

* `WordFilter(string[] words)` Initializes the object with the `words` in the dictionary.
* `f(string prefix, string suffix)` Returns _the index of the word in the dictionary_ which has the prefix `prefix` and the suffix `suffix`. If there is more than one valid index, return **the largest** of them. If there is no such word in the dictionary, return `-1`.

**Example 1:**

```text
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and 
suffix = 'e".
```

**Constraints:**

* `1 <= words.length <= 15000`
* `1 <= words[i].length <= 10`
* `1 <= prefix.length, suffix.length <= 10`
* `words[i]`, `prefix` and `suffix` consist of lower-case English letters only.
* At most `15000` calls will be made to the function `f`.

## Explanation

 **Trie of Suffix Wrapped Words**

Consider the word `'apple'`. For each suffix of the word, we could insert that suffix, followed by `'{'` , followed by the word, all into the trie. { is used because its ascii value is z+1.

For example, we will insert `'{apple', 'e{apple', 'le{apple', 'ple{apple', 'pple{apple', 'apple{apple'` into the trie. Then for a query like `prefix = "ap", suffix = "le"`, we can find it by querying our trie for `le{ap`.

## Solution

```cpp
#define ALPHABET_SIZE 26
class TrieNode {
    public:
        int weight;
        TrieNode *children[ALPHABET_SIZE + 1];
    
        TrieNode() {
            weight = 0;
            for(int i = 0; i <= ALPHABET_SIZE; i++)
              children[i] = NULL; 
        }
};

class WordFilter {
    TrieNode *root;
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for(int weight = 0; weight < words.size(); weight++)
        {
            // '{' is used because its ASCII value is z+1
            string word = words[weight] + "{";
            for(int i = 0; i < word.size(); i++) 
            {
                TrieNode *cur = root;
                cur->weight = weight;
                for(int j = i; j < 2*word.size() - 1; j++)
                {
                    int k = word.at(j % word.size()) - 'a';
                    if(cur->children[k] == NULL)
                        cur->children[k] = new TrieNode();
                    cur = cur->children[k];
                    cur->weight = weight;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode *cur = root;
        string c = suffix + '{' + prefix;
        for ( char letter : c)
        {
            if(cur->children[letter - 'a'] == NULL) return -1;
            cur = cur->children[letter - 'a'];
        }
        return cur->weight;
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
```

