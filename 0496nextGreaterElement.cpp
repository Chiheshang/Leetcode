#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		for (int cur : nums1) {
			auto it = find(nums2.begin(), nums2.end(), cur);
            it++;
            bool find = false;
            while (it != nums2.end()) {
                if (*it > cur) {
                    ans.emplace_back(*it);
                    find = true;
                    break;
                }
                else {
                    it++;
                }
            }
            if (!find)
                ans.emplace_back(-1);
		}
		return ans;
	}
};