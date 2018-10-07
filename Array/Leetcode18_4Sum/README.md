---
title: "Leetcode18 4Sum"
date: 2018-10-07T22:33:53+08:00
slug : "Leetcode18 4Sum"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode18 4Sum](https://leetcode.com/problems/4sum/description/)

- 概述：

  Given an array `nums` of *n* integers and an integer `target`, are there elements *a*, *b*, *c*, and *d* in `nums` such that *a* + *b*+ *c* + *d* = `target`? Find all unique quadruplets in the array which gives the sum of `target`.

  **Note:**

  The solution set must not contain duplicate quadruplets.

  **Example:**

  ```
  Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
  
  A solution set is:
  [
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
  ]
  ```

***

## 思考

**分析一：**

- 四层循环暴力求解的方法显然是不切实际的。

**分析二：**

- 我们参考之前[leetcode15 3sum](https://sysucarey.github.io/leetcode15-3sum/)的解法套路。在[leetcode15 3sum](https://sysucarey.github.io/leetcode15-3sum/)解法中，我们将一个 *3 Sum* 问题转化为一个 *2 Sum* 问题，先确定三数中的一个，剩下的 *2 Sum* 问题可以通过 *head, tail* 两个 *index* 指针向中间逼近的方法以 *O(n)* 的复杂度解决。

- 那么同样的道理，对于 *4 Sum* 问题，我们何不先确定一个数，从而将 *4 Sum* 问题归化成一个 *3 Sum* 问题，从而再简化成一个 *2 Sum* 问题，这样一个算法的复杂度可以变为 *O (n^3)* 。

***

## 解法

- 第一步，将数组排序。

  ```c++
  sort(nums.begin(), nums.end());
  ```

- 第二步，`4 Sum -> 3 Sum -> 2 Sum`。

  

  ​	用 *smallest, head, tail, largest* 四个 *index* 指针来指向选中的四个数(从小到大)。

  ​	两个 *for* 循环确定最小数和最大数，问题转化从`4 Sum -> 3 Sum -> 2 Sum`。(`smallest from 0 to len-1`，`largest from len-1 to smallest+3`)

  ​	一个while循环，*head, tail* 从两侧向中间逼近解决`2 Sum`问题。(`head = smallest + 1`，`tail = largest - 1`)

- 第三步，除去重复项。

  ​	 *smallest* 的重复。第一层 *for* 循环中，`smallest from 0 to len-1`，如果最小数与前一个相同，那么跳过。

  ​	 *largest* 的重复。第二层 *for* 循环中，`largest from len-1 to smallest+3`，如果最大数与后一个数相同，那么跳过。

  ​	 *head, tail* 的重复。第三层 *while* 循环中，由于我们规定，当找到符合条件的四数组合，那么 *head++* ，因此在这一层循环中排除重复时，要在最后判断 *head* 指向数与前一个是否相同，如果相同则跳过。

- 选择`largest frome len-1 to smallest+3`，而不是`largest from smallest+3 to len-1`的原因是：

  ​	如果选择后者的遍历方法，当你判断 *largest* 重复的 时候，因为这是一个 *4 Sum* 问题，就算新的最大数与前一个数相同，也不一定是重复项。反例示范：

  ```
  Input:[-1,2,2,-5,0,-1,4] 3
  
  Output:[[-5,2,2,4]]
  
  Expected:[[-5,2,2,4],[-1,0,2,2]]
  
  ```

  ​	如果是后者的遍历方法，这样最大数取到第一个2的时候，因为head与tail取不到第二个2，因此取不到第二个解`[-1, 0, 2, 2]`。然后tail++的时候会判断2与前一个数相等，直接跳过，那么就漏掉了这个解了。

**算法复杂度O(n^3)** 

------

## code(c++)

**solution(20ms)** 

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //sorted the array
        sort(nums.begin(), nums.end());
        //determine the smallest and largest
        vector<vector<int>> answer;
        int smallest, head, tail, largest;
        int sum;
        for(smallest = 0; smallest < (int)nums.size(); smallest++) {
            // avoid the same pair of smallest and largest numbers
            if(smallest > 0 && nums[smallest] == nums[smallest-1]) continue;

            for(largest = (int)nums.size()-1; largest >= smallest+3; largest--) {
                // avoid the same pair of smallest and largest numbers
                if(largest < (int)nums.size()-1 && nums[largest] == nums[largest+1]) continue;
    
                //find the two Sum answer
                head = smallest + 1;
                tail = largest - 1;
                while(head < tail) {
                    sum = nums[smallest] + nums[head] + nums[tail] + nums[largest];
                    if(sum < target) head++;
                    else if(sum > target) tail--;
                    else {
                        answer.push_back({nums[smallest], nums[head], nums[tail], nums[largest]});
                        head++;
                        // avoid the same pair of head and tail numbers
                        while(nums[head] == nums[head-1]) {
                            head++;
                        }
                    }
                }
    
            }
        }
        return answer;
    }
};
```

