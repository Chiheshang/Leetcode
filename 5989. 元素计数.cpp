#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int countElements(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		sort(nums.begin(), nums.end());
		int begin = 0, end = nums.size() - 1;
		while (begin < nums.size())
		{
			if (nums[begin] != nums[0])break;
			begin++;
		}
		while (end >= 0)
		{
			if (nums[end] != nums[nums.size() - 1])break;
			end--;
		}
		return std::max(end - begin + 1, 0);
	}
};