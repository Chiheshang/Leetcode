/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int numA = 0;
        int numL = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'P')
                continue;
            else if (s[i] == 'A')
            {
                numA++;
                if (numA >= 2)
                    return false;
            }
            else if (s[i] == 'L')
            {
                if (i > s.size() - 3)
                    continue;
                if (s[i + 1] != 'L')
                    continue;
                i++;
                if (s[i + 1] == 'L')
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
