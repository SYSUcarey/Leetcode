#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int searchInsert(vector<int>& nums, int target);

int main(){
	vector<int> numbers;
	srand((int)time(0));
	for(int i = 0; i < 20; i++) {
		int num = (rand()%10) + i*10;
		numbers.push_back(num);
	}
	cout << "input array: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	int target = rand()%200;
	cout << endl << "target: " << endl << target;
	cout << endl << "answer:";
	int answer = searchInsert(numbers, target);
	cout << endl << answer << endl;
}

int searchInsert(vector<int>& nums, int target) {
    for(unsigned int i = 0; i < nums.size(); i++) {
        if(target <= nums[i]) return i;
    }
    return nums.size();
}