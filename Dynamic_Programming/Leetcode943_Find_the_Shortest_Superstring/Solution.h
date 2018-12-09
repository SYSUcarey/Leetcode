#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        int dist[n][n];
        for(int i = 0; i < n; i++) {
            dist[i][i] = 20+1;
        }
        for(int i = 0; i < n; i++) {
        	for(int j = i+1; j < n; j++) {
        		dist[i][j] = cost(A[i], A[j]);
                dist[j][i] = cost(A[j], A[i]);
        	}
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, 20*12+1));
        vector<vector<int>> praent(1 << n, vector<int>(n, -1));

        // init
        for(int i = 0; i < n; i++) 
            dp[1 << i][i] = A[i].length();

        // dp
        for(int s = 1; s < (1 << n); s++) {
            for(int i = 0; i < n; i++) {
                if(!(s & (1<<i))) continue;
                int prev = s - (1<<i);
                for(int j = 0; j < n; j++) {
                    if(dp[prev][j] + dist[j][i] < dp[s][i]) {
                        dp[s][i] = dp[prev][j] + dist[j][i];
                        praent[s][i] = j;
                    }
                }
            }
        }

        // find path
        auto it = min_element(dp.back().begin(), dp.back().end());
        int cur = it - dp.back().begin();
        int s = (1 << n) - 1;
        string ans;
        while(s) {
            int prev = praent[s][cur];
            if(prev < 0) ans = A[cur] + ans;
            else ans = A[cur].substr(A[cur].length()-dist[prev][cur]) + ans;
            s &= ~(1 << cur);
            cur =prev;
        }
        return ans;
    }   

private:
    int cost(const string& str1, const string& str2) {
        int a = str1.length(), b = str2.length();
        int _cost = b;
        for(int k = 1; k <= min(a, b); k++) {
            if(str1.substr(a - k) == str2.substr(0, k)) {
                _cost = b - k;
            }
        }
        return _cost;
    }

};


