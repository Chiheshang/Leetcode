#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};