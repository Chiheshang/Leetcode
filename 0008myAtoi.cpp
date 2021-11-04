#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int myAtoi(string s) {
		long ans = 0;
		for (auto it = s.begin(); it != s.end(); ) {
			if (*it == ' ') {
				s.erase(it);
			}
			else {
				break;
			}
		}
		bool positive = true;
		if (s[0] == '-' || s[0] == '+') {
			if (s[0] == '-')positive = false;
			s.erase(0, 1);
		}
		for (char cur : s) {
			if (!isdigit(cur))break;
			ans *= 10;
			ans += cur - '0';
			if (positive) {
				if (ans > INT32_MAX) {
					ans = INT32_MAX;
					break;
				}
			}
			else {
				if (ans > 2147483648) {
					ans = 2147483648;
					break;
				}
			}
		}
		return positive ? ans : ans * -1;
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
//		int ret = Solution().myAtoi(s);
//
//		string out = to_string(ret);
//		cout << out << endl;
//	}
//	return 0;
//}