#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (s.size() <= 1 || numRows == 1)return s;
		string ans;
		vector<vector<char>> stack;
		for (int i = 0; i < numRows; i++) {
			vector<char> cur;
			stack.push_back(cur);
		}
		for (int i = 0; i < s.size(); i++) {
			int num = i % (2 * numRows - 2);
			if (num < numRows) {
				stack[num].push_back(s[i]);
			}
			else {
				stack[2 * numRows - 2 - num].push_back(s[i]);
			}
		}
		for (auto cur_vector : stack) {
			for (char cur : cur_vector) {
				ans.push_back(cur);
			}
		}
		return ans;
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
//int stringToInteger(string input) {
//	return stoi(input);
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string s = stringToString(line);
//		getline(cin, line);
//		int numRows = stringToInteger(line);
//
//		string ret = Solution().convert(s, numRows);
//		string ret1 = Solution().convert1(s, numRows);
//		cout << ret << endl;
//		cout << ret1 << endl;
//	}
//	return 0;
//}