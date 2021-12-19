#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		string ans = "";
		int index = 0;
		ans += s.substr(0, spaces[0]);
		for (int i = 1; i < spaces.size(); i++) {
			ans = ans + s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]) + " ";
		}
		ans += s.substr(spaces[spaces.size() - 1]);
		return ans;
	}
};