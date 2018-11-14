#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        // empty array situation
        int row = matrix.size();
        if(row == 0) return answer;
        int col = matrix[0].size();
        if(col == 0) return answer;

        // (x,y) is on the left side of the start point
        int x = 0, y = -1;
        while(row > 0 && col > 0) {
            // move right col times
            for(int i = 1; i <= col; i++) {
                y++;
                answer.push_back(matrix[x][y]);
            }
            
            // move down (row-1) times
            for(int i = 1; i <= row-1; i++) {
                x++;
                answer.push_back(matrix[x][y]);
            }

            // move left (col-1) times if row > 1
            if(row > 1) {
                for(int i = 1; i <= col-1; i++) {
                    y--;
                    answer.push_back(matrix[x][y]);
                }
            }

            //move up (row-2) times if col > 1
            if(col > 1) {
                for(int i = 1; i <= row-2; i++) {
                    x--;
                    answer.push_back(matrix[x][y]);
                }
            }
            row -= 2;
            col -= 2;
        }
        return answer;
    }
};