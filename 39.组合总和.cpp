/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    set<vector<int>> ans;
    vector<int> candidate;
    int tar;
    void help(int curnum, vector<int> curvec)
    {
        if (curnum == tar)
        {
            sort(curvec.begin(), curvec.end());
            ans.insert(curvec);
            return;
        }
        for (int cur : candidate)
        {
            cout << cur << endl;
            if ((curnum + cur) == tar)
            {
                curvec.push_back(cur);
                sort(curvec.begin(), curvec.end());
                ans.insert(curvec);
                return;
            }
            else if ((curnum + cur) < tar)
            {
                curnum += cur;
                curvec.push_back(cur);
                help(curnum, curvec);
            }
            else
            {
                continue;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        tar = target;
        sort(candidates.begin(), candidates.end());
        candidate = candidates;
        vector<int> curvec;
        help(0, curvec);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
// @lc code=endcdrfd-\

