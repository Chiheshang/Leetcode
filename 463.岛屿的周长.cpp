/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int temp = 0;
                if (grid[i][j] == 1)
                {
                    if (i == 0 || grid[i - 1][j] != 1)
                        temp++;
                    if (j == 0 || grid[i][j - 1] != 1)
                        temp++;
                    if (i == grid.size() - 1 || grid[i + 1][j] != 1)
                        temp++;
                    if (j == grid[0].size() - 1 || grid[i][j + 1] != 1)
                        temp++;
                }
                // cout << "i=" << i << "j=" << j << "temp=" << temp << endl;
                ans += temp;
            }
        }
        return ans;
    }
};
// @lc code=end
