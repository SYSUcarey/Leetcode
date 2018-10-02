---
title: "Leetcode16: 3 Sum Closet"
date: 2018-09-09T20:30:53+08:00
slug : "Leetcode16: 3 Sum Closet"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目：

Given an array `nums` of n integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution. 

**Example:**

```
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

***
## 思考：

1. 首先一开始的想法，肯定是3个for循环遍历数组任意三个数的组合，复杂度O(n^3) ，效率想来肯定是太慢了，应该是无法通过测试。 

2. 然后第二个想法，将数组排序之后，从小到大遍历一次邻近3个数的组合，事实上`3Sum Closest`选出来的3个数并不一定是大小邻近的，例如对情况`[-3,0,1,2]，target=1`，输出应该是0，按照这个错误的算法来输出的是3，想法太简单了。

3. 那么第三个想法，将Array排序后分成大于等于target的数组A和小于target的数组B。

   - 若A，B数组中有任一个数组是空的，那自然问题解决，A中取最小的三个（B中取最大的三个)

   - 若A，B里任一个数组的长度为1。不妨假设A中只有一个数a，那么问题转换成求B数组的`2Sum Closet`，B中两数和要最接近target-a。

   - 若A，B数组的长度都大于1，那么数组A和数组B中必定都至少有一个数被选中，这样才能保证是最接近target的，对称地讨论1+2模式和2+1模式：

     以A+B=1+2的模式为例，遍历数组A取一个数a，那么B数组要取两个数，其和要最接近target-a，问题同样转换为一个`2Sum Closet`。

     那么我们把一个`3Sum Closet`的问题转换成了一个`2Sum Closet`的问题。

     对于`2Sum Closet`，我们给定头尾指针指向排序数组最左边（最小）+最右边（最大）开始往中间逼近：

     - 若这两个数加起来小于target，左边指针往右移动，这总能保证新的两个数是更接近target的

     - 若这两个数加起来大于target，右边指针往左移动，这总能保证新的两个数是更接近target的

     所以，`2Sum Closet`的复杂度为O(n)，这样整个算法的复杂度是O(n^2)

4. 仔细再考虑想法3，其实核心在于将`3Sum Closest`变成了一个`2Sum Closest`的问题，那么开始的时候将Array数组分成两个数组的操作根本是不必要的，它的作用只是为了先确定一个数，而且分成两个数组后还出现了讨论的问题，增加了问题的复杂性。

     所以我们在数组排序完之后，先选出一个数`nums[i]`，假设数组的长度是`len`，然后在`nums[i+1]`~`nums[len-1]`的数中选出剩下的第二、三个数，这是个`2Sum Closest`的问题，用头尾指针`head`，`tail`来向中间逼近，复杂度O(n)

     最终这个算法的复杂度是O(n^2)

***

## code(c++)

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sorted
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size() - i - 1; j++) {
                if(nums[j] > nums[j+1]) {
                    temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        int min_sum = nums[0] + nums[1] + nums[2];
        int head, tail;
        for(int i = 0; i < nums.size(); i++) {
            head = i + 1;
            tail = nums.size()-1;
            while (head < tail) {
                temp = nums[i] + nums[head] + nums[tail];
                if(temp > target) tail--;
                else if(temp < target) head++;
                else if(temp == target) return temp;
                if(abs(temp - target) < abs(min_sum - target)) min_sum = temp;
            }
        }
        return min_sum;
    }
};
```

