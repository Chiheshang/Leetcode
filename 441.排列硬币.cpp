/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int i = 0;
        for (; n >= 0; n -= ++i)
            ;
        return i - 1;
    }
};
// @lc code=end
