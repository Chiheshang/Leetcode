/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> cal(nums.size()+1);
        for (int cur : nums)
        {
            cal[cur]++;
        }
        vector<int> ans;
        for (int i = 1; i < cal.size(); i++)
        {
            if (!cal[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
