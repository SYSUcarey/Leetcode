#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 <= 0) return size2;
        if(size2 <= 0) return size1;
        int d[size1+1][size2+1];
        for(int i = 0; i <= size1; i++) {
            d[i][0] = i;
        }
        for(int j = 0; j <= size2; j++) {
            d[0][j] = j;
        }
        int min1, min2, min3;
        for(int i = 1; i <= size1; i++) {
            for(int j = 1; j <= size2; j++) {
                // replace operation
                if(word1[i-1] == word2[j-1]) min1 = d[i-1][j-1];
                else min1 = d[i-1][j-1] + 1;
                // insert operation
                min2 = d[i][j-1] + 1;
                // remove operation
                min3 = d[i-1][j] + 1;
                d[i][j] = min(min1, min2);
                d[i][j] = min(d[i][j], min3);
            }
        }
        return d[size1][size2];
    }
};