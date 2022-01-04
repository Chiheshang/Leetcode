/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string temp = s + s;
        temp = temp.substr(1, temp.size() - 2);
        if (temp.find(s) != string::npos)
            return true;
        else
            return false;
    }
};
// @lc code=end
