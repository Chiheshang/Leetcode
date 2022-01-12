/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                swap(nums[j], nums[i++]);
            }
        }
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 1)
            {
                swap(nums[j], nums[i++]);
            }
        }
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 2)
            {
                swap(nums[j], nums[i++]);
            }
        }
    }
};
// @lc code=end
