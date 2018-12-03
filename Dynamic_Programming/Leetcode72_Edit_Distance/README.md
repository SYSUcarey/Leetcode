---
title: "Leetcode72 Edit Distance"
date: 2018-12-02T14:50:53+08:00
slug : "Leetcode72 Edit Distance"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---
# Table of Contents

- [题目](#%E9%A2%98%E7%9B%AE)

- [思考](#%E6%80%9D%E8%80%83)

- [解法](#%E8%A7%A3%E6%B3%95)

  

Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc.go)

## 题目

- 链接：

  [Leetcode72 Edit Distance](https://leetcode.com/problems/edit-distance/description/) 

- 难度：

  **Difficulty: Hard** 

  **Acceptance: 35.1%**  

- 概述：

  Given two words *word1* and *word2*, find the minimum number of operations required to convert *word1* to *word2*.

  You have the following 3 operations permitted on a word:

  1. Insert a character
  2. Delete a character
  3. Replace a character

  **Example 1:**

  ```
  Input: word1 = "horse", word2 = "ros"
  Output: 3
  Explanation: 
  horse -> rorse (replace 'h' with 'r')
  rorse -> rose (remove 'r')
  rose -> ros (remove 'e')
  ```

  **Example 2:**

  ```
  Input: word1 = "intention", word2 = "execution"
  Output: 5
  Explanation: 
  intention -> inention (remove 't')
  inention -> enention (replace 'i' with 'e')
  enention -> exention (replace 'n' with 'x')
  exention -> exection (replace 'n' with 'c')
  exection -> execution (insert 'u')
  ```

------

## 思考


- 这道题因为是在分组动态规划下找的，所以相当于作弊给了自己一个提示，首先我们要设计动态规划下的状态，然后再考虑状态转移方程。

- 参考课堂上讲的几道与字符串处理动态规划相关的习题的解决思路，对字符串状态的定义，`d[i][j]` 应该表示为将 `word1` 长度为 `i` 的前缀子串 个字符转换成 `word2` 长度为 `j` 的前缀子串所需要的最小操作数。那么状态总共有 `(m+1)·(n+1)`个，其中 `m, n` 是两个输入字符串的长度，我们需要的解为 `d[m][n]` 。

- 接下来考虑动态规划的状态转移方程，我们得从题目中给出的三种字符串操作方法入手进行分析：

  - `replace` 替换操作：

    考虑`d[i][j]` 和 `d[i-1][j-1]` 的关系，如果：

    - `str1[i-1] == str2[j-1]` 也即最后一个字符相等，不用操作就可以将 `d[i-1][j-1]` 状态转换成 `d[i][j]`状态。
    - `str1[i-1] != str2[j-1]`也即最后一个字符不相等，需要一个替换操作就可以将 `d[i-1][j-1]`状态转换成`d[i][j]`状态。

  -  `insert` 添加操作：

    考虑 `d[i][j]` 和 `d[i][j-1]` 的关系，显然我们只用一个添加操作，在最后添加 `str2[j-1]` 字符就可以将 `d[i][j-1]` 状态转换成 `d[i][j]` 状态。

  -  `remove` 删除操作：

    考虑 `d[i][j]` 和 `d[i-1][j]` 的关系。显然，我们可以一开始将 `str1[i-1]` 给删除，那么 `str1` 就只有 `i-1` 的长度，这时候我们就可以把状态 `d[i][j]` 的求解转换成状态 `d[i-1][j]`。

- 状态转移方程：

$$
d[i,j] = min
\begin{cases}
d[i-1][j-1],\quad if \; str1[i-1] == str2[j-1] \\
d[i-1][j-1]+1, \quad if  \;  str1[i-1] != str2[j-1] \\
d[i][j-1]+1\\
d[i-1][j]+1\\
\end{cases}
$$

------

## 解法

c++ Solution 4ms beats 100%
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 <= 0) return size2;
        if(size2 <= 0) return size1;
        int d[size1+1][size2+1];
        for(int i = 0; i <= size1; i++) {
            d[i][0] = i;
        }
        for(int j = 0; j <= size2; j++) {
            d[0][j] = j;
        }
        int min1, min2, min3;
        for(int i = 1; i <= size1; i++) {
            for(int j = 1; j <= size2; j++) {
                // replace operation
                if(word1[i-1] == word2[j-1]) min1 = d[i-1][j-1];
                else min1 = d[i-1][j-1] + 1;
                // insert operation
                min2 = d[i][j-1] + 1;
                // remove operation
                min3 = d[i-1][j] + 1;
                d[i][j] = min(min1, min2);
                d[i][j] = min(d[i][j], min3);
            }
        }
        return d[size1][size2];
    }
};
```

