#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> width(grid.size());
        vector<int> length(grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                width[i] = std::max(width[i], grid[i][j]);
                length[j] = std::max(length[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += std::min(width[i], length[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
