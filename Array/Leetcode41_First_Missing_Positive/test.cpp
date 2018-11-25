#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;


#define LENGTH 5
int main(){
	vector<int> nums;
	int data[LENGTH] = {3,4,4,1,1};
	for(int i = 0; i < LENGTH; i++) {
		nums.push_back(data[i]);
	}
	cout << "Input : " << endl;
	for(int i = 0; i < LENGTH; i++) {
		cout << nums[i] << " ";
	}
	cout << endl << "Output : " << endl;
	Solution mySolution = Solution();
	int answer = mySolution.firstMissingPositive(nums);
	cout << answer << endl;
}

