#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		vector<int>::iterator new_end = unique(nums.begin(), nums.end());
		nums.erase(new_end, nums.end());
		if (nums.size() > 2) {
			return nums[2];
		}
		else {
			return nums[0];
		}
	}
};