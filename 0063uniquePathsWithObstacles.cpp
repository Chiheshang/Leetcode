#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		for (int i = 0; i < obstacleGrid.size(); i++) {
			if (obstacleGrid[i][0] == 1) {
				for (int j = i + 1; j < obstacleGrid.size(); j++) {
					obstacleGrid[j][0] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < obstacleGrid[0].size(); i++) {
			if (obstacleGrid[0][i] == 1) {
				for (int j = i + 1; j < obstacleGrid[0].size(); j++) {
					obstacleGrid[0][j] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < obstacleGrid.size(); i++) {
			for (int j = 0; j < obstacleGrid[0].size(); j++) {
				if (obstacleGrid[i][j] == 1)obstacleGrid[i][j] = 0;
				else if (i == 0 || j == 0)obstacleGrid[i][j] = 1;
				else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
		return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};