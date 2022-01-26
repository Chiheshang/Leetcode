#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int max = 0;
	bool isValid(vector<vector<int>>& statements, vector<int>& state, int cur) {
		for (int i = 0; i < statements.size(); i++) {
			if (statements[cur][i] == 2)continue;
			if (state[i] == 2)continue;
			if (state[i] != statements[cur][i])return false;
		}
		return true;
	}
	void backtrack(vector<vector<int>>& statements, int i, vector<int> state) {
		if (i == statements.size()) {//0-bad,1-good,2-undefine
			int j = 0;
			for (int cur : state) {
				if (cur == 1)j++;
			}
			max = std::max(max, j);
			return;
		}
		for (int k = 0; k < statements.size(); k++) {
			if (state[k] != 2)continue;
			if (!isValid(statements, state, k))
				state[k] = 2;
			// ×öÑ¡Ôñ
			state[k] = 1;
			i++;
			for (int j = 0; j < statements.size(); j++) {
				if (statements[k][j] != 2) {
					if (state[j] == 2)i++;
					if (statements[k][j] == 1 && isValid(statements, state, j)) {
						if (state[j] == 0)return;
						state[j] = 1;
					}
					else {
						if (state[j] == 1)return;
						state[j] = 0;
					}
				}
			}
			backtrack(statements, i, state);
		}
	}
	int maximumGood(vector<vector<int>>& statements) {
		vector<int> state(statements.size(), 2);
		for (int k = 0; k < statements.size(); k++) {
			backtrack(statements, k, state);
		}
		return max;
	}
};
int main() {
	vector<vector<int>> statements = { {2,2,2,2},{1,2,1,0},{0,2,2,2},{0,0,0,2} };
	cout << Solution().maximumGood(statements);

}