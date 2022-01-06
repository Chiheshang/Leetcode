/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        string ans = "";
        if (num == 0)
            return "0";
        bool pos = true;
        if (num < 0)
        {
            pos = false;
            num = -num;
        }
        while (num)
        {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if (!pos)
            ans = '-' + ans;
        return ans;
    }
};
// @lc code=end
