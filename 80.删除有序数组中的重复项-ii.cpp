/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        for (int j = 2; j < nums.size(); j++)
        {
            if (nums[j] == nums[j - 2 - count])
                count++;
            else
                nums[j - count] = nums[j];
        }
        return nums.size() - count;
    }
};
// @lc code=end
