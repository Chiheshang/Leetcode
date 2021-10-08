#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1)return strs[0];
		int min = INT32_MAX;
		for (string cur : strs) {
			min = std::min(min, (int)cur.length());
		}
		int length = 0;
		for (int j = 0; j < min; j++) {
			bool flag = true;
			for (int i = 0; i < strs.size(); i++) {
				flag = strs[i][j] == strs[0][j];
				if (!flag)
					break;
			}
			if (!flag) {
				length = j;
				break;
			}
			else {
				length = j + 1;
			}
		}
		return strs[0].substr(0, length);
	}
};
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		vector<string> strings = { "flower","flower","flower","flower" };
//		cout << Solution().longestCommonPrefix(strings) << endl;
//	}
//	return 0;
//}