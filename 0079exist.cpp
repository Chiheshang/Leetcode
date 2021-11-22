#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (hasnext(board, i, j, word)) {
					return true;
				}
			}
		}
		return false;
	}
	bool hasnext(vector<vector<char>> board, int i, int j, string word) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())return false;
		if (board[i][j] != word[0])return false;
		else {
			board[i][j] = -1;
		}
		if (word.size() == 1) {
			return true;
		}
		word.erase(word.begin());
		return  hasnext(board, i - 1, j, word) || hasnext(board, i + 1, j, word) ||
			hasnext(board, i, j - 1, word) || hasnext(board, i, j + 1, word);
	}
};
int main() {
	vector<vector<char>> a = { {'a','b'} ,{'c','d'} };
	bool ab= Solution().exist(a, "abcd") ;
	return 1;
}