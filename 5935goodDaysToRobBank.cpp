#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		vector<int> ans;
		if (security.size() < time * 2)return ans;
		if (time == 0) {
			vector<int> c(security.size());
			for (int i = 0; i < c.size(); i++) {
				c[i] = i;
			}
			return c;
		}
		bool last = false;
		for (int i = time; i < security.size() - time; i++) {
			if (last) {
				bool tag = true;
				if (security[i] > security[i - 1])tag = false;
				if (security[i + time - 1] > security[i + time])tag = false;
				if (tag) {
					last = true;
					ans.push_back(i);
				}
				else {
					last = false;
				}
				continue;
			}
			bool tag = false;
			for (int j = i - 1; j > i - time - 1; j--) {
				if (security[j] < security[j + 1]) {
					tag = true;
					break;
				}
			}
			if (tag) {
				last = false;
				continue;
			}
			for (int j = i + 1; j < i + time + 1; j++) {
				if (security[j] < security[j - 1]) {
					tag = true;
					break;
				}
			}
			if (tag) {
				last = false;
				continue;
			}
			ans.push_back(i);
			last = true;
		}
		return ans;
	}
};
int main() {
	vector<int> a = { 1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8
	};
	Solution().goodDaysToRobBank(a, 2);
}