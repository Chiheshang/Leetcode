#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int>positive;
		vector<int>negative;
		for (int cur : nums) {
			if (cur > 0)positive.push_back(cur);
			else negative.push_back(cur);
		}
		vector<int>ans;
		for (int i = 0; i < positive.size(); i++) {
			ans.push_back(positive[i]);
			ans.push_back(negative[i]);
		}
		return ans;
	}
};