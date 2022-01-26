#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int minimumCost(vector<int>& cost) {
		sort(cost.begin(), cost.end());
		int ans = 0;
		int i;
		for (i = 0; (i * 3 + 2) < cost.size(); i++) {
			ans += cost[cost.size() - 1 - 3 * i - 1];
			ans += cost[cost.size() - 1 - 3 * i - 2];
		}
		if (cost.size() % 2 == 1) {
			ans += cost[0];
		}
		else if (cost.size() % 2 == 2) {
			ans += cost[0];
			ans += cost[1];
		}
		return ans;
		return ans;
	}
};