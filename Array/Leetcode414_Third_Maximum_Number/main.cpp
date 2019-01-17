#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

#define _ARRAY_SIZE 3

int main(){
	vector<int> nums;
	int data[_ARRAY_SIZE] = {1,1,-2147483648};
	for(int i = 0; i < _ARRAY_SIZE; i++) 
		nums.push_back(data[i]);
	cout << "Input : " << endl;
	for(unsigned int i = 0; i < nums.size(); i++) 
		cout << nums[i] << " "; 
	cout << endl << "Output : " << endl;
	Solution mySolution = Solution();
	int answer = mySolution.thirdMax(nums);
	cout << answer << endl;
}

