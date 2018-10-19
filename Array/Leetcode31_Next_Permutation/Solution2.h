#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        if(i == 0) reverse(nums.begin(), nums.end());
        else {
            sort(nums.begin() + i, nums.end());
            int j = i;
            while(j < (int)nums.size() && nums[j] <= nums[i-1]) j++;
            swap(nums[j], nums[i-1]);
        }
    }
};