---
title: "Leetcode943 Find the Shortest Superstring"
date: 2018-12-09T16:00:53+08:00
slug : "Leetcode943 Find the Shortest Superstring"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---
# Table of Contents

- [题目](#%E9%A2%98%E7%9B%AE)

- [思考](#%E6%80%9D%E8%80%83)

- [解法](#%E8%A7%A3%E6%B3%95)


Created by [gh-md-toc](https://github.com/ekalinin/github-markdown-toc.go)

***

## 题目

- 链接：

  [Leetcode943 Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/description/) 

- 难度：

  **Difficulty: Hard** 

  **Acceptance: 29.1%**  

- 概述：

  Given an array A of strings, find any smallest string that contains each string in `A` as a substring.

  We may assume that no string in `A` is substring of another string in `A`.

   

  **Example 1:**

  ```
  Input: ["alex","loves","leetcode"]
  Output: "alexlovesleetcode"
  Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
  ```

  **Example 2:**

  ```
  Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
  Output: "gctaagttcatgcatc"
  ```

   

  **Note:**

  1. `1 <= A.length <= 12`
  2. `1 <= A[i].length <= 20`

------

## 思考


- 这道题感觉是一个变相的TSP问题，不过最后不用回到开始的起点，只需要我们遍历完所有的点求最短路。

- 那么 A 中的每一个字符串就相当于图中的一个点，i -> j 之间的距离就是将字符串word[j] 添加到 word[i] 后增加的长度。那么这道题绘制的图是一个有向完全图，不限制起点和终点求解一个TSP问题，将图中所有的点遍历使得走的距离最短的路径就是解。

- 我们首先求出任意两点，点 i 到 点 j 的距离。例如说 `gcta` -> `ctaagt` ，我们计算 `gcta` 的字符串尾 和 `ctaagt` 的字符串头最大有多少个重叠的元素，这里`cta` 是重叠的最长串。那么最大重叠长度为3，也就是说定义的距离 `gcta` -> `ctaagt` 为 `len("ctaagt")-3 = 6-3 = 3` 。注意的是点 i 到 点 j 的距离与点 j 到点 i 的距离一般是不相同的，这是一个有向图。另外由于每个点只到一次，点 i 到其自身的距离我们不定义，为了后面循环遍历方便，我们设置为21，大于任意一个字符串的长度。

- 接着我们用 dp 算法去解决这个 TSP 问题。因为还要记录路径，我们定义两个数组。

  ```c++
  vector<vector<int>> dp(1 << n, vector<int>(n, 20*12+1));
  vector<vector<int>> praent(1 << n, vector<int>(n, -1));
  ```

  dp数组表示动态规划里的状态， `dp[s][i]` ，表示遍历完 s 中所有节点的，且以 i 节点作为结束的最短路径长度，其中 s 是一个 32-bit 二进制表示数，用来表示节点集合。例如说 `dp[1031][2]` ，`s = 1031 = 1024+4+2+1 = 0x10000000111`，表示节点集合 `{0，1，2，10}`。`dp[1031][2]` 则表示遍历完节点集合 `{0, 1, 2, 10}`且以节点2结束的最短路径的长度。因为 int 有 32位，除去符号位还有31位，而题目中规定了`1 <= A.length <= 12`，因此是足够表示的。

  parent数组表示对应最短路径下的父节点号。例如说 `dp[1031][2]` ，表示遍历完节点集合 `{0, 1, 2, 10}`且以节点 2 结束的最短路径中节点 2 的父节点号。初始标记为-1，没有父亲节点。

- 对dp状态初始化，显然如果我们遍历的节点集合只有一个，那么长度就是这个节点字符串的长度。也即是：`dp[2^i][i]=A[i].length()`

- 那么状态转移方程：

  ```
  dp[s][i] = min{dp[s-2^j][j] + dist[j][i]}
  ```

- 算法的时间复杂度：**O(n^2 · 2^n)** 

- 算法的空间复杂度：**O(n · 2^n)** 



------

## 解法

c++ Solution 20ms beats 92%
```c++
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        int dist[n][n];
        for(int i = 0; i < n; i++) {
            dist[i][i] = 20+1;
        }
        for(int i = 0; i < n; i++) {
        	for(int j = i+1; j < n; j++) {
        		dist[i][j] = cost(A[i], A[j]);
                dist[j][i] = cost(A[j], A[i]);
        	}
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, 20*12+1));
        vector<vector<int>> praent(1 << n, vector<int>(n, -1));

        // init
        for(int i = 0; i < n; i++) 
            dp[1 << i][i] = A[i].length();

        // dp
        for(int s = 1; s < (1 << n); s++) {
            for(int i = 0; i < n; i++) {
                if(!(s & (1<<i))) continue;
                int prev = s - (1<<i);
                for(int j = 0; j < n; j++) {
                    if(dp[prev][j] + dist[j][i] < dp[s][i]) {
                        dp[s][i] = dp[prev][j] + dist[j][i];
                        praent[s][i] = j;
                    }
                }
            }
        }

        // find path
        auto it = min_element(dp.back().begin(), dp.back().end());
        int cur = it - dp.back().begin();
        int s = (1 << n) - 1;
        string ans;
        while(s) {
            int prev = praent[s][cur];
            if(prev < 0) ans = A[cur] + ans;
            else ans = A[cur].substr(A[cur].length()-dist[prev][cur]) + ans;
            s &= ~(1 << cur);
            cur =prev;
        }
        return ans;
    }   

private:
    int cost(const string& str1, const string& str2) {
        int a = str1.length(), b = str2.length();
        int _cost = b;
        for(int k = 1; k <= min(a, b); k++) {
            if(str1.substr(a - k) == str2.substr(0, k)) {
                _cost = b - k;
            }
        }
        return _cost;
    }

};



```

