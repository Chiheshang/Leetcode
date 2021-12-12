#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int countPoints(string rings) {
		vector<vector<int>> count(100, vector<int>(3, 0));
		for (int i = 0; i < rings.size() / 2; i++) {
				if (rings[i * 2] == 'R')
					count[rings[i * 2 + 1] - '0'][0]++;
			if (rings[i * 2] == 'G')
				count[rings[i * 2 + 1] - '0'][1]++;
			if (rings[i * 2] == 'B')
				count[rings[i * 2 + 1] - '0'][2]++;
		}
		int ans = 0;
		for (auto cur : count) {
			if (cur[0] && cur[1] && cur[2])ans++;
		}
		return ans;
	}
};
int main() {
	Solution().countPoints("B0B6G0");
}