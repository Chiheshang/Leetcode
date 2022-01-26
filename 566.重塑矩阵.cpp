/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if (mat.size() * mat[0].size() != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = mat[(i * c + j) / mat[0].size()][(i * c + j) % mat[0].size()];
            }
        }
        return ans;
    }
};
// @lc code=end
