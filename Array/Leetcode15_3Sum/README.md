---
title: "Leetcode15 3Sum"
date: 2018-09-30T22:25:53+08:00
slug : "Leetcode15 3Sum"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目论述

- 链接：

  [Leetcode15 3Sum](https://leetcode.com/problems/3sum/description/)

- 概述：

  Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

  **Note:**

  The solution set must not contain duplicate triplets.

  **Example:**

  ```
  Given array nums = [-1, 0, 1, 2, -1, -4],
  
  A solution set is:
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]
  ```
  
***

## 思考分析

**分析一：**

​	三层循环暴力求解。

​	**复杂度O(n^3)**

**分析二(Solution1)：**

​	我们根据之前做的[Leetcode16： 3 Sum Closest](https://sysucarey.github.io/leetcode16-3-sum-closet/)的思路，将这道三数和问题转化为二数和问题。

- 第一步，因为所求与原始数组下标无关，故放心大胆地先将数组排序。
- 第二步，用一个for循环选出三数中最小的一个数`num[target]`。
- 第三步，用一个while循环从`num[target]`后面的数中，以从两头向中间逼近的方法确定剩下的两个数`num[head], num[tail]`，如果`num[head] + num[tail] = -num[target]`，那么，`(num[target], num[head], num[tail])`就是满足条件的三元组。
- 第四步，按照上述步骤得到的三元组是有重复的，那么我们要优化一下，避免向答案数组中加入重复项。
  - 在for循环中，如果`num[target]`与之前的一样的话，那么target++，跳过。

  - 在while循环中，我们规定如果找到一个满足条件的`(head, tail)`，head++继续寻找不同的`(head, tail)`。那么需要判断head++后，当下的`num[head]`与之前的是否相同，相同的话，那么head++，跳过。

  **复杂度O(n^2)**



***

## code(c++)

solution (88ms)

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array
        sort(nums.begin(), nums.end());

        //find the answer vector<vector<int>>
        vector<vector<int>> answer;
        int head, tail;
        for(int i = 0; i < (int)nums.size(); i++) {
            if(nums[i] == nums[i-1] && i != 0) continue;
            head = i + 1;
            tail = nums.size()-1; 
            while(head < tail) {
                if(nums[head] + nums[tail] < -nums[i]) head++;
                else if(nums[head] + nums[tail] > -nums[i]) tail--;
                else {
                    if(nums[head] == nums[head-1] && head != i+1) {
                        head++;
                        continue;
                    }
                    answer.push_back({nums[i], nums[head], nums[tail]});
                    head++;
                }
            }
        }
        return answer;
    }
};
```

