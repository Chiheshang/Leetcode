#include"Datastruct.h"
using namespace std;
class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			int min = nums[i], max = nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				min = std::min(min, nums[j]);
				max = std::max(max, nums[j]);
				ans += (long long)max - min;
			}
		}
		return ans;
	}
};