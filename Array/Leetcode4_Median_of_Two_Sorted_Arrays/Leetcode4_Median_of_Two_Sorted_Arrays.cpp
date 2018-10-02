#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findkthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k);

int main(){
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	cout << "array1: " << endl;
	for(int i = 0; i < (int)nums1.size(); i++) cout << nums1[i] << " ";
	cout << endl << "array2: " << endl;
	for(int i = 0; i < (int)nums2.size(); i++) cout << nums2[i] << " ";
	cout << endl << "answer:" << endl;
	double answer = findMedianSortedArrays(nums1, nums2);
	cout << answer << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	int left = (m + n + 1) / 2;
	int right = (m + n + 2) / 2;
	return (findkthNum(nums1, 0, nums2, 0, left) + findkthNum(nums1, 0, nums2, 0, right)) / 2.0; 
}

double findkthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
	int m = nums1.size();
	int n = nums2.size();
	if (m - i > n - j) return findkthNum(nums2, j, nums1, i, k);
    if (m == i) return nums2[j + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);
    int pa = min(i + k / 2, m);
    int pb = j + (k - pa + i);
    if (nums1[pa - 1] < nums2[pb - 1]) 
        return findkthNum(nums1, pa, nums2, j, k - pa + i);
    else if (nums1[pa - 1] > nums2[pb - 1]) 
        return findkthNum(nums1, i, nums2, pb, k - pb + j);
    else 
        return nums1[pa - 1];
}

