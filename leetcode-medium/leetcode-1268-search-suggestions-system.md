# Leetcode 1268 Search Suggestions System

## Problem Statement

[https://leetcode.com/problems/search-suggestions-system/](https://leetcode.com/problems/search-suggestions-system/)

Given an array of strings `products` and a string `searchWord`. We want to design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return _list of lists_ of the suggested `products` after each character of `searchWord` is typed. 

**Example 1:**

```text
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: 
products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
```

**Example 2:**

```text
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
```

**Example 3:**

```text
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: 
[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
```

**Example 4:**

```text
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
```

**Constraints:**

* `1 <= products.length <= 1000`
* There are no repeated elements in `products`.
* `1 <= Σ products[i].length <= 2 * 10^4`
* All characters of `products[i]` are lower-case English letters.
* `1 <= searchWord.length <= 1000`
* All characters of `searchWord` are lower-case English letters.

## Solution

### Trie Based Solution

Check this link for more on [Trie](https://app.gitbook.com/@thangarajn1992/s/data-structures-and-algorithms/~/drafts/-Mb0zgvzKN7hy-TsNxtD/trie)

```cpp
// Define the character size
#define CHAR_SIZE 26
 
// A class to store a Trie node
class Trie
{
    public:
        int index;  // To Store index of key on Key Array
        Trie* character[CHAR_SIZE];
 
        // Constructor
        Trie()
        {
            this->index = -1;
            for (int i = 0; i < CHAR_SIZE; i++) {
                this->character[i] = nullptr;
            }
        }
 
        void insert(string, int);
        bool suggest(string, vector<string>&, vector<string>&);
    };
 
    // Iterative function to insert a key into a Trie
    void Trie::insert(string key, int index)
    {
        // start from the root node
        Trie* curr = this;
        for (int i = 0; i < key.length(); i++)
        {
            // create a new node if the path doesn't exist
            if (curr->character[key[i] - 'a'] == nullptr) {
                curr->character[key[i] - 'a'] = new Trie();
            }
 
            // go to the next node
            curr = curr->character[key[i] - 'a'];
        }
 
        // mark the current node as a leaf
        curr->index = index;
    }
 
    // Iterative function to search a key in a Trie. It returns true
    // if the key is found in the Trie; otherwise, it returns false
    bool Trie::suggest(string key, vector<string>& products, vector<string>&result)
    {
        // return false if Trie is empty
        if (this == nullptr) {
            return false;
        }
        Trie* curr = this;
        
        // Traverse the given key completely
        for (int i = 0; i < key.size(); i++)
        {
            // go to the next node
            curr = curr->character[key[i] - 'a'];
            // if the string is invalid (reached end of a path in the Trie)
            if (curr == nullptr) {
                return false;                
            }
        }
        
        // Now do preorder traversal to get first 3 products with same prefix
        int count = 0;
        stack<Trie *> s;
        s.push(curr);
        while(count < 3 && !s.empty())
        {
            Trie *temp = s.top();
            s.pop();
            if(temp->index != -1)
            {
                result.push_back(products[temp->index]);
                count++;
            }
            for(int i = CHAR_SIZE - 1; i >= 0; i--)
            {
                char c = i + 'a';
                if(temp->character[i] != nullptr)
                {
                    s.push(temp->character[i]);
                }
            }
        }
        while(!s.empty())
            s.pop();
        return count != 0;
    }
 
class Solution {
public:
    Trie *root = new Trie();
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size(), vector<string>());
        
        // Adding keys into the trie
        for(int i = 0; i < products.size(); i++)
            root->insert(products[i],i);
        
        for(int i = 1; i <= searchWord.size(); i++)
            root->suggest(searchWord.substr(0, i), products, result[i-1]);
        
        return result;
    }
};
```

### 

