---
title: "Leetcode57 Insert Interval"
date: 2018-10-18T22:30:53+08:00
slug : "Leetcode57 Insert Interval"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode57 Insert Interval](https://leetcode.com/problems/insert-interval/description/)

- 概述：

  Given a set of *non-overlapping* intervals, insert a new interval into the intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their start times.

  **Example 1:**

  ```
  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
  Output: [[1,5],[6,9]]
  ```

  **Example 2:**

  ```
  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
  Output: [[1,2],[3,10],[12,16]]
  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
  ```

  

***

## 思考

**分析：**

- 这都题其实不难，虽然不知道为什么只有30-%的Acc。画个图我们可以比较直观地看出这道题让我们想做的东西。

- 主要还是要找出插入区间**newInterval**最小值、最大值是在区间数组**intervals**的哪个位置，然后将中间的区间全部合并掉就好了。由于区间数组已经是按照最小值排好序的，那么这道题看上去应该是可以在**O(n)**的复杂度内解决的，从小到大遍历区间数组，比较与插入区间是否有交集，没有的话就直接添加到答案数组；有交集的话就计算出合并后的区间，添加到答案数组中；然后再把后面的也是无交的集区间添加到答案数组中去，返回答案数组。

  

***

## 解法

**Solution：**

- 基本思路应该是从小到大地遍历循环区间数组intervals，比较**newInterval.start**和**intervals[i].end**的大小，判断两区间是否存在交集：
  - **newInterval.start > intervals[i].end**，说明**newInterval**与**intervals[i]**是没有交集的，直接**push_back(intervals[i])**。

  - **newInterval.start <= intervals[i].end**，说明**newInterval**与**intervals[i]**是有交集的，我们得找出合并后的区间**temp**的**start**值和**end**值。
    - **temp.start**当然是**newInterval**与**intervals[i]**中**start**的较小值。
    - **temp.end**当然是再继续增加**i**，找出最后一个与**newInterval**有交集的区间**intervals[i]**，此时**temp.end**当然是**newInterval**与**intervals[i]**中**end**的较大值。

  - 找出合并区间后，再把之后的区间也**push_back**进去即可。

    

- 另外要注意空数组的情况，注意插入区间比所有数组中区间都要小、大的情况。

  

- 算法复杂度**O(n)**。

------

## code(c++)

**solution(8ms)：** 

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> answer;
    	// if intervals is empty
    	if(intervals.size() == 0) {
    		answer.push_back(newInterval);
    		return answer;
    	}
    	// if not empty
    	Interval temp = Interval();
    	bool isInsertEnd = false;
    	for(int i = 0; i < intervals.size(); i++) {
    		if(isInsertEnd) {
    			answer.push_back(intervals[i]);
    		}
    		else if(newInterval.start > intervals[i].end) {
    			answer.push_back(intervals[i]);
    			if(i == intervals.size() - 1) {
    				answer.push_back(newInterval);
    			}
    			continue;
    		}
    		else {
    			temp.start = (newInterval.start < intervals[i].start) ? newInterval.start : intervals[i].start;
    			while(i < intervals.size()) {
					if(newInterval.end < intervals[i].start) {
						temp.end = newInterval.end;
						answer.push_back(temp);
						i--;
						isInsertEnd = true;
						break;
					}
					else if(newInterval.end <= intervals[i].end) {
						temp.end = intervals[i].end;
						answer.push_back(temp);
						isInsertEnd = true;
						break;
					}
					else if(i == intervals.size() - 1) {
						temp.end = newInterval.end;
						answer.push_back(temp);
						isInsertEnd = true;
						break;
					}
					else i++;
    			}
    		}
    	}
    	return answer;
    }

};
```


