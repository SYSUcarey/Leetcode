---
title: "Leetcode56 Merge Intervals"
date: 2018-10-14T10:30:53+08:00
slug : "Leetcode56 Merge Intervals"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode56 Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

- 概述：

  Given a collection of intervals, merge all overlapping intervals.

  **Example 1:**

  ```
  Input: [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
  ```

  **Example 2:**

  ```
  Input: [[1,4],[4,5]]
  Output: [[1,5]]
  Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
  ```

***

## 思考

**分析一：**

- 合并区间的操作在我们思考中是比较简单的，首先的第一步应该是排序操作，将区间的最小值为Key进行从小到大排序。然后就是从数组第一个区间开始判断到最后一个区间。具体对于自定义结构体的sort数组操作，类内和类外的区别等细节，[参考博客](https://leetcode.com/problems/merge-intervals/description/)。
- 如果前一个区间的最大值比后一个区间的最小值小，那么没有区间合并操作；如果前一个区间的最大值比后一个区间的最小值大，但比最大值小，那么区间合并成`[前一个区间的最小值，后一个区间的最大值]`；如果前一个区间的最大值比后一个区间的最大值都大，相当于后一个区间没有用，直接删去。
- 这样我们就可以得到**Solution1**，排序复杂度为**O(nlogn)**，一个for循环，**O(n)**。一开始我以为算法复杂度是**O(nlogn)**，但后来我发现错了，因为在数组中删去一个元素erase操作的复杂度为**O(n)**，所以总复杂度应该是**O(n^2)**，这样我们非但没有降低到我们想要的复杂度，而且还调用了很多erase操作，还有一个sort操作，还有数组的克隆操作，这样还是蛮慢的，可以预见到算法还有优化的空间。

**分析二：**

- 我们考虑优化分析一，造成**Solution1**中复杂度升到**O(n^2)**的原因在于for循环中进行了删除元素的操作。那么我们考虑是否可以先判断完，再添加进answer数组，而不是一开始先复制后删除。
- 基于这样的考虑，我们可以先把intervals数组排序，然后先比较完是否需要进行合并区间，如果是需要合并的话，因为intervals已经基于区间start值排序了，那么也就是说要添加的新区间的start一定比answer中最后一个元素区间的start值要大，那么我们只需要修改answer中最后一个元素区间的end值；不需要合并的话，就直接把新区间添加进answer数组中即可。
- 这样我们就可以得到**Solution2**，复杂度为**O(nlogn)**。

***

## 解法

**Solution1：**

- 第一步，关于自定义结构体数组的排序，类内构造比较函数，以`Interval.start`作为key进行比较。

  ```c++
  static bool LessSort(Interval v1, Interval v2);
  ```

- 第二步，复制`intervals`数组，克隆到新的数组`answer`。

- 第三步，考虑空数组的情况。

- 第四步，调用数组的sort函数，对数组进行排序。

  ```c++
  sort(answer.begin(), answer.end(), LessSort);
  ```

- 第五步，for循环从小到大遍历数组，如果`answer[i].end>=answer[i+1].start`则发生区间合并的操作，否则直接跳过这次循环。然后根据`answer[i].end`和`anwer[i+1].end`的比较，决定合并后的数组的最大值。

- 算法完成，**复杂度O(n^2)**。

**Solution2：**

- 第一步，依然是关于自定义结构体数组的排序，类内构造比较函数，以`Interval.start`作为key进行比较。

  ```c++
  static bool LessSort(Interval v1, Interval v2);
  ```

- 第二步，考虑空数组的特殊情况。

- 第三步，对intervals数组进行基于Interval.start为key的排序。

  ```c++
  sort(interval.begin(), interval.end(), LessSort);
  ```

- 第四步，遍历数组intervals，进行是否合并区间的比较。

  - IF answer.size() == 0, THEN push_back
  - ELSE IF intervals[i].start > answer.back().end，THEN push_back，即不需要进行合并区间的操作。
  - ELSE IF intervals[i].end > answer.back().end，THEN answer.back().end = intervals[i].end，即需要进行合并区间的操作。

- 算法完成，**复杂度O(nlogn)**。

------

## code(c++)

**solution1(96ms)：** 

```c++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    static bool LessSort(Interval v1, Interval v2) {
        return v1.start < v2.start;
    }    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> answer;
	    if(intervals.size()<=0) return answer;
        for(unsigned int i = 0; i < intervals.size(); i++)
            answer.push_back(intervals[i]);
        sort(answer.begin(), answer.end(), LessSort);
        for(unsigned int i = 0; i < answer.size()-1; i++) {
            if(answer[i].end >= answer[i+1].start) {
                if(answer[i].end < answer[i+1].end) answer[i].end = answer[i+1].end;
                answer.erase(answer.begin()+i+1);
                i--;
            }
        }
        return answer;
    }
};
```



**solution2 (8ms)：**

```c++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    static bool LessSort(Interval v1, Interval v2) {
        return v1.start < v2.start;
    }    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> answer;
        if(intervals.size()<=0) return answer;
        sort(intervals.begin(), intervals.end(), LessSort);
        for(unsigned int i = 0; i < intervals.size(); i++) {
            if(answer.size() == 0) answer.push_back(intervals[i]);
            else if (intervals[i].start > answer.back().end) answer.push_back(intervals[i]);
            else if(intervals[i].end > answer.back().end) answer.back().end = intervals[i].end;
        }
        return answer;
    }
};
```

