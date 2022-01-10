#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool checkValid(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<int> flag(n + 1, 0);
		vector<int> flag1(n + 1, 0);
		for (int i = 0; i < n; i++) {
			flag=flag1;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] > n || matrix[i][j] < 1 || flag[matrix[i][j]]) {
					return false;
				}
				else flag[matrix[i][j]]++;
			}
		}
		for (int i = 0; i < n; i++) {
			flag = flag1;
			for (int j = 0; j < n; j++) {
				if (matrix[j][i] > n || matrix[j][i] < 1 || flag[matrix[j][i]]) {
					return false;
				}
				else flag[matrix[j][i]]++;
			}
		}
		return true;
	}
};
int main() {
	vector<vector<int>> a = { {1, 2, 3},{3, 1, 2},{2, 3, 1} };
	Solution().checkValid(a);
}