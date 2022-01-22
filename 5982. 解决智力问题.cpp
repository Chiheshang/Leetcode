#include"Datastruct.h"
#include<mutex>
using namespace std;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i], dp[i + 1]);
            int nxt = min(i + 1 + questions[i][1], n);
            dp[nxt] = max(dp[nxt], dp[i] + questions[i][0]);
        }
        return dp[n];
    }
};
int main() {
	vector<vector<int>> a = { {21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3} };
	Solution().mostPoints(a);
    mutex g_mtx;
    g_mtx.lock();
}