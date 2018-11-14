#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;


#define ARRAY_COL 4
#define ARRAY_ROW 3

int main(){
	vector<vector<int>> matrix;
	int data[ARRAY_ROW][ARRAY_COL] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	for(int i = 0; i < ARRAY_ROW; i++) {
		vector<int> temp;
		for(int j = 0; j < ARRAY_COL; j++)
			temp.push_back(data[i][j]);
		matrix.push_back(temp);
	}
	cout << "Input : ";
	for(int i = 0; i < ARRAY_ROW; i++) {
		cout << endl;
		for(int j = 0; j < ARRAY_COL; j++) 
			cout << matrix[i][j] << " "; 
	}
	cout << endl << "Output : " << endl;
	Solution mySolution = Solution();
	vector<int> answer = mySolution.spiralOrder(matrix);
	for(int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}

