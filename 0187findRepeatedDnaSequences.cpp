#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		if (s.size() < 10)return ans;
		map<string, int> map;
		for (int i = 0; i <= s.size() - 10; i++) {
			string cur = s.substr(i, 10);
			if (++map[cur] == 2) {
				ans.push_back(cur);
			}
		}
		return ans;
	}

};
