---
title: "Leetcode581 Shortest Unsorted Continuous Subarray"
date: 2018-10-23T18:50:53+08:00
slug : "Leetcode581 Shortest Unsorted Continuous Subarray"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode581 Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/)

- 概述：

  Given an integer array, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

  You need to find the **shortest** such subarray and output its length.

  **Example 1:**

  ```
  Input: [2, 6, 4, 8, 10, 9, 15]
  Output: 5
  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
  ```

  **Note:**

  1. Then length of the input array is in range [1, 10,000].
  2. The input array may contain duplicates, so ascending order here means **<=**.

***

## 思考

**分析：**

- todo

***

## 解法

**Solution：**

- todo

------

## code(c++)

**solution1(32ms)：** 

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return 0;
        vector<int> sortArray;
        for(int i = 0; i < (int)nums.size(); i++) sortArray.push_back(nums[i]);
        sort(sortArray.begin(), sortArray.end());
        int begin = 0, end = nums.size() - 1;
        while(begin <= end) {
            if(nums[begin] == sortArray[begin]) begin++;
            else break;
        }
        while(end > begin) {
            if(nums[end] == sortArray[end]) end--;
            else break;
        }
        return end-begin+1;
    }
};
```

**Solution2(8ms)**

```c++

```

