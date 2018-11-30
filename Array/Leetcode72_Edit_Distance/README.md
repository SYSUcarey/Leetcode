---
title: "Leetcode72 Edit Distance"
date: 2018-11-30T14:50:53+08:00
slug : "Leetcode72 Edit Distance"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---
# Table of Contents

- [题目](#%E9%A2%98%E7%9B%AE)
- [思考](#%E6%80%9D%E8%80%83)
- [解法](#%E8%A7%A3%E6%B3%95)
  - [<strong>Solution</strong>](#solution)
  - [<strong>Code</strong>](#code)

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

**分析1：**

- TODO

------

## 解法

### **Solution**

- TODO


### **Code**

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

