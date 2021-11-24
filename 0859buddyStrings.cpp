#include "Datastruct.h"
using namespace std;
class Solution {
public:
	bool buddyStrings(string s, string goal) {
		if (s.size() != goal.size() || s.size() < 2)return false;
		int num = 0;
		vector<int> letter(26, 0);
		bool flag = false;
		int index1 = 0, index2 = 0;
		for (int i = 0; i < goal.size(); i++) {
			if (letter[goal[i] - 'a'])flag = true;
			letter[goal[i] - 'a']++;
			if (s[i] != goal[i]) {
				num++;
				if (num == 1)index1 = i;
				if (num == 2)index2 = i;
			}
		}
		if (num == 2 &&
			s[index1] == goal[index2] &&
			s[index2] == goal[index1])return true;
		if (num == 0 && flag)return true;
		return false;
	}
};