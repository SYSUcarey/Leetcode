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

- todo

***

## 解法

**Solution：**

- todo


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


