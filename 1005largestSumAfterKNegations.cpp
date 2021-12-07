#include "Datastruct.h"
using namespace std;
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		vector<int> pos;
		deque<int> nega;
		bool zero = false;
		for_each(nums.begin(), nums.end(), [&pos, &nega, &zero](int cur) {if (cur < 0) { nega.push_back(cur); }
		else if (cur > 0) { pos.push_back(cur); }
		else zero = true; });
		sort(nega.begin(), nega.end());
		for (int i = 0; i < k && i < nega.size(); i++) {
			pos.push_back(nega[0] * -1);
			nega.pop_front();
		}
		sort(pos.begin(), pos.end());
		int sum = 0;
		if (!nega.size()) {
			if (!(k % 2 == 0 || zero)) {
				pos[0] = -pos[0];
			}
		}
		for_each(pos.begin(), pos.end(), [&sum](int cur) {sum += cur; });
		for_each(nega.begin(), nega.end(), [&sum](int cur) {sum += cur; });
		return sum;
	}
};