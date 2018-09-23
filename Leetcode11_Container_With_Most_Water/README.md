# Leetcode11: Container With Most Water

[TOC]

### 题目论述

- 链接：[Leetcode11: Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/)

- 概述：

  Given *n* non-negative integers $a_1, a_2, ..., a_n$ , where each represents a point at coordinate $(i, a_i)$. *n* vertical lines are drawn such that the two endpoints of line *i* is at $(i, a_i)$ and $(i, 0)$. Find two lines, which together with x-axis forms a container, such that the container contains the most water.

  **Note:** You may not slant the container and *n* is at least 2.

  ![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

  The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

   

  **Example:**

  ```
  Input: [1,8,6,2,5,4,8,3,7]
  Output: 49
  ```

***

### 思考分析

1. 问题转数学语言表达：

   ​	这道题叙述上是求n个不等高的柱子等距1排放，如何选出两个柱子，使得柱子之间形成的长方形的“盛水容器”面积更大。实际上该长方形的高度取决于两根柱子之间较矮的那根，其宽度取决于两根柱子之间的距离。

   ​	那么转换成数学语言即是：

   ​	在数组A中，如何选出两个数$A[i]$与$A[j]$，$(i < j)$，使得值$min(A[i], A[j])·(j-i)$的值最大。

   

2. Solution1：

   ​	第一个很容易想到的解法，当然是两个循环体遍历任意两个数的组合，算出每对组合数的对应面积，取最大的面积即是答案。这样的复杂度为$O(n^2)$。

   

3. Solution2:

     ​	我们考虑一下是否存在$O(n)$的解法，我们首先先保证宽度最大，也即先选出最左边的柱子和最右边的柱子。那么暂定最大面积为这两根柱子之间的容器面积。

     ​	那么下面要考虑高度的问题，我们从较矮的那根柱子开始往另一边移动1步，那么移动后有一个新的容器面积，我们只需要比较暂定最大面积和这个新的容器面积，将较大的那个重新赋值给暂定最大面积即可。重复考虑新的两根柱子的移动问题，直到两根柱子移动n-1次并到一起，这时候得到的最大面积就是答案。

     ​	事实上这样的逼近是合理的。因为如果新的容器面积比暂定最大面积大，那么最大面积就与之前暂定最大面积移动的那根柱子无关了。而如果新的容器面积比之前的暂定最大面积小，那么最后结果的最大面积一定不是由移动后的这根柱子形成的，所以可以继续往后逼近。

***

### code(c++)

- Solution 1	(1424ms)

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
       	int area = min(height[1], height[0]);
        for(int i = 0; i < (int)height.size(); i++) {
            for (int j = i+1; j < (int)height.size(); j++) {
                area =  max(area, min(height[i], height[j])*(j-i));
            }
        }
        return area; 
    }
};
```

- Solution 2	(12ms)
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_area = min(height[0], height[size-1]) * (size-1);
        int head = 0, tail = size - 1;
        while(head < tail) {
            if(height[head] < height[tail]) {
                max_area = max(max_area, height[head] * (tail - head));
                head++;
            }
            else {
                max_area = max(max_area, height[tail] * (tail - head));
                tail--;
            }
        }
        return max_area;
    }
};
```

