/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
    const static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<vector<int>> vec(score.size());
        for (int i = 0; i < score.size(); i++)
        {
            vec[i] = {i, score[i]};
        }
        sort(vec.begin(), vec.end(), compare);
        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); i++)
        {
            if (i == 0)
                ans[vec[i][0]] = "Gold Medal";
            else if (i == 1)
                ans[vec[i][0]] = "Silver Medal";
            else if (i == 2)
                ans[vec[i][0]] = "Bronze Medal";
            else
                ans[vec[i][0]] = to_string(i+1);
        }
        return ans;
    }
};
// @lc code=end
