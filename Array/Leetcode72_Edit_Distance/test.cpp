#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(){
	string word1 = "intention", word2 = "execution";
	Solution mySolution = Solution();
	int answer = mySolution.minDistance(word1, word2);
	cout << answer << endl;
}

