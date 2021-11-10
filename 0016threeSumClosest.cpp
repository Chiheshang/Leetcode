#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int min = nums[0] + nums[1] + nums[2];
		int ans = abs(min - target);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				for (int k = j + 1; k < nums.size(); k++) {
					int cur = nums[i] + nums[j] + nums[k];
					if (ans > abs(cur - target)) {
						min = cur;
						ans = abs(cur - target);
					}
				}
			}
		}
		return ans;
	}
};