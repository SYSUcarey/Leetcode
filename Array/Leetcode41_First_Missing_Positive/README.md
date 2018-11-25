---
title: "Leetcode41 First Missing Positive"
date: 2018-11-25T11:50:53+08:00
slug : "Leetcode41 First Missing Positive"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---
## 题目

- 链接：

  [Leetcode41 First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/)

- 难度：

  **Difficulty: Hard** 

  **Acceptance: 28.7%**  

  

- 概述：

  Given an unsorted integer array, find the smallest missing positive integer.

  **Example 1:**

  ```
  Input: [1,2,0]
  Output: 3
  ```

  **Example 2:**

  ```
  Input: [3,4,-1,1]
  Output: 2
  ```

  **Example 3:**

  ```
  Input: [7,8,9,11,12]
  Output: 1
  ```

  **Note:**

  Your algorithm should run in *O*(*n*) time and uses constant extra space.

------

## 思考

**分析1：**

- 这道题描述很简单，但其实细想起来并不简单。特别是对于时间复杂度 O(n) 和空间复杂度 O(1) 的限制，使得这道题的难度更高吧。
- 因为时间复杂度的限制，要基于比较对数组排序是不可能的了。不处理数组直接用变量去记录最小正数也不行，例如说数组`[2，3，4，1]`，只记录最小可用正数的话，一开始是记录1，这样遍历下去到第四个数1时，就会会导致不知道下一个正数是多少。但如果记录下别的信息，但显然困扰到我们的始终会是不知道下一个可用的最小正数是多少。如果非得强行记录下所有信息，显然又超过了 O(1) 的空间复杂度。这样想下去估计是行不通的。
-  我们注意到这样一个事实，对于一个长度为n的数组，这道题的答案只有可能是 `[1,n+1]`，毕竟求的是最小的正数，若数组恰好是`{1,2,3,···,n}`，那么最小正数就肯定是n+1；若不是，那么最小正数必定是`{1，2，3，···，n}`在数组中没有出现的最小的数。那么或许我们可以改变思路，不是遍历数组，而是遍历从1到n，判断这个数是否出现在数组中即可。
- 那么问题又来了，判断数是否在数组中也需要 O(n) 的复杂度，这样时间复杂度就又超了，因此我们不能直接进行遍历。
- 我们可以参考一下桶排序，我们生成n个桶，桶号1~n，规定桶k只能放数字k，k=1,2,3,···,n。先遍历数组，将对应的数字放进对应的桶，非正数或者大于n的就不用处理了。这样遍历完后，我们再从桶1遍历到桶n，如果桶k是空的，代表着k没有出现在数组中，那么k就是最小正数。如果桶都是满的，说明数组恰好是`{1,2,3,···,n}`，最小正数为n+1。这样问题迎刃而解。
- 而受限于空间复杂度 O(1) 的限制，我们不用真的去生成n个桶，我们直接把数组当作n个桶，交换数组中的数即可。

------

## 解法

### **Solution**

- 根据分析1中的思路，获得数组的长度size。

- 从头到尾遍历数组，FOR i FROM 0 TO size-1，如果：
  - 数字非正数，也即`nums[i]<0`
  - 数字超过size，也即`nums[i]>size`
  - 数字正好就在对应(桶内)位置上，也即 `nums[i]==i+1`
  - 要替换的(桶)位置上已经有一个对应数字了，也即`nums[i]==nums[nums[i]-1]`。(这是为了避免输入数组为`[1,1]`进入死循环的情况)

  那么，直接跳过这一次循环

- 否则，我们将`nums[i]`和`nums[nums[i]-1]`替换。继续从 i 这个位置遍历数组。

- 遍历完数组后，再次遍历 FOR i FROM 0 TO size-1，如果对应(桶内)位置上是对应的数字，也即`nums[i]==i+1`，那么就继续遍历。若不是对应数字，也即`nums[i]!=i+1`，那么直接返回桶号，也即 i+1 。若所有位置都是对应数字，那么返回 size+1 。

- 根据上述的算法，算法时间复杂度为**O(n)**，空间复杂度 **O(1)** 。 

### **code c++**

```c++
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
        	if(nums[i] <= 0 || nums[i] > size || nums[i] == i+1 || nums[i] == nums[nums[i]-1]) continue;
        	swap(nums[i], nums[nums[i]-1]);
            i--;
        }
        for(int i = 0; i < size; i++) {
        	if(nums[i] != i+1) return i+1;
        }
        return size+1;
    }
};
```





