#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && (nums[i - 1] == nums[i] || nums[i - 1] == nums[i] - 1))continue;
			if (i < nums.size() - 1 && (nums[i + 1] == nums[i] || nums[i + 1] == nums[i] + 1))continue;
			ans.push_back(nums[i]);
		}
		return ans;
	}
};