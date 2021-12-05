#include "Datastruct.h"
using namespace std;
class Solution {
public:
	void findnext(vector<vector<char>>& board, vector<int>& pos, queue<vector<int>>& border) {
		int x = pos[0];
		int y = pos[1];
		if (board[x][y] == '1')return;
		board[x][y] = '1';
		if (x + 1 < board.size()) {
			if (board[x + 1][y] == 'O')border.push({ x + 1,y });
		}
		if (x - 1 >= 0) {
			if (board[x - 1][y] == 'O')border.push({ x - 1,y });
		}
		if (y + 1 < board[0].size()) {
			if (board[x][y + 1] == 'O')border.push({ x ,y + 1 });
		}
		if (y - 1 >= 0) {
			if (board[x][y - 1] == 'O')border.push({ x ,y - 1 });
		}
	}
	void solve(vector<vector<char>>& board) {
		int length = board[0].size();
		int width = board.size();
		queue<vector<int>> border;
		for (int i = 0; i < width; i++) {
			if (board[i][0] == 'O')border.push({ i,0 });
			if (board[i][length - 1] == 'O')border.push({ i,length - 1 });
		}
		for (int i = 0; i < length; i++) {
			if (board[0][i] == 'O')border.push({ 0,i });
			if (board[width - 1][i] == 'O')border.push({ width - 1,i });
		}
		while (!border.empty())
		{
			auto cur = border.front();
			border.pop();
			if (board[cur[0]][cur[1]] == '1')continue;
			findnext(board, cur, border);
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++)
			{
				if (board[i][j] == 'O')board[i][j] = 'X';
			}
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++)
			{
				if (board[i][j] == '1')board[i][j] = 'O';
			}
		}
		return;
	}
};