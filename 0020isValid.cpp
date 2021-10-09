#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> m_stack;
		for (char cur : s) {
			switch (cur)
			{
			case'(': {
				m_stack.push(cur);
				break;
			}
			case')': {
				if (m_stack.empty()) {
					return false;
				}
				else if (m_stack.top() != '(') {
					return false;
				}
				else {
					m_stack.pop();
				}
				break;
			}
			case'{': {
				m_stack.push(cur);
				break;
			}
			case'}': {
				if (m_stack.empty()) {
					return false;
				}
				else if (m_stack.top() != '{') {
					return false;
				}
				else {
					m_stack.pop();
				}
				break;
			}
			case'[': {
				m_stack.push(cur);
				break;
			}
			case']': {
				if (m_stack.empty()) {
					return false;
				}
				else if (m_stack.top() != '[') {
					return false;
				}
				else {
					m_stack.pop();
				}
				break;
			}
			default:
				break;
			}
		}
		if (m_stack.empty()) {
			return true;
		}
		else {
			return false;
		}
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
//string boolToString(bool input) {
//	return input ? "True" : "False";
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string s = stringToString(line);
//
//		bool ret = Solution().isValid(s);
//
//		string out = boolToString(ret);
//		cout << out << endl;
//	}
//	return 0;
//}