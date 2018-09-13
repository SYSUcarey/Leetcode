#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main(){
	vector<int> numbers;
	srand((int)time(0));
	
	for(int i = 0; i < 10; i++) {
		int num = -20 + rand()%40;
		numbers.push_back(num);
	}
	cout << "Array of nums: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	int target = -30 + rand()%60;
	cout << endl << "target:" << endl << target;
	int answer = threeSumClosest(numbers, target);
	//cout << endl << "Array sorted: " << endl;
	//for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	cout << endl << "answer" << endl << answer << endl;

}

int threeSumClosest(vector<int>& nums, int target) {
	//sorted
    int temp = 0;
    for(int i = 0; i < nums.size(); i++) {
    	for(int j = 0; j < nums.size() - i - 1; j++) {
    		if(nums[j] > nums[j+1]) {
    			temp = nums[j+1];
    			nums[j+1] = nums[j];
    			nums[j] = temp;
    		}
    	}
    }
    int min_sum = nums[0] + nums[1] + nums[2];
    int head, tail;
    for(int i = 0; i < nums.size(); i++) {
    	head = i + 1;
    	tail = nums.size()-1;
    	while (head < tail) {
    		temp = nums[i] + nums[head] + nums[tail];
	    	if(temp > target) tail--;
	    	else if(temp < target) head++;
	    	else if(temp == target) return temp;
	    	if(abs(temp - target) < abs(min_sum - target)) min_sum = temp;
    	}
    }
    return min_sum;
}