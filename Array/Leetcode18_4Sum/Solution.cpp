#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main(){
	vector<int> numbers;
	int target = 3;
	int array[] = {-1,2,2,-5,0,-1,4};
	for(unsigned int i = 0; i < sizeof(array)/sizeof(int); i++)
		numbers.push_back(array[i]);

	cout << "Array of nums: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	vector<vector<int>> answer = fourSum(numbers, target);
	cout << endl << "answer:";
	for(int i = 0; i < (int)answer.size(); i++) {
		cout << endl;
		for (int j = 0; j < (int)answer[i].size(); j++) {
			cout<< answer[i][j] << " ";
		}
	}
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	//sorted the array
	sort(nums.begin(), nums.end());
	//determine the smallest and largest
	vector<vector<int>> answer;
	int smallest, head, tail, largest;
	int sum;
	for(smallest = 0; smallest < (int)nums.size(); smallest++) {
		if(smallest > 0 && nums[smallest] == nums[smallest-1]) continue;
		for(largest = (int)nums.size()-1; largest >= smallest+3; largest--) {
			if(largest < (int)nums.size()-1 && nums[largest] == nums[largest+1]) continue;
			//find the two Sum answer
			head = smallest + 1;
			tail = largest - 1;
			while(head < tail) {
				sum = nums[smallest] + nums[head] + nums[tail] + nums[largest];
				if(sum < target) head++;
	    		else if(sum > target) tail--;
	    		else {
	    			answer.push_back({nums[smallest], nums[head], nums[tail], nums[largest]});
	    			head++;
	    			// avoid the same pair of head and tail numbers
	    			while(nums[head] == nums[head-1]) {
	    				head++;
	    			}
	    		}
			}

		}
	}
	return answer;
}