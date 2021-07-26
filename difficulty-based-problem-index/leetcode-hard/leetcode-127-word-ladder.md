# Leetcode 127 Word Ladder

## Problem Statement

[https://leetcode.com/problems/word-ladder](https://leetcode.com/problems/word-ladder/)

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return _the **number of words** in the **shortest transformation sequence** from_ `beginWord` _to_ `endWord`_, or_ `0` _if no such sequence exists._

**Example 1:**

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: 
One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 
5 words long.
```

**Example 2:**

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: 
The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

* `1 <= beginWord.length <= 10`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 5000`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All the words in `wordList` are **unique**.

## Solution

```cpp
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    int min_ladder_length;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        min_ladder_length = INT_MAX;
        unordered_set<string> tempwordList(wordList.begin(), wordList.end());

        // DO BFS from beginword to complete the adj_list
        bfs(beginWord, tempwordList);
        
        // backtrack and find shortest path
        backtrack(beginWord, endWord, 1);
        
        return min_ladder_length != INT_MAX ? min_ladder_length : 0;
    }
    
    void bfs(string word, unordered_set<string> &wordList)
    {
        queue<string> q;
        q.push(word);
        
        //If word is in dictionary, remove it
        if(wordList.find(word) != wordList.end())
            wordList.erase(wordList.find(word));
        
        unordered_set<string> isEnqueued;
        isEnqueued.insert(word);
        
        // Each loop process one layer of BFS
        while(q.empty() == false)
        {
            vector<string> visited; 
            // Maintain visited list for each layer
            // to delete the visited nodes of this layer at 
            // end of processing all nodes in this layer.
            for(int i = q.size() - 1; i >= 0; i--)
            {
                string wd = q.front(); q.pop();            
                //find all possible neighbors for this word
                vector<string> neighbors = find_neighbors(wd, wordList);
                for(string neighbor : neighbors)
                {
                    visited.push_back(neighbor);
                    adjList[wd].push_back(neighbor);
                    if(isEnqueued.count(neighbor) == 0)
                    {
                        isEnqueued.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            
            // Remove all the words we added as part of this layer
            for(int i = 0; i < visited.size(); i++)
            {
                auto it = wordList.find(visited[i]);
                if(it != wordList.end())
                    wordList.erase(it);
            }
        }
    }
    
    vector<string> find_neighbors(string word, unordered_set<string> &wordList)
    {
        vector<string> neighbors;
        
        // Replace each letter with some other alphabet at a time,
        // and if that new word is part of WordList, then it is our neighbor
        for(int i = 0; i < word.size(); i++)
        {
            char old_char = word[i];
            for(char c = 'a'; c <= 'z'; c++)
            {
                if(c != old_char)
                {
                    word[i] = c;
                    if(wordList.find(word) != wordList.end())
                        neighbors.push_back(word);
                }
            }
            word[i] = old_char;
        }
        return neighbors;
    }
    
    void backtrack(string src, string dst, int ladder_length)
    {
        if(src == dst)
            if(ladder_length < min_ladder_length)
                min_ladder_length = ladder_length;
        
        for(int i = 0; i < adjList[src].size(); i++)
            backtrack(adjList[src][i], dst, ladder_length+1);
    }
};
```

