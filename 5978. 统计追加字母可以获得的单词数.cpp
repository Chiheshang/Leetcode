#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		unordered_map<string, int> index;
		for (string cur : startWords) {
			sort(cur.begin(), cur.end());
			index[cur]++;
		}
		int ans=0;
		for (string cur : targetWords) {
			sort(cur.begin(), cur.end());
			bool find = false;
			for (int i = 0; i < cur.size(); i++) {
				string temp = cur.substr(0, i - 0) + cur.substr(i + 1);
				if (index[temp]) {
					find = true;
					break;
				}
			}
			if (find)ans++;
		}
		return ans;
	}
};