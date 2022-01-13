/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int counterOne = 0;
        int counterTwo = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            counterOne = (~counterTwo) & (counterOne ^ nums[i]);
            counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
        }
        return counterOne;
    }
};
// @lc code=end
