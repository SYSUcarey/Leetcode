#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(){
	vector<int> numbers;
	srand((int)time(0));
	for(int i = 0; i < 20; i++) {
		int num = (rand()%10) + i*10;
		numbers.push_back(num);
	}
	cout << "input array: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	int target = numbers[rand()%19] + numbers[rand()%19];
	cout << endl << "target: " << endl << target;
	cout << endl << "answer:" << endl;
	vector<int>	answer = twoSum(numbers, target);
	for(unsigned int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
}

vector<int> twoSum(vector<int>& numbers, int target) {
	int head = 0, tail = numbers.size()-1;
    while(head!=tail) {
        if(numbers[head] + numbers[tail] < target) head++;
        else if(numbers[head] + numbers[tail] > target) tail--;
        else if(numbers[head] + numbers[tail] == target) return {head+1,tail+1};
    }
}