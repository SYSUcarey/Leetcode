#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(){

	int target = 16;
	vector<vector<int>> matrix;
	int nums[3][4] = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	cout << "Input :" << endl;
	for(int i = 0; i < 3; i++){
		vector<int> temp;
		for(int j = 0; j < 4; j++) {
			temp.push_back(nums[i][j]);
			cout << nums[i][j] << " ";
		}
		matrix.push_back(temp);
		cout << endl;
	}

	bool answer;
	cout << "answer: " << endl;
	answer = searchMatrix(matrix, target);
	if(answer) cout << "true" << endl;
	else cout << "false" << endl; 
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size() <= 0) return false;
	if(matrix[0].size() <= 0) return false;
	int row = matrix.size();
	int col = matrix[0].size();
	for(int i = 0; i < row; i++) {
		if(matrix[i][col-1] < target) continue;
		for(int j = col-1; j >= 0; j--) {
			if(matrix[i][j] == target) return true;
		}
		return false;
	}
	return false;
}