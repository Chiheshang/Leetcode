#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.empty())return ans;
		int begin = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1] + 1) {
				continue;
			}
			else {
				if (nums[i - 1] == begin) {
					ans.emplace_back(to_string(begin));
				}
				else {
					string cur = to_string(begin) + "->" + to_string(nums[i - 1]);
					ans.emplace_back(cur);
				}
				begin = nums[i];
			}
		}
		if (nums[nums.size() - 1] == begin) {
			ans.emplace_back(to_string(begin));
		}
		else {
			ans.emplace_back(to_string(begin) + "->" + to_string(nums[nums.size() - 1]));
		}
		return ans;
	}
};