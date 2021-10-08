#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int min = 0;
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
		}
		return strs[0].substr(0,length);
	}
};