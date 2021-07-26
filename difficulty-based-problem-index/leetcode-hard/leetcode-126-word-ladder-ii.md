# Leetcode 126 Word Ladder II

## Problem Statement

[https://leetcode.com/problems/word-ladder-ii/](https://leetcode.com/problems/word-ladder-ii/)

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return _all the **shortest transformation sequences** from_ `beginWord` _to_ `endWord`_, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words_ `[beginWord, s1, s2, ..., sk]`.

**Example 1:**

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

* `1 <= beginWord.length <= 5`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 1000`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All the words in `wordList` are **unique**.

## Solution

**Algorithm**

1. Store the words present in `wordList` in an unordered set so that the words can be efficiently removed during the breadth-first search.
2. Perform the BFS, and add the edges to the adjacency list `adjList`. Also once a level is finished remove the `visited` words from the `wordList`.
3. Start from `beginWord` and while keep tracking of the current path as `currPath` traverse all the possible paths, whenever the path leads to the `endWord` store the path in `shortestPaths`.

```cpp
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)     {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        
        if(copiedWordList.find(endWord) == copiedWordList.end())
            return shortestPaths;
        
        // build the DAG using BFS
        bfs(beginWord, copiedWordList);
        
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);
        
        return shortestPaths;
    }

    void bfs(string beginWord, unordered_set<string> wordList) {
        queue<string> q;
        q.push(beginWord);
        
        // If beginWord is present in WordList, remove it
        // It will form the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }
        
        // Enqueued is used to track new words, only new words needs to 
        // be added in the queue for BFS.
        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while (!q.empty())  {
            // visited will store the words of current layer
            // so that we can remove these words visited in this layer
            // at the end of this layer.
            vector<string> visited;
            
            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front(); 
                q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    // add the edge from currWord to word in the list
                    adjList[currWord].push_back(word);
                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            // removing the words of the previous layer
            // We are removing this after completing one full layer,
            // because two nodes at this layer may have same neighbor at next layer
            // thats why we can't remove the neighbors after processing for one node.
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    vector<string> findNeighbors(string &word, unordered_set<string>& wordList) {
        vector<string> neighbors;
        
        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];   
            
            // replace the i-th character with all letters from a to z 
            // except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                if(c != oldChar)
                {
                    word[i] = c;
                    if(wordList.count(word))
                        neighbors.push_back(word);
                }
            }
            word[i] = oldChar;
        }
        return neighbors;
    }
    
    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }  
};  
```

