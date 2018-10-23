#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return 0;
        vector<int> sortArray;
        for(int i = 0; i < (int)nums.size(); i++) sortArray.push_back(nums[i]);
        sort(sortArray.begin(), sortArray.end());
        int begin = 0, end = nums.size() - 1;
        while(begin <= end) {
            if(nums[begin] == sortArray[begin]) begin++;
            else break;
        }
        while(end > begin) {
            if(nums[end] == sortArray[end]) end--;
            else break;
        }
        return end-begin+1;
    }
};