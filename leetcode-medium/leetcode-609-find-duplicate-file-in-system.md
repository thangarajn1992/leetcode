# Leetcode 609 Find Duplicate File in System

## Problem Statement

[https://leetcode.com/problems/find-duplicate-file-in-system/](https://leetcode.com/problems/find-duplicate-file-in-system/)

Given a list `paths` of directory info, including the directory path, and all the files with contents in this directory, return _all the duplicate files in the file system in terms of their paths_. You may return the answer in **any order**.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

* `"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"`

It means there are `n` files `(f1.txt, f2.txt ... fn.txt)` with content `(f1_content, f2_content ... fn_content)` respectively in the directory "`root/d1/d2/.../dm"`. Note that `n >= 1` and `m >= 0`. If `m = 0`, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

* `"directory_path/file_name.txt"`

**Example 1:**

```text
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)",
                "root/c 3.txt(abcd)",
                "root/c/d 4.txt(efgh)",
                "root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],
         ["root/a/1.txt","root/c/3.txt"]]
```

**Example 2:**

```text
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)",
                "root/c 3.txt(abcd)",
                "root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
```

**Constraints:**

* `1 <= paths.length <= 2 * 10^4`
* `1 <= paths[i].length <= 3000`
* `1 <= sum(paths[i].length) <= 5 * 10^5`
* `paths[i]` consist of English letters, digits, `'/'`, `'.'`, `'('`, `')'`, and `' '`.
* You may assume no files or directories share the same name in the same directory.
* You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

## Solution

```cpp
class Solution {
public:
    static inline void parse(const vector<string>& paths, unordered_map<string, vector<string>> &files) {
        for (const auto &path : paths) {
            int space = path.find(' ');
            auto basename = path.substr(0, space);
            
            while (space != string::npos) {
                auto start = path.find('(', space);
                auto end = path.find(')', start);
                files[path.substr(start + 1, end - start - 1)].emplace_back(basename + "/" + path.substr(space + 1, start - space - 1));
                space = path.find(' ', end);
            }
        }
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        parse(paths, files);
        
        vector<vector<string>> result;
        for (auto &p : files) {
            if (p.second.size() > 1) {
                result.emplace_back(move(p.second));
            }
        }
        return result;
    }
};
```

