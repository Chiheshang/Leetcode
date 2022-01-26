#include"Datastruct.h"
using namespace std;
class Solution {
public:
	static int row;
	static int col;
	const static bool cmp(vector<int>& a, vector<int>& b) {
		int len1 = abs(a[0] - row) + abs(a[1] - col);
		int len2 = abs(b[0] - row) + abs(b[1] - col);
		if (len1 != len2)return len1 > len2;
		if (a[2] != b[2])return a[2] > b[2];
		if (a[0] != b[0])return a[0] > b[0];
		return a[1] > b[1];
	}
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
		row = start[0];
		col = start[1];
		vector<vector<int>> ans;
		vector<vector<int>> vec;
		set<vector<int>> visited;
		visited.insert({ row, col });
		queue< vector<int>>q;
		q.push({ start[0],start[1] });
		while (!q.empty())
		{
			auto& cur = q.front();
			q.pop();
			if (grid[cur[0]][cur[1]] >= pricing[0] && grid[cur[0]][cur[1]] <= pricing[1]) {
				vec.push_back({ cur[0] ,cur[1] ,grid[cur[0]][cur[1]] });
			}
			vector<vector<int>> pos;
			if (cur[0] > 0 && visited.find({ cur[0] - 1,cur[1] }) == visited.end())pos.push_back({ cur[0] - 1,cur[1] });
			if (cur[0] < grid.size() && visited.find({ cur[0] + 1,cur[1] }) == visited.end())pos.push_back({ cur[0] + 1,cur[1] });
			if (cur[1] > 0 && visited.find({ cur[0] ,cur[1] - 1 }) == visited.end())pos.push_back({ cur[0] ,cur[1] - 1 });
			if (cur[1] < grid[0].size() && visited.find({ cur[0] ,cur[1] + 1 }) == visited.end())pos.push_back({ cur[0] ,cur[1] + 1 });
			for (auto& curpos : pos) {
				if (grid[curpos[0]][curpos[1]] == 0)continue;
				q.push({ curpos[0],curpos[1] });
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		for (auto& curvec : vec) {
			ans.push_back({ curvec[0],curvec[1] });
		}
		return ans;
	}
};