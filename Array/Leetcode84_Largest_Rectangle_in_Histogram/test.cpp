#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

#define _ARRAY_SIZE 6

int main(){
	vector<int> heights;
	int data[_ARRAY_SIZE] = {2,1,5,6,2,3};
	for(int i = 0; i < _ARRAY_SIZE; i++) 
		heights.push_back(data[i]);
	cout << "Input : " << endl;
	for(unsigned int i = 0; i < heights.size(); i++) 
		cout << heights[i] << " "; 
	cout << endl << "Output : " << endl;
	Solution mySolution = Solution();
	int answer = mySolution.largestRectangleArea(heights);
	cout << answer << endl;
	
}

