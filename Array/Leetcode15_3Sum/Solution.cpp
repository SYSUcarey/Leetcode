#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);
#define N 8

int main(){
	vector<int> numbers;
	int array[N] = {-1, 0, 1, -1, -1, 1, 2, -4};
	for(int i = 0; i < N; i++)
		numbers.push_back(array[i]);
	cout << "Array of nums: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	vector<vector<int>> answer = threeSum(numbers);
	cout << endl << "answer:";
	for(int i = 0; i < (int)answer.size(); i++) {
		cout << endl;
		for (int j = 0; j < (int)answer[i].size(); j++) {
			cout<< answer[i][j] << " ";
		}
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	//sort the array
	sort(nums.begin(), nums.end());
	
	//find the answer vector<vector<int>>
    vector<vector<int>> answer;
    int head, tail;
    for(int i = 0; i < (int)nums.size(); i++) {
    	if(nums[i] == nums[i-1] && i != 0) continue;
    	head = i + 1;
    	tail = nums.size()-1; 
    	while(head < tail) {
    		if(nums[head] + nums[tail] < -nums[i]) head++;
    		else if(nums[head] + nums[tail] > -nums[i]) tail--;
    		else {
    			if(nums[head] == nums[head-1] && head != i+1) {
    				head++;
    				continue;
    			}
    			answer.push_back({nums[i], nums[head], nums[tail]});
    			head++;
    		}
    	}
    }
    return answer;
}