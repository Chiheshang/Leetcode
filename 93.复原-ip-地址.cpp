/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string temp = "";
        dfs(s, ans, 0, 0, temp);
        return ans;
    }
    void dfs(string &s, vector<string> &ans, int step, int start, string curip)
    {
        if (step == 4 && start == s.size())
        {
            curip.erase(curip.end() - 1);
            ans.push_back(curip);
            return;
        }
        if ((s.size() - start) > (4 - step) * 3)
        {
            // cout << curip  << endl;
            return;
        }
        if ((s.size() - start) < (4 - step))
        {
            // cout << curip << endl;
            return;
        }
        int num = 0;
        if (s[start] == '0')
        {
            dfs(s, ans, step + 1, start + 1, curip + "0" + ".");
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            num *= 10;
            num += s[start + i] - '0';
            if (num > 255)
                break;
            dfs(s, ans, step + 1, start + i + 1, curip + to_string(num) + ".");
        }
    }
};
// @lc code=end
