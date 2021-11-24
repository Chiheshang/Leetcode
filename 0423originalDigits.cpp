#include "Datastruct.h"
using namespace std;
class Solution {
public:
	string originalDigits(string s) {
		//zero one two three four five six seven eight nine
		//	z        w         u         x          g
		//"e", "g", "f", "i", "h", "o", "n", "s", "r", "u", "t", "w", "v", "x", "z"
		vector<int> num(15, 0);
		for (char cur : s) {
			if (cur == 'e')num[0]++;
			if (cur == 'g')num[1]++;
			if (cur == 'f')num[2]++;
			if (cur == 'i')num[3]++;
			if (cur == 'h')num[4]++;
			if (cur == 'o')num[5]++;
			if (cur == 'n')num[6]++;
			if (cur == 's')num[7]++;
			if (cur == 'r')num[8]++;
			if (cur == 'u')num[9]++;
			if (cur == 't')num[10]++;
			if (cur == 'w')num[11]++;
			if (cur == 'v')num[12]++;
			if (cur == 'x')num[13]++;
			if (cur == 'z')num[14]++;
		}
		vector<int> count(10, 0);
		count[0] = num[14];
		count[2] = num[11];
		count[4] = num[9];
		count[6] = num[13];
		count[8] = num[1];
		count[1] = num[5] - count[4] - count[2] - count[0];
		count[3] = num[8] - count[0] - count[4];
		count[5] = num[2] - count[4];
		count[7] = num[7] - count[6];
		count[9] = num[3] - count[5] - count[6] - count[8];
		string ans = "";
		for (int i = 0; i < count.size(); i++) {
			for (int j = 0; j < count[i]; j++) {
				ans.append(to_string(i));
			}
		}
		return ans;
	}
};
