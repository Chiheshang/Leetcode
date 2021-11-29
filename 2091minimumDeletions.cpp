#include "Datastruct.h"
using namespace std;
class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		int index_min = 0;
		int min = INT32_MAX;
		int index_max = 0;
		int max = INT32_MIN;
		for (int i = 0; i < nums.size(); i++) {
			if (min > nums[i]) {
				min = nums[i];
				index_min = i;
			}
			if (max < nums[i]) {
				max = nums[i];
				index_max = i;
			}
		}
		if (index_min > index_max)swap(index_max, index_min);
		int ans = std::min((int)nums.size() - index_min, index_max + 1);
		ans = std::min(ans, index_min + 1 + (int)nums.size() - index_max);
		return ans;
	}
};