#include "Datastruct.h"
using namespace std;
class Solution {
public:
	int cur;
	void createTag(vector<vector<int>>& grid, int row, int col) {
		if (row < 0 || row > grid.size() - 1 || col < 0 || col > grid[0].size() - 1) {
			return;
		}
		if (grid[row][col] != cur)return;
		grid[row][col] = 0;
		createTag(grid, row + 1, col);
		createTag(grid, row - 1, col);
		createTag(grid, row, col + 1);
		createTag(grid, row, col - 1);
		return;
	}
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		cur = grid[row][col];
		createTag(grid, row, col);
		bool edge = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				edge = true;
				if (grid[i][j] != 0)continue;
				if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) {
					grid[i][j] = -1;
				}
				else {
					if (i + 1 >= 0 && i + 1 < grid.size() && j >= 0 && j < grid[0].size() &&
						grid[i + 1][j] != 0 && grid[i + 1][j] != -1)edge = false;
					if (i - 1 >= 0 && i - 1 < grid.size() && j >= 0 && j < grid[0].size() &&
						grid[i - 1][j] != 0 && grid[i - 1][j] != -1)edge = false;
					if (i >= 0 && i < grid.size() && j + 1 >= 0 && j + 1 < grid[0].size() &&
						grid[i][j + 1] != 0 && grid[i][j + 1] != -1)edge = false;
					if (i >= 0 && i < grid.size() && j - 1 >= 0 && j - 1 < grid[0].size() &&
						grid[i][j - 1] != 0 && grid[i][j - 1] != -1)edge = false;
					if (!edge)grid[i][j] = -1;
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0)
					grid[i][j] = cur;
				if (grid[i][j] == -1)
					grid[i][j] = color;
			}
		}
		return grid;
	}
};
int main() {
	vector<vector<int>> a = { {1,1,1}, {1,1,1}, {1,1,1} };
	Solution().colorBorder(a, 1, 1, 2);
}