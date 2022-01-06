/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> result;

    void helper(int open, int close, int n, string current)
    {
        if (current.length() == n * 2)
        {
            result.push_back(current);
            return;
        }
        if (open < n)
            helper(open + 1, close, n, current + "(");
        if (close < open)
            helper(open, close + 1, n, current + ")");
    }
    vector<string> generateParenthesis(int n)
    {
        helper(0, 0, n, "");
        return result;
    }
};
// @lc code=end
