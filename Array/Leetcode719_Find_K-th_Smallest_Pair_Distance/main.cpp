#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

#define _ARRAY_SIZE 6

int main(){
	vector<int> nums;
	int data[_ARRAY_SIZE] = {1,2,4,5,1,3};
	for(int i = 0; i < _ARRAY_SIZE; i++) 
		nums.push_back(data[i]);
	cout << "Input : " << endl;
	for(unsigned int i = 0; i < nums.size(); i++) 
		cout << nums[i] << " "; 
	int k = 7;
	cout << endl << k << endl << "Output : " << endl;
	Solution mySolution = Solution();
	int answer = mySolution.smallestDistancePair(nums, k);
	cout << answer << endl;
}

