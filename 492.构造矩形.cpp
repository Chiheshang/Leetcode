/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int wid = pow(area, 0.5);
        // cout << wid;
        while (area % wid != 0)
        {
            wid--;
        }
        return {area / wid, wid};
    }
};
// @lc code=end
