#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> index;
		for (int i = 0; i < nums.size(); i++) {
			if (auto it = index.find(nums[i]) != index.end()) {
				if (i - (index.find(nums[i])->second) <= k) {
					return true;
				}
			}
			index[nums[i]] = i;
		}
		return false;
	}
};