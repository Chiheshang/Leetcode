#include"Datastruct.h"
using namespace std;
class Solution {
public:
	long long getDescentPeriods(vector<int>& prices) {
		long long ans = prices.size();
		long long num = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] == prices[i - 1] - 1) {
				num++;
				continue;
			}
			ans = ans + (1 + num) * num / 2;
			num = 0;
		}
		ans = ans + (1 + num) * num / 2;
		return ans;
	}
};