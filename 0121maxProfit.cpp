#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		int min = prices[0];
		for (int cur : prices) {
			min = std::min(cur, min);
			ans = std::max(ans, cur - min);
		}
		return ans;
	}
};