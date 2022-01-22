#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		vector<string> ans;
		int index = 0;
		while (index < s.size())
		{
			if ((s.size() - index) >= k) {
				ans.push_back(s.substr(index, k));
				index += k;
			}
			else
			{
				string temp = s.substr(index);
				while (temp.size()<k)
				{
					temp += fill;
				}
				ans.push_back(temp);
				break;
			}
		}
		return ans;
	}
};
int main() {
	Solution().divideString("abcdefghij", 3, 'x');
}