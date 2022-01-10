/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
// #include "Datastruct.h"
// using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &c)
    {
        int l = 0, r = c.size() - 1, avg;
        sort(begin(c), end(c));
        while (l <= r)
        {
            if (c[avg = (r + l) / 2] < c.size() - avg)
                l = avg + 1;
            else
                r = avg - 1;
        }
        return c.size() - l;
    }
};
// @lc code=end
