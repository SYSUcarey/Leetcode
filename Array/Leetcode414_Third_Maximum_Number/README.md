---
title: "Leetcode414 Third Maximum Number"
date: 2019-01-17T18:10:53+08:00
slug : "Leetcode414 Third Maximum Number"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode414 Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) 

- 概述：

  Given a **non-empty** array of integers, return the **third** maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

  **Example 1:**

  ```
  Input: [3, 2, 1]
  
  Output: 1
  
  Explanation: The third maximum is 1.
  ```

  **Example 2:**

  ```
  Input: [1, 2]
  
  Output: 2
  
  Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
  ```

  **Example 3:**

  ```
  Input: [2, 2, 3, 1]
  
  Output: 1
  
  Explanation: Note that the third maximum here means the third maximum distinct number.
  Both numbers with value 2 are both considered as second maximum.
  ```

***

## 解法

**Solution：**

- 这道题逻辑比较简单，从头到尾遍历整个数组，用三个 `FirstMax,SecondMax,ThirdMax` 记录三个最大值。当然三个变量初始化为`INT_MIN`。
- 不过需要注意很多小细节：
  - 数组长度不到 3 的情况(例如`Example 2`)
  - 数组中重复元素的情况(这里计算的第三大的数字是不计算重复数字的，例如`Example 3`。)
  - 数组长度大于等于3，但是不计算重复元素的时候，小于3的情况。(返回最大的元素，也即`FirstMax`)
  - 数组中存在`-2147483647` ，也即`INT_MIN`的情况。

------

## code(c++)

**solution(4ms-100%)：** 

```c++
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int FirstMax = INT_MIN;
        int SecondMax = INT_MIN;
        int ThirdMax = INT_MIN;
        int n = nums.size();
        bool has_INT_MIN = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= ThirdMax) {
                if(nums[i] == INT_MIN) has_INT_MIN = true;
                continue;
            }
            if(nums[i] == FirstMax || nums[i] == SecondMax || nums[i] == ThirdMax) {
                continue;
            }
            else if (nums[i] < SecondMax) ThirdMax = nums[i];
            else if (nums[i] < FirstMax) {
                ThirdMax = SecondMax;
                SecondMax = nums[i];
            }
            else {
                ThirdMax = SecondMax;
                SecondMax = FirstMax;
                FirstMax = nums[i];
            }
        }
        if(n < 3) return FirstMax;
        if(ThirdMax == INT_MIN) {
            if(!has_INT_MIN || SecondMax == INT_MIN) return FirstMax;
        }
        return ThirdMax;
    }
};
```





