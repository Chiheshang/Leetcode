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
    vector<int> nextGreaterElementStack(vector<int>& nums1, vector<int>& nums2) {//µ¥µ÷Õ»
        unordered_map<int, int> hashmap;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashmap[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};