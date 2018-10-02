#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getRow(int rowIndex);

int main(){
	int rowIndex = 33;
	cout << "rowIndex: " << endl << rowIndex << endl;

	vector<int> answer = getRow(rowIndex);
	cout << "answer:" << endl;
	for(int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

vector<int> getRow(int rowIndex) {
    vector<int> answer;
    int k = 0;
    long long int element = 1;
    while(k <= rowIndex) {
    	answer.push_back(element);
    	k++;
    	element = element * (rowIndex+1-k) / k;
    }
    return answer;
}