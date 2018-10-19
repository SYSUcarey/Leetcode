---
title: "Leetcode31 Next Permutation"
date: 2018-10-19T20:30:53+08:00
slug : "Leetcode31 Next Permutation"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode31 Next Permutation](https://leetcode.com/problems/next-permutation/description/)

- 概述：

  Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  The replacement must be **in-place** and use only constant extra memory.

  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

  `1,2,3` → `1,3,2`
  `3,2,1` → `1,2,3`
  `1,1,5` → `1,5,1`

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

**solution1(8ms)：** 

```c++
class Solution {
public:
    int temp;
    bool isFinished = false;

    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] >= nums[i+1]) continue;
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums, i, j);
            i = i + 1;
            j = nums.size() - 1;
            reverse(nums, i, j);
            break;
        }
        if(!isFinished) reverse(nums, 0, nums.size() - 1);
    }

    void swap(vector<int>& nums, int i, int j) {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
        isFinished = true;
    }
};
```

**Solution2(8ms)** ——(Solution1 的写法优化)

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        if(i == 0) reverse(nums.begin(), nums.end());
        else {
            sort(nums.begin() + i, nums.end());
            int j = i;
            while(j < (int)nums.size() && nums[j] <= nums[i-1]) j++;
            swap(nums[j], nums[i-1]);
        }
    }
};
```

