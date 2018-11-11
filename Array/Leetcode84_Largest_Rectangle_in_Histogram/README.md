---
title: "Leetcode84 Largest Rectangle in Histogram"
date: 2018-11-11T20:50:53+08:00
slug : "Leetcode84 Largest Rectangle in Histogram"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode84 Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

- 概述：

  1. Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

      

     ![img](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
     Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.

      

     ![img](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
     The largest rectangle is shown in the shaded area, which has area = `10` unit.

      

     **Example:**

     ```
     Input: [2,1,5,6,2,3]
     Output: 10
     ```

***

## 思考

**分析1：**

- 这道题乍一看跟[Leetcode 11 container with most water](https://leetcode.com/problems/container-with-most-water/description/)很像，都是求面积最大，不同的是，前者形成的长方形的高是由两端较小的数决定的，而本道题形成的长方形的高是由两端以及中间所有数的最小值决定的。
- 但正因为高的取决不同，这道题就不能像**Leetcode 11**那样从两端向中间逼近，因为我们可以找出反例，我们总丢弃矮的那边向中间缩进是不正确的。

**分析2：**

- 那么或许我们可以从最矮的开始下手，将数组分成两部分。最矮的数左边和最矮的数右边，然后最大的长方形面积就必然来自以下三个部分之一：
  - 要么来自于左半部中的最大长方形面积
  - 要么来自于右半部中的最大长方形面积
  - 要么来自高为这个最矮数，长我们取最大的长方形的面积
- 按照这个想法我们可以用递归去实现这个算法

***

## 解法

### **Solution**

- `int getMaxArea(int head, int tail, vector<int>& heights)`是辅助函数，用来获取**heights[head, tail]**中的最大长方形的面积，这样就方便我们用这个函数进行递归实现算法。这个函数的实现就基于上面分析2中所说的，找到最小数，然后分成三部分，递归下去。
- `int getMinHeight(int head, int tail, vector<int>& heights, int& index)`是另外一个函数，用来获取**heights[head, tail]**中的最小的数返回，并且获得这个最小的数的**index**，这个函数的实现就很简单，从**head**到**tail**遍历一遍即可。
- 那么最后题目所要求的解就是`getMaxArea(0, heights.size()-1,  heights);`
- 算法复杂度：最好**O(n·logn)**，最坏**O(n^2)**。

### **code(c++)**

```c++
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	return getMaxArea(0, heights.size()-1, heights);

    }
    int getMaxArea(int head, int tail, vector<int>& heights) {
    	if(tail < head) return 0;
    	if(tail == head) return heights[head];
    	// get the smallest height in heights[head...tail]
    	int smallest_index;
    	int smallest = getMinHeight(head, tail, heights, smallest_index);
    	// MaxArea may be the maximun of the following three part
    	int area1 = getMaxArea(head, smallest_index-1, heights);
    	int area2 = getMaxArea(smallest_index+1, tail, heights);
    	int area3 = smallest * (tail - head + 1);
    	int MaxArea = (area1 > area2) ? area1 : area2;
    	return (MaxArea > area3) ? MaxArea : area3;
    }

    int getMinHeight(int head, int tail, vector<int>& heights, int& index) {
    	int answer = heights[head];
    	index = head;
    	for(int i = head+1; i <= tail; i++) {
    		if(heights[i] < answer) {
    			answer = heights[i];
    			index = i;    		}
    	}
    	return answer;
    }
};
```





