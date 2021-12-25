#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		long long curtime = getCurrentTimeMillis();
		string ans = "";
		int index = 0;
		for (char cur : s.substr(0, spaces[0])) {
			ans.push_back(cur);
		}
		for (int i = 1; i < spaces.size(); i++) {
			for (char cur : s.substr(spaces[i - 1], spaces[i] - spaces[i - 1])) {
				ans.push_back(cur);
			}
			ans.push_back(' ');
		}
		for (char cur : s.substr(spaces[spaces.size() - 1])) {
			ans.push_back(cur);
		}
		cout<<getCurrentTimeMillis()-curtime;
		return ans;
	}
};
int main() {
	string s="";
	Solution().addSpaces();
}