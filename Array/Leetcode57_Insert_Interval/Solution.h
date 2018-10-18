#include <vector>
#include <iostream>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

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