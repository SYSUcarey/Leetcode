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