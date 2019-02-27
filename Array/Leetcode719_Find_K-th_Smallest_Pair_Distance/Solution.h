#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = nums[n-1];
        int bucket[m+1] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int d = nums[i]-nums[j];
                if(d < 0) d = -d;
                bucket[d]++;
            }
        }
        int count = 0, index = 0;
        while(index <= m) {
            if(bucket[index] > 0) {
                count += bucket[index];
                if(count >= k) return index;
            }
            index++;
        }
        return -1;
    }
};