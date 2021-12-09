#include "Datastruct.h"
using namespace std;
class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int numx = 0, numo = 0;
		for (int i = 0; i < board.size(); i++) {
			for (char cur : board[i]) {
				if (cur == 'X')numx++;
				else if (cur == 'O')numo++;
			}
		}
		if (numx - numo > 1)return false;
		if (numx < numo)return false;
		bool tag = false;
		for (string cur : board) {
			if (cur == "XXX" || cur == "OOO") {
				if (tag)return false;
				tag = true;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X' ||
				board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
				if (tag)return false;
				tag = true;
			}
		}
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
			board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
			if (tag)return false;
			tag = true;
		}
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' ||
			board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
			if (tag)return false;
			tag = true;
		}
		return true;
	}
};