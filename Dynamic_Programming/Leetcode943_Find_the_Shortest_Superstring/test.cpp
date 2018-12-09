#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(){
	int n = 5;
	string words[n] = {"intentionexe", "execution", "esdfa", "adf", "asdfasd"};
	vector<string> A;
	for(int i = 0; i < n; i++) A.push_back(words[i]);
	Solution mySolution = Solution();
	string answer = mySolution.shortestSuperstring(A);
	cout << "Input: " << endl;
	cout << "[";
	for(int i = 0; i < n; i++) {
		cout << "\"" << words[i] << "\"";
		if(i < n-1) cout << ", ";
	}
	cout << "]" << endl;
	cout << "Output: " << endl;
	cout << "\"" << answer << "\"" << endl;
}

