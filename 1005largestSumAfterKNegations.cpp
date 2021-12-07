#include"Datastruct.h"
using namespace std;
class Solution {
public:
	static const bool compare(int a, int b) {
		return abs(a) < abs(b);
	}
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), compare);
		for (int i = nums.size() - 1; i >= 0 && k > 0; i--) {
			if (nums[i] < 0) {
				nums[i] *= -1;
				k--;
			}
		}
		k = k % 2;
		if (k && nums[0]) {
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > 0) {
					nums[i] *= -1;
					break;
				}
			}
		}
		int sum = 0;
		for_each(nums.begin(), nums.end(), [&sum](int cur) {sum += cur; });
		return sum;
	}
};
int main() {
	vector<int > a = { 3,-1,0,2 };
	Solution().largestSumAfterKNegations(a, 3);
}