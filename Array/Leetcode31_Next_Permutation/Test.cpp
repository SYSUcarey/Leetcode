#include <iostream>
#include <vector>
#include "Solution.h"
#include "Solution2.h"
using namespace std;

int main(){
	vector<int> nums;
	int data[9]= {20, 15, 21, 17, 6, 4, 3, 2, 1};
	for(int i = 0; i < 9; i++) 
		nums.push_back(data[i]);
	cout << "Input : " << endl;
	for(unsigned int i = 0; i < nums.size(); i++) 
		cout << nums[i] << " "; 
	cout << endl << "Output : " << endl;
	//Solution mySolution = Solution();
	Solution2 mySolution = Solution2();
	mySolution.nextPermutation(nums);
	for(unsigned int i = 0; i < nums.size(); i++) 
		cout << nums[i] << " "; 
	cout << endl;
}

