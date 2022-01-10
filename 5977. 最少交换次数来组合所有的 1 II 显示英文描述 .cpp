#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int minSwaps(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		int num = 0;
		for (int cur : nums) {
			if (cur)num++;
		}
		int cur = 0;
		for (int i = 0; i < num; i++) {
			if (nums[i])cur++;
		}
		dp[num - 1] = cur;
		int ans = cur;
		for (int i = num; i < nums.size(); i++) {
			dp[i] = dp[i - 1];
			if (nums[i]) dp[i]++;
			if (nums[i - num])dp[i]--;
			ans = std::max(ans, dp[i]);
		}
		for (int i = 0; i < num; i++) {
			if (i == 0)dp[i] = dp[nums.size() - 1];
			else dp[i] = dp[i - 1];
			if (nums[i]) dp[i]++;
			if (nums[nums.size() + i - num])dp[i]--;
			ans = std::max(ans, dp[i]);
		}
		return num - ans;
	}
};
int main() {
	vector<int> a = { 0,0,0 };
	Solution().minSwaps(a);
}