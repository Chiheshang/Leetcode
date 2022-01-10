/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
    const bool compare static(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
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
        vector<string> ans;
        }
};
// @lc code=end
