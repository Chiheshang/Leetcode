#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 1) {
			return s;
		}
		else if (s.size() == 2) {
			return s[0] == s[1] ? s : s.substr(0, 1);
		}
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n));
		int maxlen = 0;
		int begin = 0;
		int end = 0;

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for (int j = 1; j < n; j++) {//需要參考左下角，一列一列來
			for (int L = 1; L <= j + 1; L++) {
				int i = j - L + 1;
				if (L == 1) {
					dp[i][j] = true;
				}
				else if (L == 2) {
					dp[i][j] = s[i] == s[j];
				}
				/*if (i + 1 > j) {
					break;
				}*/
				else {
					dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];//状态转移方程
				}

				if (dp[i][j] && maxlen < j - i + 1) {
					maxlen = j - i + 1;
					begin = i;
					end = j;
				}
			}
		}
		return s.substr(begin, maxlen);
	}
};
//string stringToString(string input) {
//	string result;
//	for (int i = 1; i < input.length() - 1; i++) {
//		char currentChar = input[i];
//		if (input[i] == '\\') {
//			char nextChar = input[i + 1];
//			switch (nextChar) {
//			case '\"': result.push_back('\"'); break;
//			case '/': result.push_back('/'); break;
//			case '\\': result.push_back('\\'); break;
//			case 'b': result.push_back('\b'); break;
//			case 'f': result.push_back('\f'); break;
//			case 'r': result.push_back('\r'); break;
//			case 'n': result.push_back('\n'); break;
//			case 't': result.push_back('\t'); break;
//			default: break;
//			}
//			i++;
//		}
//		else {
//			result.push_back(currentChar);
//		}
//	}
//	return result;
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string s = stringToString(line);
//
//		string ret = Solution().longestPalindrome(s);
//
//		string out = (ret);
//		cout << out << endl;
//	}
//	return 0;
//}