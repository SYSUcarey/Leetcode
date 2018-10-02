---
title: "Leetcode4: Median of Two Sorted Arrays"
date: 2018-09-16T23:50:53+08:00
slug : "Leetcode4: Median of Two Sorted Arrays"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

### 题目论述

- 链接：[leetcode 4](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

- 概述：

  There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

  You may assume **nums1** and **nums2** cannot be both empty.

  **Example 1:**

  ```
  nums1 = [1, 3]
  nums2 = [2]
  
  The median is 2.0
  ```

  **Example 2:**

  ```
  nums1 = [1, 2]
  nums2 = [3, 4]
  
  The median is (2 + 3)/2 = 2.5
  ```

***

### 思考分析

1.

​	一个排序好的数组，求它的中位数是简单的，O(1)的复杂度即可。

2.

​	对于两个分开排序好的数组A,B，复杂度O(m+n)的解是显然的。事实上只用从小到大遍历数组A，比较B[0]与A中数的大小，找出有多少个小于B[0]的即可。

3.

​	然而题目中要求的是O(log(m+n))的复杂度，首先想到的是二分查找。

​	根据中位数的定义，我们需要的结果是数组A中的第i个元素和数组B中的第j个元素，使得`k=i+j-2 = (m+n-1)/2`，而且这两个元素之前的数都比这两个元素小，之后的数都比这两个元素大。核心就是找出`k=(m+n-1)/2`个数比A[i-1]，B[j-1]都小，此时可以采用二分查找的方法，不断缩小每次查找时k的值，来确实所需要找的A[i-1]，B[j-1]。

​	具体来说，就是用pa, pb两个指针分别指向两个数组，利用二分查找，比较pa，pb两个指针指向的数：

- 当*pa < *pb 的时候，pa指针改为指向后面数的中间。那么pa前面的数就是找出来的既比 *pa 小也比 *pb 小的数，k的值变小递推下去。
- 当*pa > *pb的时候，pb指针改为指向后面数的中间，那么pb前面的数就是找出来的既比 *pa 小也比 *pb 小的数，k的值变小递推下去。

   	要注意的问题是：

 - 指针临界的问题，比如说A中的数目都比B[j-1]都小，但是这时候还没找到足够的数（B的长度比A大很多），就直接可以从B[j-1]往后移查找了。
 - k=1的时候。

***

### code(c++)



```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findkthNum(nums1, 0, nums2, 0, left) + findkthNum(nums1, 0, nums2, 0, right)) / 2.0; 
    }

    double findkthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        int m = nums1.size();
        int n = nums2.size();
        if (m - i > n - j) return findkthNum(nums2, j, nums1, i, k);
        if (m == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int pa = min(i + k / 2, m);
        int pb = j + (k - pa + i);
        if (nums1[pa - 1] < nums2[pb - 1]) 
            return findkthNum(nums1, pa, nums2, j, k - pa + i);
        else if (nums1[pa - 1] > nums2[pb - 1]) 
            return findkthNum(nums1, i, nums2, pb, k - pb + j);
        else 
            return nums1[pa - 1];
    }
};
```

