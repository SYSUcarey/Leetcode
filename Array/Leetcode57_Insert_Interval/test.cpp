#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(){
	vector<Interval> intervals;
	int data[5][2] = {{1, 2}, {5, 7}, {9, 11}, {13, 17}, {18, 26}};
	for(int i = 0; i < 5; i++) 
		intervals.push_back(Interval(data[i][0], data[i][1]));
	Interval newInterval = Interval(2, 12);
	cout << "Input : " << endl << "intervals: ";
	for(unsigned int i = 0; i < intervals.size(); i++) 
		cout << "[" <<  intervals[i].start << ", " << intervals[i].end << "]  ";
	cout << endl << "newInterval: " << "[" << newInterval.start << ", " << newInterval.end << "]" << endl; 
	cout << endl << "Output : " << endl;
	Solution mySolution = Solution();
	vector<Interval> answer;
	answer = mySolution.insert(intervals, newInterval);
	for(unsigned int i = 0; i < answer.size(); i++) 
		cout << "[" <<  answer[i].start << ", " << answer[i].end << "]  ";
	cout << endl;
}

