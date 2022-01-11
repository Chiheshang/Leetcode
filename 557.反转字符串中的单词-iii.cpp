/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};
// @lc code=end
