/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        if (s.size() == 0)
            return 0;
        int ans = 0;
        bool tag = false;
        for (char cur : s)
        {
            if (cur == ' ' && tag)
            {
                ans++;
                tag = false;
            }
            if (cur != ' ')
                tag = true;
        }
        return s[s.size() - 1] == ' ' ? ans : ans + 1;
    }
};
// @lc code=end
