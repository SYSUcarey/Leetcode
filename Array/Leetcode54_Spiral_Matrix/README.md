---
title: "Leetcode 54 Spiral Matrix"
date: 2018-11-18T22:50:53+08:00
slug : "Leetcode 54 Spiral Matrix"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---
Table of Contents
=================

* [题目](#%E9%A2%98%E7%9B%AE)
* [思考](#%E6%80%9D%E8%80%83)
* [解法](#%E8%A7%A3%E6%B3%95)
  * [<strong>Solution</strong>](#solution)
  * [<strong>code(c\+\+)</strong>](#code\(c++\))

Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc.go)

## 题目

- 链接：

  [Leetcode 54 Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/)

- 难度：

  **Difficulty: Medium** 

  **Acceptance: 28.7%**  

  

- 概述：

  Given a matrix of *m* x *n* elements (*m* rows, *n* columns), return all elements of the matrix in spiral order.

  **Example 1:**

  ```
  Input:
  [
   [ 1, 2, 3 ],
   [ 4, 5, 6 ],
   [ 7, 8, 9 ]
  ]
  Output: [1,2,3,6,9,8,7,4,5]
  ```

  **Example 2:**

  ```
  Input:
  [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9,10,11,12]
  ]
  Output: [1,2,3,4,8,12,11,10,9,5,6,7]
  ```

------

## 思考

**分析1：**

- 这道题让我们从外到内，顺时针遍历一个二维数组，就像螺旋一样从外走到里，直到剩下单行或者单列（因为这可以不是一个正方形，螺旋到最后不一定是一个点）。
- 那么我们可以考虑一层一层地去遍历，先把最外面那一层的数字给遍历掉，去掉这些数字后，我们发现剩下的是一个更小的长方形，我们可以一样的方法去解决这个更小的长方形。
- 那么对于一个m*n的数组矩阵，如果以左上角作为起点的话，遍历矩阵的最外层时，我们可以容易地发现：
  - 先是向右遍历n-1步，然后向下遍历m-1步，然后向左遍历n-1步，然后向上遍历m-2步，回到下一层起点的左边。
  - 如果m=1或者n=1的话，就相当于只有一行或一列，这样就只存在一次向右或向下的遍历，遍历n步或m步。
- 为了更好地进行下一层的遍历，我们不如将起点设置为左上角的左边一格，那样每次遍历完最外层相当于又回到了下一次遍历的起点。这样的话，就是向右遍历n步，向下m-1步，向左n-1步，向上遍历m-2步。

------

## 解法

### **Solution**

- 根据分析1中的思路，获取矩阵的 row 和 col，设置起点 (x,y) = (0, -1)
- 当 `row > 0 && col > 0`时，我们进行循环最外层的遍历：
  - 从起点往右移动 col 步；
  - 往下移动 row -1 步（如果 row = 1，只有一行，就相当于没移动）
  - 如果 row > 1，多于一行，往左移动 col - 1 步
  - 如果 col > 1，多于一列，往上移动 row-2 步
- 遍历完最外层的循环，`row -= 2，col -= 2`。矩阵的宽高变化了，进行下一层循环。
- 根据上述的算法，算法复杂度为**O(m·n)**。 

### **code(c++)**

```c++
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        // empty array
        int row = matrix.size();
        if(row == 0) return answer;
        int col = matrix[0].size();
        if(col == 0) return answer;

        // (x,y) is on the left side of the start point
        int x = 0, y = -1;
        while(row > 0 && col > 0) {
            // move right col times
            for(int i = 1; i <= col; i++) {
                y++;
                answer.push_back(matrix[x][y]);
            }
            
            // move down (row-1) times
            for(int i = 1; i <= row-1; i++) {
                x++;
                answer.push_back(matrix[x][y]);
            }

            // move left (col-1) times if row > 1
            if(row > 1) {
                for(int i = 1; i <= col-1; i++) {
                    y--;
                    answer.push_back(matrix[x][y]);
                }
            }

            //move up (row-2) times if col > 1
            if(col > 1) {
                for(int i = 1; i <= row-2; i++) {
                    x--;
                    answer.push_back(matrix[x][y]);
                }
            }
            row -= 2;
            col -= 2;
        }
        return answer;
    }
};
```





