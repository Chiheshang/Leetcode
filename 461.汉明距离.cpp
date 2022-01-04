/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        while (x > 0 || y > 0)
        {
            if (x % 2 != y % 2)
                ans++;
            x /= 2;
            y /= 2;
        }
        return ans;
    }
};
// @lc code=end
