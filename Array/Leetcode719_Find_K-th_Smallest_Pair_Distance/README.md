---
title: "Leetcode719 Find_K-th Smallest Pair Distance"
date: 2019-02-27T12:10:53+08:00
slug : "Leetcode719 Find_K-th Smallest Pair Distance"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode719 Find_K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) 

- 概述：

  Given an integer array, return the k-th smallest **distance** among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

  **Example 1:**

  ```
  Input:
  nums = [1,3,1]
  k = 1
  Output: 0 
  Explanation:
  Here are all the pairs:
  (1,3) -> 2
  (1,1) -> 0
  (3,1) -> 2
  Then the 1st smallest distance pair is (1,1), and its distance is 0.
  ```

  **Note:**

  1. `2 <= len(nums) <= 10000`.
  2. `0 <= nums[i] < 1000000`.
  3. `1 <= k <= len(nums) * (len(nums) - 1) / 2`.

***

## 解法

**Solution：**

- 这道题首先第一个想法是将所有(A,B)对的距离计算出，然后排序，再之后取从小到大第k项返回。Note中提示了数组的长度为2~10000。显然地所有的距离将是n^2的数量级，然后再进行排序，算法复杂度将会是 **O(n^3)** ，当测试案例n很大时，导致了Time Limit，没有通过测试。
- 第二个比较简单的想法是，我们假设输入数据中最大的是M<1000000，然后创建M+1个桶用来计数，初始设置为0。我们依然需要计算出每一个(A,B)对的距离，但我们并不存储距离的数值，而是对这个数值进行次数计数，相当于我们往标号为这个数值的桶放入一个小球。例如我们算出的第一个距离为m，那么我们往桶m放入一个小球，即令桶m的计数+1，。这样当我们计算完所有的距离时，我们也完成了所有的计数，我们从桶0往桶M进行遍历，直到找到第k个球，对应桶的标号，即是答案。这样算法复杂度为 **O(n^2+M)** ，当n很大时，会比上一个方案要好一点，但n小时，将会很糟糕。这个 Solution1 虽然过了测试，beat 20%，使用了13MB的内存依然是糟糕的表现。
- 待优化

------

## code(c++)

**solution1(860ms-20%)：** 

```c++
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = nums[n-1];
        int bucket[m+1] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int d = nums[i]-nums[j];
                if(d < 0) d = -d;
                bucket[d]++;
            }
        }
        int count = 0, index = 0;
        while(index <= m) {
            if(bucket[index] > 0) {
                count += bucket[index];
                if(count >= k) return index;
            }
            index++;
        }
        return -1;
    }
};
```





