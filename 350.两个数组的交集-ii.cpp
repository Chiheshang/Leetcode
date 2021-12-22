/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1,n2;
        for(int cur:nums1)
        {
            n1[cur]++;
        }
        for(int cur:nums2)
        {
            n2[cur]++;
        }
        vector<int> ans;
        for(auto it=n1.begin();it!=n1.end();it++)
        {
            if(n2.find(it->first)!=n2.end())
            {
                for(int i=0;i<std::min(it->second,n2[it->first]);i++)
                {
                    ans.push_back(it->first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

