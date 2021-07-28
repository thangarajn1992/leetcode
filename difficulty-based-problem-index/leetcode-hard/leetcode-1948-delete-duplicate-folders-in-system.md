# Leetcode 1948 Delete Duplicate Folders in System

## Problem Statement

[https://leetcode.com/problems/delete-duplicate-folders-in-system/](https://leetcode.com/problems/delete-duplicate-folders-in-system/)

Due to a bug, there are many duplicate folders in a file system. You are given a 2D array `paths`, where `paths[i]` is an array representing an absolute path to the `ith` folder in the file system.

* For example, `["one", "two", "three"]` represents the path `"/one/two/three"`.

Two folders \(not necessarily on the same level\) are **identical** if they contain the **same non-empty** set of identical subfolders and underlying subfolder structure. The folders **do not** need to be at the root level to be identical. If two or more folders are **identical**, then **mark** the folders as well as all their subfolders.

* For example, folders `"/a"` and `"/b"` in the file structure below are identical. They \(as well as their subfolders\) should **all** be marked:
  * `/a`
  * `/a/x`
  * `/a/x/y`
  * `/a/z`
  * `/b`
  * `/b/x`
  * `/b/x/y`
  * `/b/z`
* However, if the file structure also included the path `"/b/w"`, then the folders `"/a"` and `"/b"` would not be identical. Note that `"/a/x"` and `"/b/x"` would still be considered identical even with the added folder.

Once all the identical folders and their subfolders have been marked, the file system will **delete** all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.

Return _the 2D array_ `ans` _containing the paths of the **remaining** folders after deleting all the marked folders. The paths may be returned in **any** order_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder1.jpg)

```text
Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
Output: [["d"],["d","a"]]
Explanation: 
The file structure is as shown.
Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both 
contain an empty folder named "b".
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder2.jpg)

```text
Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
Output: [["c"],["c","b"],["a"],["a","b"]]
Explanation: 
The file structure is as shown. 
Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because 
they both contain an empty folder named "y".
Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted 
because they were not marked beforehand.
```

**Example 3:** ![](https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder3.jpg)

```text
Input: paths = [["a","b"],["c","d"],["c"],["a"]]
Output: [["c"],["c","d"],["a"],["a","b"]]
Explanation: 
All folders are unique in the file system.
Note that the returned array can be in a different order as the order does not matter.
```

**Example 4:** ![](https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder4_.jpg)

```text
Input: paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"]]
Output: []
Explanation: 
The file structure is as shown.
Folders "/a/x" and "/b/x" (and their subfolders) are marked for deletion because they 
both contain an empty folder named "y".
Folders "/a" and "/b" (and their subfolders) are marked for deletion because they 
both contain an empty folder "z" and the folder "x" described above.
```

**Example 5:** ![](https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder5_.jpg)

```text
Input: paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"],["b","w"]]
Output: [["b"],["b","w"],["b","z"],["a"],["a","z"]]
Explanation: 
This has the same structure as the previous example, except with the added "/b/w".
Folders "/a/x" and "/b/x" are still marked, but "/a" and "/b" are no longer marked
because "/b" has the empty folder named "w" and "/a" does not.
Note that "/a/z" and "/b/z" are not marked because the set of identical subfolders must 
be non-empty, but these folders are empty.
```

**Constraints:**

* `1 <= paths.length <= 2 * 10^4`
* `1 <= paths[i].length <= 500`
* `1 <= paths[i][j].length <= 10`
* `1 <= sum(paths[i][j].length) <= 2 * 10^5`
* `path[i][j]` consists of lowercase English letters.
* No two paths lead to the same folder.
* For any folder not at the root level, its parent folder will also be in the input.

## Solution

### Trie Based Approach

1. **Build Tree**: Build a folder tree based on the `paths`. The process is similar to the Trie building process.
2. **Dedupe**: Use post-order traversal to visit all the nodes. If we've seen the subfolder structure before, mark the node as deleted.
3. **Generate Paths**: DFS to generate the output. We skip the nodes that have been deleted.

To ensure we visit the sub-folders in the same order,  we declare `Node::next` as`map`instead of`unordered map`

**Complexity Analysis**

Assume `N` is the number of folders, `W` is the maximum length of folder name, `D` is the deepest folder depth, and `C` is the maximum number of direct **c**hild folders.

1. **Build Tree**: We need to add all the `N` folders, each of which takes `O(DWlogC)` time. So overall it takes `O(NDWlogC)` time, and `O(NW)` space.
2. **Dedupe**: We traverse the `N` folders in post-order. The maximum length of `subfolder` structure string is roughly `O(NW)`, so each node visit need `O(NW)` time to check if it's a duplicate. The overall time complexity is `O(N^2 * W)` and the space complexity is `O(N^2 * W)`.
3. **Generate Paths**: In the worst case we traverse the `N` nodes again. Each visit takes `O(W)` time to update the current `path` and `O(DW)` time to update the answer. So overall the time complexity is `O(NDW)` and space complexity is `O(DW)` for the temporary `path`.

```cpp
struct Node {
    string name;
    map<string, Node*> next; // mapping from folder name to the corresponding child node.
    bool del = false; // whether this folder is deleted.
    Node(string n = "") : name(n) {}
};

class Solution {
    // mapping from subfolder structure string to the first occurrence node.
    unordered_map<string, Node*> seen; 
    vector<vector<string>> ans;
    vector<string> path;
    
    // Given a path, add nodes to the folder tree. 
    // This is similar to the Trie build process.
    void addPath(Node *node, vector<string> &path) 
    { 
        for (auto &s : path) 
        {
            if (node->next.count(s) == 0) 
                node->next[s] = new Node(s);
            node = node->next[s];
        }
    }
    
    // post-order traversal to dedupe. 
    // If we've seen the subfolder structure before, mark it as deleted.
    string dedupe(Node *node) 
    { 
        string subfolder;
        for (auto &[name, next] : node->next) 
        {
            subfolder += dedupe(next);
        }
        // Only non-leaf nodes to be considered
        if (subfolder.size())  
        { 
            // if we've seen this subfolder structure before, mark them as deleted.
            if (seen.count(subfolder)) 
            { 
                seen[subfolder]->del = node->del = true;
            } else {
                seen[subfolder] = node; // otherwise, add the mapping
            }
        }
        // return the folder structure string of this node.
        return "(" + node->name + subfolder + ")"; 
    }

    void getPath(Node *node) 
    {
        if (node->del) 
            return; // if the current node is deleted, skip it.
        path.push_back(node->name);
        ans.push_back(path);
        for (auto &[name, next] : node->next) 
        {
            getPath(next);
        }
        path.pop_back();
    }
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        for (auto &path : paths) 
            addPath(&root, path);
        
        dedupe(&root);
        
        for (auto &[name, next] : root.next) 
            getPath(next);
        
        return ans;
    }
};
```

