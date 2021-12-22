/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n && pos2 < m)
        {
            if (nums1[pos1] == nums2[pos2])
            {
                ans.push_back(nums1[pos1]);
                pos1++;
                pos2++;
                while (pos1 < n && nums1[pos1] == nums1[pos1 - 1])
                    pos1++;
                while (pos2 < m && nums2[pos2] == nums2[pos2 - 1])
                    pos2++;
            }
            else if(nums1[pos1] < nums2[pos2])
                pos1++;
            else
                pos2++;
        }
        return ans;
    }
};
// @lc code=end
