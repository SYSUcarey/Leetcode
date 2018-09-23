#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxArea(vector<int>& height);

int main(){
	vector<int> height;
	int array[] = {1,8,6,2,5,4,8,3,7};
	for(int i = 0; i < 9; i++) {
		height.push_back(array[i]);
	}
	cout << "array1: " << endl;
	for(int i = 0; i < (int)height.size(); i++) cout << height[i] << " ";
	cout << endl << "answer:" << endl;
	int answer = maxArea(height);
	cout << answer << endl;
	return 0;
}

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

	int area = min(height[1], height[0]);
	for(int i = 0; i < (int)height.size(); i++) {
		for (int j = i+1; j < (int)height.size(); j++) {
			area =  max(area, min(height[i], height[j])*(j-i));
		}
	}
	return area;
}

