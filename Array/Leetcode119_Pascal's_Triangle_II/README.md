---
title: "Leetcode119 Pascal's Triangle II"
date: 2018-10-02T23:20:50+08:00
slug : "Leetcode119 Pascal's Triangle II"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目论述

- 链接：

  [Leetcode119 Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/)

- 概述：

  Given a non-negative index *k* where *k* ≤ 33, return the *k* th index row of the Pascal's triangle.

  Note that the row index starts from 0.

  ![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
  In Pascal's triangle, each number is the sum of the two numbers directly above it.

  **Example:**

  ```
  Input: 3
  Output: [1,3,3,1]
  ```

  **Follow up:**

  Could you optimize your algorithm to use only *O*(*k*) extra space?

***


## 思考分析

​	这道题比较简单，注意到 *k* 是zero-based的，在杨辉三角中的第 *k* 层的 *k+1* 个数正好是组合数 *C(k,m),	m = 0, 1, 2, …, k-1* 。

​	而求组合数是简单的。

​	要注意的是，`int`整型的取值可能会取不到那么大的整数，因而改用`long long int`。

------

## code(c++)

solution (0ms)

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;
        int k = 0;
        long long int element = 1;
        while(k <= rowIndex) {
            answer.push_back(element);
            k++;
            element = element * (rowIndex+1-k) / k;
        }
        return answer;
    }
};
```

