---
title: "Leetcode74 Search a 2D Matrix"
date: 2018-10-04T21:22:32+08:00
slug : "Leetcode74 Search a 2D Matrix"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目论述

- 链接：

  [Leetcode74 Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

- 概述：

  Write an efficient algorithm that searches for a value in an *m* x *n* matrix. This matrix has the following properties:

  - Integers in each row are sorted from left to right.
  - The first integer of each row is greater than the last integer of the previous row.

  **Example 1:**

  ```
  Input:
  matrix = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
  ]
  target = 3
  Output: true
  ```

  **Example 2:**

  ```
  Input:
  matrix = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
  ]
  target = 13
  Output: false
  ```

------

## 思考分析

​	这道题比较简单，注意到这个m*n矩阵中每一行都是左小右大排序，且下一行的数都比上一行的数要大。

​	那么给定`target`，我们只要从上到下比较每一行的最后一项即可。

​	如果这最后一项比`target`小，那么这一行就都比`target`要小；如果出现第一个最后一项是大于等于`target`的，那么`target`只有可能出现在这一行，下面行的数都比这个最后一项大，也就比`target`大，故不可能出现`target`。这样我们就找到了`target`可能出现在的行。复杂度O(m)。

​	然后再遍历这一行n个数，判断`target`是否出现在这一行。复杂度O(n)。

​	这个算法复杂度O(m+n)。

------

## code(c++)

solution (8ms)

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() <= 0) return false;
        if(matrix[0].size() <= 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++) {
            if(matrix[i][col-1] < target) continue;
            for(int j = col-1; j >= 0; j--) {
                if(matrix[i][j] == target) return true;
            }
            return false;
        }
        return false;
    }
};
```

