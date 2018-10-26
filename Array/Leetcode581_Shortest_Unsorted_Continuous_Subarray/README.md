---
title: "Leetcode581 Shortest Unsorted Continuous Subarray"
date: 2018-10-26T14:50:53+08:00
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

- 找到最短的要排序的连续项的数量，使得排序这些项后，整个数组是升序的。
- 那么我们考虑的很简单，我们干脆先复制数组，然后先进行排序。然后用两个指针**begin**和**end**从头和尾向中间逼近，找到第一项和排序后的数组不一样的，那么这时候**Output=end-begin+1**。

***

## 解法

**Solution：**

- 根据分析里的思路，首先考虑数组`SIZE == 0`和 `SIZE == 1`的情况。
- 克隆数组**sortArray**，然后用**sort**函数排序**sortArray**数组。
- 定义两个指针**begin**和**end**从两头向中间逼近，找出第一项和排序数组不一样的。这里只要注意好一些边界细节就没问题了。
- **算法复杂度O(n logn)**

------

## code(c++)

**solution(32ms)：** 

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





