/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int temp = 0;
        for (int cur : nums)
        {
            if (cur == 1)
                temp++;
            else
            {
                ans = std::max(ans, temp);
                temp = 0;
            }
        }
        ans = std::max(ans, temp);
        return ans;
    }
};
// @lc code=end
