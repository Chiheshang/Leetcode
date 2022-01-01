#include"Datastruct.h"
using namespace std;
class Solution {
public:
	inline bool checkValid(int n, vector<int>& pos) {
		return pos[0]<0 || pos[0]>(n - 1) || pos[1]<0 || pos[1]>(n - 1);
	}
	vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		vector<int> ans;
		for (int i = 0; i < s.size(); i++) {
			vector<int> pos = startPos;
			int num = 0;
			while ((i + num)<s.size()) {
				switch (s[i + num])
				{
				case 'R':
					pos[1]++;
					break;
				case 'D':
					pos[0]++;
					break;
				case 'L':
					pos[1]--;
					break;
				case 'U':
					pos[0]--;
					break;
				}
				if (!checkValid(n, pos))num++;
				else break;
			}
			ans.push_back(num );
		}
		return ans;
	}
};
int main() {
	vector<int> a = { 0, 1 };
	Solution().executeInstructions(3,
		a,
		"RRDDLU");
}