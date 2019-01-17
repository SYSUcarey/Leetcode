#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int FirstMax = INT_MIN;
        int SecondMax = INT_MIN;
        int ThirdMax = INT_MIN;
        int n = nums.size();
        bool has_INT_MIN = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= ThirdMax) {
                if(nums[i] == INT_MIN) has_INT_MIN = true;
                continue;
            }
            if(nums[i] == FirstMax || nums[i] == SecondMax || nums[i] == ThirdMax) {
                continue;
            }
            else if (nums[i] < SecondMax) ThirdMax = nums[i];
            else if (nums[i] < FirstMax) {
                ThirdMax = SecondMax;
                SecondMax = nums[i];
            }
            else {
                ThirdMax = SecondMax;
                SecondMax = FirstMax;
                FirstMax = nums[i];
            }
        }
        if(n < 3) return FirstMax;
        if(ThirdMax == INT_MIN) {
            if(!has_INT_MIN || SecondMax == INT_MIN) return FirstMax;
        }
        return ThirdMax;
    }
};