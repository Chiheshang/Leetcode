#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		set<vector<int>> raw;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				int left = j + 1;
				int right = nums.size() - 1;
				while (left < right) {
					long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum > INT32_MAX || sum > target) {
						right--;
					}
					else if (sum < target) {
						left++;
					}
					else if (sum == target) {
						raw.insert({ nums[i] , nums[j] , nums[left] , nums[right] });
						left++;
						right--;
					}
				}
			}
		}
		vector<vector<int>>ans;
		ans.assign(raw.begin(), raw.end());
		return ans;
	}
};