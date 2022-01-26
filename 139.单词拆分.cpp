/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        map<int, vector<string>> index;
        for (string curstr : wordDict)
        {
            size_t pos = s.find(curstr);
            while (pos != string::npos)
            {
                index[pos].push_back(curstr);
                pos = s.find(curstr);
                pos = s.find(curstr, pos + 1);
            }
        }
        return dfs(index, s, 0);
    }
    bool dfs(map<int, vector<string>> &index, string &s, int start)
    {
        cout << start << endl;
        if (start == s.size())
            return true;
        if (start > s.size())
            return false;
        if (index[start].size() == 0)
            return false;
        bool find = false;
        for (string curstr : index[start])
        {
            if (dfs(index, s, start + curstr.size()))
            {
                find = true;
                break;
            }
        }
        return find;
    }
};
// @lc code=end
