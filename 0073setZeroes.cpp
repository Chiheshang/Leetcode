#include"Datastruct.h"
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<int> width;
		vector<int> length;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					width.emplace_back(j);
					length.emplace_back(i);
				}
			}
		}
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (count(width.begin(), width.end(), j) ||
					count(length.begin(), length.end(), i))
					matrix[i][j] = 0;
			}
		}
	}
};