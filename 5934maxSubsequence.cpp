#include"Datastruct.h"
using namespace std;
class Solution {
public:
	const static bool cmp(vector<int>& a, vector<int>& b) {

		return a[1] > b[1];
	}
	const static bool cmp1(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<vector<int>> index(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			index[i] = { i,nums[i] };
		}
		sort(index.begin(), index.end(), cmp);
		vector<vector<int>> fist(k);
		for (int i = 0; i < k; i++) {
			fist[i] = index[i];
		}
		sort(fist.begin(), fist.end(), cmp1);
		vector<int> ans(k);
		for (auto cur : fist) {
			ans.push_back(cur[1]);
		}
		return ans;
	}
};
int main() {
	vector<int> a = { 2,1,3,3 };
	Solution().maxSubsequence(a, 2);
}