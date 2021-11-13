#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        //f(i,j)=min(i<=k<=j){k+max{f(i,k-1),f(k+1,j)}}
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    if (i >= j);
                    continue;
                }
                int min = i + dp[i + 1][j];
                for (int k = i; k <= j; k++) {
                    min = std::min(min, (k + std::max(dp[i][k - 1], dp[k + 1][j])));
                }
                dp[i][j] = min;
            }
        }
        return dp[1][n];
    }
};