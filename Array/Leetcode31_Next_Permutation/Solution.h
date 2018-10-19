#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int temp;
    bool isFinished = false;

    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] >= nums[i+1]) continue;
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums, i, j);
            i = i + 1;
            j = nums.size() - 1;
            reverse(nums, i, j);
            break;
        }
        if(!isFinished) reverse(nums, 0, nums.size() - 1);
    }

    void swap(vector<int>& nums, int i, int j) {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
        isFinished = true;
    }
};