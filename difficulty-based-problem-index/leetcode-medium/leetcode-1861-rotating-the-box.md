# Leetcode 1861 Rotating the Box

## Problem Statement

[https://leetcode.com/problems/rotating-the-box/](https://leetcode.com/problems/rotating-the-box/)

You are given an `m x n` matrix of characters `box` representing a side-view of a box. Each cell of the box is one of the following:

* A stone `'#'`
* A stationary obstacle `'*'`
* Empty `'.'`

The box is rotated **90 degrees clockwise**, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity **does not** affect the obstacles' positions, and the inertia from the box's rotation **does not** affect the stones' horizontal positions.

It is **guaranteed** that each stone in `box` rests on an obstacle, another stone, or the bottom of the box.

Return _an_ `n x m` _matrix representing the box after the rotation described above_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png)

```text
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png)

```text
Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png)

```text
Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
```

**Constraints:**

* `m == box.length`
* `n == box[i].length`
* `1 <= m, n <= 500`
* `box[i][j]` is either `'#'`, `'*'`, or `'.'`.

## Solution

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> result(box[0].size(),vector<char>(box.size(),'.'));
        for(int i = 0; i < box.size(); i++)
        {
            for(int j = box[i].size() - 1, k = box[i].size() - 1; j >= 0; j--)
            {
                 switch(box[i][j]){
                     case '*':
                         k = j;
                         result[k--][box.size() - i - 1] = '*';
                         break;
                     case '#':
                         result[k--][box.size() - i - 1] = '#';
                         break;
                 }      
            }
        }
        return result;
    }
};
```

